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
        // Some example language targets for testing purposes...
        .target(name: "ArithLang",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
            ],
            path: "Sources/Xamples/ArithLang",
            cSettings: [.headerSearchPath("src")],
            swiftSettings: [.interoperabilityMode(.C)]
        ),
        .target(name: "TypedLang",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
            ],
            path: "Sources/Xamples/TypedLang",
            cSettings: [.headerSearchPath("src")],
            swiftSettings: [.interoperabilityMode(.C)]
        ),
        // Test targets for the sample language targets...
        .testTarget(name: "ArithLangTests",
            dependencies: [
                "TSKit",
                .product(name: "SwiftSyntaxMacrosTestSupport", package: "swift-syntax"),
                "ArithLang",
            ],
            path: "Tests/ArithLang"
        ),
        .testTarget(name: "TypedLangTests",
            dependencies: [
                "TSKit",
                .product(name: "SwiftSyntaxMacrosTestSupport", package: "swift-syntax"),
                "TypedLang",
            ],
            path: "Tests/TypedLang"
        ),
    ]
)
