// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "TreeSitting",
    dependencies: [
      //.package(url: "https://github.com/viktorstrate/swift-tree-sitter", from: "0.1.1"),
      .package(path: "/Users/dave/Developer/External/swift-tree-sitter"),
    ],
    targets: [
        .executableTarget(name: "TreeSitting",
            dependencies: [
                .product(name: "SwiftTreeSitter", package: "swift-tree-sitter"),
            ]
        ),
    ]
)
