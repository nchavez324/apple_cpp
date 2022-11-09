package(default_visibility = ["//test_app:__subpackages__"])

cc_library(
    name = "AppKit",
    hdrs = glob(["AppKit/*.hpp"]),
    includes = [
        "./",
    ],
    deps = [
        ":Foundation",
    ],
)

cc_library(
    name = "Foundation",
    hdrs = glob(["Foundation/*.hpp"]),
    includes = [
        "./",
    ],
)

cc_library(
    name = "CoreGraphics",
    hdrs = glob(["CoreGraphics/*.hpp"]),
    includes = [
        "./",
    ],
    deps = [
        ":Foundation",
    ],
)

cc_library(
    name = "Metal",
    hdrs = glob(["Metal/*.hpp"]),
    includes = [
        "./",
    ],
    deps = [
        ":Foundation",
    ],
)

cc_library(
    name = "OpenGLES",
    hdrs = glob(["OpenGLES/*.hpp"]),
    includes = [
        "./",
    ],
    deps = [
        ":Foundation",
    ],
)

cc_library(
    name = "QuartzCore_OpenGLES",
    hdrs = glob(
        ["QuartzCore/*.hpp"],
        exclude = [
            "QuartzCore/CAMetalDrawable.hpp",
            "QuartzCore/CAMetalLayer.hpp",
        ],
    ),
    defines = ["QUARTZ_CORE_OPEN_GLES=1"],
    includes = [
        "./",
    ],
    deps = [
        ":CoreGraphics",
        ":Foundation",
        ":OpenGLES",
    ],
)

cc_library(
    name = "QuartzCore_Metal",
    hdrs = glob(
        ["QuartzCore/*.hpp"],
        exclude = ["QuartzCore/CAEAGLLayer.hpp"],
    ),
    defines = ["QUARTZ_CORE_METAL=1"],
    includes = [
        "./",
    ],
    deps = [
        ":CoreGraphics",
        ":Foundation",
        ":Metal",
    ],
)
