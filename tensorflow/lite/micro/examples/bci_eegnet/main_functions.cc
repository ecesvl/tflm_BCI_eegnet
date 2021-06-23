#include "tensorflow/lite/micro/examples/bci_eegnet/main_functions.h"

#include "tensorflow/lite/micro/examples/bci_eegnet/eegnet_model/model.h"
#include "tensorflow/lite/micro/examples/bci_eegnet/eegnet_model/model_settings.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/micro/system_setup.h"
#include "tensorflow/lite/schema/schema_generated.h