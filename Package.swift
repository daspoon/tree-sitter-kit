// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "TreeSitterKit",
    products: [
        .library(name: "TreeSitterKit", targets: ["TreeSitterKit"]),
        .plugin(name: "TreeSitterGen", targets: ["TreeSitterGen"]),
    ],
    dependencies: [
        .package(url: "https://github.com/tree-sitter/tree-sitter", from: "0.21.0"),
    ],
    targets: [
        // The exported library providing a Swift interface for tree-sitter.
        .target(name: "TreeSitterKit",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
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
            dependencies: ["TreeSitterKit", "FunLang"],
            path: "Tests"
        ),
    ]
)
