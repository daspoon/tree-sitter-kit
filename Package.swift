// swift-tools-version: 5.9

import PackageDescription
import CompilerPluginSupport

let package = Package(
    name: "TreeSitterKit",
    platforms: [.macOS(.v10_15), .iOS(.v13), .macCatalyst(.v13)],
    products: [
        .library(name: "TSKit", targets: ["TSKit"]),
        .plugin(name: "TSGen", targets: ["TSGen"]),
    ],
    dependencies: [
        .package(url: "https://github.com/tree-sitter/tree-sitter", from: "0.21.0"),
        .package(url: "https://github.com/apple/swift-syntax.git", from: "509.0.0"),
    ],
    targets: [
        // The exported library providing a Swift interface for tree-sitter.
        .target(name: "TSKit",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
              "TSMacros",
            ]
        ),
        // The definitions of macros exported by TSKit.
        .macro(name: "TSMacros",
            dependencies: [
                .product(name: "SwiftSyntaxMacros", package: "swift-syntax"),
                .product(name: "SwiftCompilerPlugin", package: "swift-syntax")
            ]
        ),
        // A command plugin to generate parsers for 'language' targets.
        .plugin(name: "TSGen",
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
            path: "Sources/Xamples/FunLang",
            cSettings: [.headerSearchPath("src")],
            swiftSettings: [.interoperabilityMode(.C)]
        ),
        // Unit tests
        .testTarget(name: "FunLangTests",
            dependencies: [
                "TSKit",
                .product(name: "SwiftSyntaxMacrosTestSupport", package: "swift-syntax"),
                "FunLang",
            ],
            path: "Tests/FunLang"
        ),
    ]
)
