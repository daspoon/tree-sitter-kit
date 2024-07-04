// swift-tools-version: 5.9

import PackageDescription
import CompilerPluginSupport

let package = Package(
    name: "TreeSitterKit",
    platforms: [.macOS(.v10_15), .iOS(.v13), .macCatalyst(.v13)],
    products: [
        .library(name: "TSKit", targets: ["TSKit"]),
    ],
    dependencies: [
        .package(url: "https://github.com/daspoon/tree-sitter", from: "0.1.3"),
        .package(url: "https://github.com/apple/swift-syntax.git", from: "509.0.0"),
    ],
    targets: [
        // The library of code shared by TSKit and TSMacros
        .target(name: "TSCommon",
          dependencies: [
              "TreeSitterCLI",
          ]
        ),
        // The exported library providing a Swift interface for tree-sitter.
        .target(name: "TSKit",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
              "TSCommon",
              "TSLanguage",
              "TSMacros",
            ]
        ),
        // The C library required to create a TSLanguage struct
        .target(name: "TSLanguage",
            dependencies: [
                .product(name: "TreeSitter", package: "tree-sitter"),
            ]
        ),
        // The definitions of macros exported by TSKit.
        .macro(name: "TSMacros",
            dependencies: [
                .product(name: "SwiftSyntaxMacros", package: "swift-syntax"),
                .product(name: "SwiftCompilerPlugin", package: "swift-syntax"),
                "TSCommon",
            ]
        ),
        // Binary tree-sitter CLI library
        .binaryTarget(name: "TreeSitterCLI",
          path: "XCFrameworks/TreeSitterCLI.xcframework"
        ),
        // Tests for general TSKit functionality
        .testTarget(name: "TSKitTests",
            dependencies: [
                "TSKit",
            ],
            path: "Tests/TSKit"
        ),
        // Example languages for testing purposes...
        .testTarget(name: "ExprLangTests",
            dependencies: [
                "TSKit",
                "TSLanguage",
                .product(name: "SwiftSyntaxMacrosTestSupport", package: "swift-syntax"),
            ],
            path: "Tests/ExprLang"
        ),
        .testTarget(name: "TypedLangTests",
            dependencies: [
                "TSKit",
                "TSLanguage",
                .product(name: "SwiftSyntaxMacrosTestSupport", package: "swift-syntax"),
            ],
            path: "Tests/TypedLang"
        ),
    ]
)
