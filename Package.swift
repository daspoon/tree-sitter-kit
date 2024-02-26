// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "TreeSitting",
    products: [
      .library(name: "TSKit", targets: ["TSKit"]),
    ],
    dependencies: [
      .package(path: "/Users/dave/Developer/External/tree-sitter"),
    ],
    targets: [
        // Minimal Swift bindings for TreeSitter.
        .target(name: "TSKit",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
            ]
        ),
        // Generated parser for a custom language.
        .target(name: "FunLangParser",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
            ],
            swiftSettings: [.interoperabilityMode(.C)]
        ),
        // Tests
        .testTarget(name: "TSKitTests",
            dependencies: ["TSKit", "FunLangParser"],
            path: "Tests"
        ),
    ]
)
