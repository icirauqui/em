load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")



cc_library (
    name = "data_handler",
    hdrs = [
        "cc/data_handler.h",
    ],
    srcs = [
        "cc/data_handler.cpp",
    ],
    visibility = ["//visibility:public"],
)


cc_library(
    name = "em",
    hdrs = [
        "cc/em.h",
    ],
    srcs = [
        "cc/em.cpp",
    ],
    visibility = ["//visibility:public"],
)




cc_binary(
    name = "main",
    srcs = [
        "cc/main.cpp",
    ],
    deps = [
        ":data_handler",
        ":em",
    ],
    visibility = ["//visibility:public"],
)