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
        //.package(url: "https://github.com/tree-sitter/tree-sitter", from: "0.21.0"),
        .package(path: "../tree-sitter"),
        .package(url: "https://github.com/apple/swift-syntax.git", from: "509.0.0"),
    ],
    targets: [
        // The exported library providing a Swift interface for tree-sitter.
        .target(name: "TSKit",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
              "TreeSitterCLI",
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
                "TreeSitterCLI",
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
        // Some examples which pair language and parser targets for testing purposes...
        .target(name: "ExprLang",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
            ],
            path: "Sources/Examples/ExprLang",
            cSettings: [.headerSearchPath("src")],
            swiftSettings: [.interoperabilityMode(.C)]
        ),
        .testTarget(name: "ExprLangTests",
            dependencies: [
                "TSKit",
                "TSLanguage",
                .product(name: "SwiftSyntaxMacrosTestSupport", package: "swift-syntax"),
                "ExprLang",
            ],
            path: "Tests/ExprLang"
        ),
        .target(name: "TypedLang",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
            ],
            path: "Sources/Examples/TypedLang",
            cSettings: [.headerSearchPath("src")],
            swiftSettings: [.interoperabilityMode(.C)]
        ),
        .testTarget(name: "TypedLangTests",
            dependencies: [
                "TSKit",
                "TSLanguage",
                .product(name: "SwiftSyntaxMacrosTestSupport", package: "swift-syntax"),
                "TypedLang",
            ],
            path: "Tests/TypedLang"
        ),
    ]
)
