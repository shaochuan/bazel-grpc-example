load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_compile")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("@com_github_grpc_grpc//bazel:python_rules.bzl", "py_grpc_library", "py_proto_library")

proto_library(
    name = "calculator_proto",
    srcs = [
        "calculator.proto",
    ],
    visibility = ["//visibility:public"],
)

cc_proto_library(
    name = "calculator_cc_proto",
    deps = [":calculator_proto"],
)

cc_grpc_library(
    name = "calculator_cc_grpc",
    srcs = [":calculator_proto"],
    grpc_only = True,
    deps = [":calculator_cc_proto"],
)

cc_binary(
    name = "calculator_server",
    srcs = ["calculator_server.cc"],
    deps = [
        ":calculator_cc_grpc",
        # http_archive made this label available for binding
        "@com_github_grpc_grpc//:grpc++",
    ],
)

# Python gRPC client

py_proto_library(
    name = "calculator_py_proto",
    deps = [":calculator_proto"],
)

py_grpc_library(
    name = "calculator_py_grpc",
    srcs = [":calculator_proto"],
    deps = [":calculator_py_proto"],
)

py_binary(
    name = "calculator_client",
    srcs = ["calculator_client.py"],
    deps = [":calculator_py_grpc"],
)