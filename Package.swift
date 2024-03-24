// swift-tools-version: 5.9

import PackageDescription
import CompilerPluginSupport

let package = Package(
    name: "TreeSitterKit",
    platforms: [.macOS(.v10_15), .iOS(.v13), .tvOS(.v13), .watchOS(.v6), .macCatalyst(.v13)],
    products: [
        .library(name: "TreeSitterKit", targets: ["TreeSitterKit"]),
        .plugin(name: "TreeSitterGen", targets: ["TreeSitterGen"]),
    ],
    dependencies: [
        .package(url: "https://github.com/tree-sitter/tree-sitter", from: "0.21.0"),
        .package(url: "https://github.com/apple/swift-syntax.git", from: "509.0.0"),
    ],
    targets: [
        // The exported library providing a Swift interface for tree-sitter.
        .target(name: "TreeSitterKit",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
              "Macros",
            ]
        ),
        // The definitions of macros exported by the TreeSitterKit.
        .macro(name: "Macros",
            dependencies: [
                .product(name: "SwiftSyntaxMacros", package: "swift-syntax"),
                .product(name: "SwiftCompilerPlugin", package: "swift-syntax")
            ]
        ),
        // A command plugin to generate parsers for 'language' targets.
        .plugin(name: "TreeSitterGen",
            capability: .command(
              intent: .custom(verb: "generate-parser", description: "Invoke tree-sitter to generate parser source files from grammar.js"),
              permissions: [
                .writeToPackageDirectory(reason: "To generate parser source files"),
              ])
        ),
        // An language target for testing purposes.
        .target(name: "FunLang",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
            ],
            cSettings: [.headerSearchPath("src")],
            swiftSettings: [.interoperabilityMode(.C)]
        ),
        // Unit tests
        .testTarget(name: "TreeSitterKitTests",
            dependencies: [
                "TreeSitterKit",
                .product(name: "SwiftSyntaxMacrosTestSupport", package: "swift-syntax"),
                "FunLang",
            ],
            path: "Tests"
        ),
    ]
)
