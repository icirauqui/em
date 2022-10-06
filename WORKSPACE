workspace(name = "main")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")



########################################
# source dependencies built with CMake #
########################################

_ALL_CONTENT = """\
filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"],
)
"""

# Setup rules_foreign_cc (CMake integration)
http_archive(
    name = "rules_foreign_cc",
    strip_prefix = "rules_foreign_cc-8d540605805fb69e24c6bf5dc885b0403d74746a", # 0.9.0
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/8d540605805fb69e24c6bf5dc885b0403d74746a.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()


# arrayfire
http_archive(
      name = "arrayfire",
      build_file_content = _ALL_CONTENT,
      sha256 = "2d01b35adade2433078f57e2233844679aabfdb06a41e6992a6b27c65302d3fe",
      strip_prefix = "arrayfire-full-3.8.2",
      urls = ["https://github.com/arrayfire/arrayfire/releases/download/v3.8.2/arrayfire-full-3.8.2.tar.bz2"],
)



# Eigen
http_archive(
  name="eigen",
  build_file_content = _ALL_CONTENT,
  strip_prefix = "eigen-3.4",
  urls=["https://gitlab.com/libeigen/eigen/-/archive/3.4/eigen-3.4.tar.bz2"],
  sha256 = "a6f7aaa7b19c289dfeb33281e1954f19bf2ba1c6cae2c182354d820f535abef8",
)