//
// Created by ece on 6/23/21.
//

#include "tensorflow/lite/micro/examples/bci_eegnet/classification_responder.h"

void RespondToClassification(tflite::ErrorReporter* error_reporter {
    if (is_new_command) {
        TF_LITE_REPORT_ERROR(error_reporter, "Test");
    }
}
