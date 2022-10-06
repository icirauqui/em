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
    deps = [
        ":arrayfire",
        ":eigen",
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



#################
## cmake builds #
#################
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

# arrayfire
cmake(
    name = "arrayfire",
    cache_entries = {
        "CMAKE_BUILD_TYPE": "Release",
        "AF_BUILD_CPU": "ON",
        "AF_BUILD_CUDA": "OFF",
        "AF_BUILD_OPENCL": "OFF",
        "AF_BUILD_EXAMPLES": "OFF",
        "AF_WITH_IMAGEIO": "OFF",
        "BUILD_TESTING": "OFF",
        "AF_BUILD_DOCS": "OFF",
    },
    build_args = [
        "--verbose",
        "--",
        "-j `nproc`",
    ],
    lib_source = "@arrayfire//:all_srcs",
    out_shared_libs = [
      "libaf.so", 
      "libaf.so.3", 
      "libafcpu.so",
      "libafcpu.so.3",
    ],
    visibility = ["//visibility:public"],
)

# eigen
cmake(
    name = "eigen",
    cache_entries = {
        "CMAKE_C_FLAGS": "-fPIC",
    },
    lib_source = "@eigen//:all_srcs",
    out_headers_only = True,
    includes = ["eigen3/",],
    install = True,
)