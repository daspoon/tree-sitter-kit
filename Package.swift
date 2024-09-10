// swift-tools-version: 5.9

import PackageDescription
import CompilerPluginSupport

let package = Package(
    name: "TreeSitterKit",
    platforms: [.macOS(.v13), .iOS(.v16), .macCatalyst(.v16)],
    products: [
        .library(name: "TSKit", targets: ["TSKit"]),
        .executable(name: "TSPlayground", targets: ["TSPlayground"]),
    ],
    dependencies: [
        .package(url: "https://github.com/daspoon/tree-sitter", from: "0.1.7"),
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
              "TSMacros",
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
        .executableTarget(name: "TSPlayground", dependencies: [
          "TSKit",
        ]),
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
                .product(name: "SwiftSyntaxMacrosTestSupport", package: "swift-syntax"),
            ],
            path: "Tests/ExprLang"
        ),
        .testTarget(name: "TypedLangTests",
            dependencies: [
                "TSKit",
                .product(name: "SwiftSyntaxMacrosTestSupport", package: "swift-syntax"),
            ],
            path: "Tests/TypedLang"
        ),
    ]
)
