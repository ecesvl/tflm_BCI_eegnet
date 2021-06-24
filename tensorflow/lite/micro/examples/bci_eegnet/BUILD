# Description:
#   TensorFlow Lite microcontroller example.
package(
    default_visibility = ["//visibility:public"],
    features = ["-layering_check"],
    licenses = ["notice"],
)

cc_library(
    name = "model_settings",
    srcs = [
        "model_settings.cc",
    ],
    hdrs = [
        "model_settings.h",
    ],
)

cc_library(
    name = "model",
    srcs = [
        "model.cc",
    ],
    hdrs = [
        "model.h",
    ],
)

cc_library(
    name = "classification_responder",
    srcs = [
        "classification_responder.cc",
    ],
    hdrs = [
        "classification_responder.h",
    ],
    deps = [
        "//tensorflow/lite/c:common",
        "//tensorflow/lite/micro:micro_error_reporter",
    ],
)

cc_binary(
    name = "bci_eegnet",
    srcs = [
        "main.cc",
        "main_functions.cc",
        "main_functions.h",
    ],
    deps = [
        ":classification_responder",
        ":model",
        ":model_settings",
        "//tensorflow/lite/micro:micro_error_reporter",
        "//tensorflow/lite/micro:micro_framework",
        "//tensorflow/lite/micro:op_resolvers",
        "//tensorflow/lite/micro:system_setup",
    ],
)

