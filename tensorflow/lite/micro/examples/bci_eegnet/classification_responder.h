
//
// Created by ece on 6/23/21.
//

#ifndef BCI_EEGNET_CLASSIFICATION_RESPONDER_H
#define BCI_EEGNET_CLASSIFICATION_RESPONDER_H

#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"

// Called every time the results of an audio recognition run are available. The
// human-readable name of any recognized command is in the `found_command`
// argument, `score` has the numerical confidence, and `is_new_command` is set
// if the previous command was different to this one.
void RespondToClassification(tflite::ErrorReporter* error_reporter);



#endif //BCI_EEGNET_CLASSIFICATION_RESPONDER_H
