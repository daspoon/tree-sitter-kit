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
        // The exported library providing a Swift interface for tree-sitter.
        .target(name: "TSKit",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
            ]
        ),
        // A command plugin to generate parsers for 'language' targets.
        .plugin(name: "GenParserCmd",
            capability: .command(
              intent: .custom(verb: "generate-parser", description: "Invoke tree-sitter to generate parser source files from grammar.js"),
              permissions: [
                .writeToPackageDirectory(reason: "To generate parser source files"),
              ])
        ),
        // An language target for testing purposes.
        .target(name: "FunLangParser",
            dependencies: [
              .product(name: "TreeSitter", package: "tree-sitter"),
            ],
            cSettings: [.headerSearchPath("src")],
            swiftSettings: [.interoperabilityMode(.C)]
        ),
        // Unit tests
        .testTarget(name: "TSKitTests",
            dependencies: ["TSKit", "FunLangParser"],
            path: "Tests"
        ),
    ]
)
