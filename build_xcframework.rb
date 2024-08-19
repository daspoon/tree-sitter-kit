#!/usr/bin/env ruby

=begin

Build TreeSitterCLI.xcframework for the installed rustc targets, minus those specified by --exclude options.

Options:
  -e, --exclude TERM        exclude targets whose name, architecture or platform matches the given term
  -i, --identity ID         code signing identity
  -n, --no-sign             don't codesign
  -t, --tree-sitter PATH    the location of the tree-sitter (fork) checkout

=end

require 'optparse'
require 'set'


working_dir = `echo $PWD`.strip

# rust comiler target

class Target
  attr_reader :name, :arch, :platform
  def initialize(name)
    @name = name
    elements = name.split("-", 3)
    @arch = elements[0]
    @platform = elements[2]
  end
  def match(term)
    @name == term || @arch == term || @platform.include?(term)
  end
end

# convenience

def exec(cmd)
  puts(cmd); `#{cmd}`
end

# Get the installed targets

targets = `rustup target list --installed`.lines.map{|line|line.strip}.filter{|name|name.include?("-apple-")}.map{|name|Target.new(name)}
if targets.empty?
  abort("no installed targets for rustc")
end

# Extract the command-line options

exclude = Set[]
tree_sitter_dir = ""
codesign = true
identity = ""

OptionParser.new do |parser|
  parser.banner = "Usage: build_xcframework [options]"
  parser.on('-e', '--exclude TERM') { |term|
    exclude.add(term)
  }
  parser.on('-i', '--identity ID') { |id|
    identity = id
  }
  parser.on('-n', '--no-sign') {
    codesign = false
  }
  parser.on('-t', '--tree-sitter PATH') { |path|
    if !File.directory?(path)
      abort("no such directory: #{path}")
    end
    tree_sitter_dir = path
  }
end.parse!

if !ARGV.empty?
  abort("invalid argument")
end

# Look for the tree-sitter checkout if unspecified

if tree_sitter_dir == ""
  ["..", "#{working_dir}/.build/checkouts"].each { |prefix|
    dir = "#{prefix}/tree-sitter"
    if File.directory?(dir)
      tree_sitter_dir = dir
      break
    end
  }
  if tree_sitter_dir == ""
    abort("can't infer location of tree-sitter checkout")
  end
end

# Partition the targets by platform, except those which match the filter options

targets_by_platform = Hash.new { |hash, platform| set = Set[]; hash[platform] = set; set }
targets.each { |target|
  matches = exclude.filter { |term| target.match(term) }
  if matches.empty?
    targets_by_platform[target.platform].add(target)
  end
}
if targets_by_platform.empty?
  abort("no build targets")
end

# Compile targets and build a fat library for each platform

manifest_path = "#{tree_sitter_dir}/cli/Cargo.toml"
target_dir = "#{working_dir}/.build/cargo"
lib_name = "libtree_sitter_cli.a"

targets_by_platform.each { |platform, targets|
  targets.each { |target|
    exec("cargo rustc --release --manifest-path #{manifest_path} --lib --crate-type=staticlib --target-dir #{target_dir} --target #{target.name}")
  }
  fat_dir = "#{target_dir}/#{platform}"
  library_paths = targets.map{|target| "#{target_dir}/#{target.name}/release/#{lib_name}"}
  if !File.directory?(fat_dir)
    exec("mkdir #{fat_dir}")
  end
  exec("lipo #{library_paths.join(" ")} -create -output #{fat_dir}/#{lib_name}")
}

# Bundle the fat libraries as an xcframework

framework_path = "#{working_dir}/XCFrameworks/TreeSitterCLI.xcframework"

if File.directory?(framework_path)
  exec("rm -rf #{framework_path}")
end

library_args = targets_by_platform.keys.map { |platform| "-library #{target_dir}/#{platform}/#{lib_name} -headers #{tree_sitter_dir}/cli/include" }.join(" ")
exec("xcodebuild -create-xcframework #{library_args} -output #{framework_path}")

# Sign the xcframework

if codesign
  if identity == ""
    identity = "\"Apple Development:\""
  end
  exec("codesign --timestamp -s #{identity} #{framework_path}")
end
