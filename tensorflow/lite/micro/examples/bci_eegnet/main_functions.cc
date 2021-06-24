#include "tensorflow/lite/micro/examples/bci_eegnet/main_functions.h"

#include "tensorflow/lite/micro/examples/bci_eegnet/model.h"
#include "tensorflow/lite/micro/examples/bci_eegnet/model_settings.h"
#include "tensorflow/lite/micro/examples/bci_eegnet/classification_responder.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/micro/system_setup.h"
#include "tensorflow/lite/schema/schema_generated.h"

namespace{
	tflite::ErrorReporter* error_reporter = nullptr;
	const tflite::Model* model = nullptr;
	tflite::MicroInterpreter* interpreter = nullptr;
	TfLiteTensor* model_input = nullptr;

    // Create an area of memory to use for input, output, and intermediate arrays.
    // The size of this will depend on the model you're using, and may need to be
    // determined by experimentation.
    constexpr int kTensorArenaSize = 100 * 1024;
    uint8_t tensor_arena[kTensorArenaSize];
    int8_t* model_input_buffer = nullptr;
}

// The name of this function is important for Arduino compatibility
void setup() {
    tflite::InitializeTarget();

    // Set up logging. Google style is to avoid globals or statics because of
    // lifetime uncertainty, but since this has a trivial destructor it's okay.
    // NOLINTNEXTLINE(runtime-global-variables)
    static tflite::MicroErrorReporter micro_error_reporter;
    error_reporter = &micro_error_reporter;

    // Map the model into a usable data structure. This doesn't involve any
    // copying or parsing, it's a very lightweight operation.
    model = tflite::GetModel(g_model);
    if (model->version() != TFLITE_SCHEMA_VERSION) {
        TF_LITE_REPORT_ERROR(error_reporter,
                             "Model provided is schema version %d not equal "
                             "to supported version %d.",
                             model->version(), TFLITE_SCHEMA_VERSION);
        return;
    }

    // Pull in only the operation implementations we need.
    // This relies on a complete list of all the ops needed by this graph.
    // An easier approach is to just use the AllOpsResolver, but this will
    // incur some penalty in code space for op implementations that are not
    // needed by this graph.
    //
    // tflite::AllOpsResolver resolver;
    // NOLINTNEXTLINE(runtime-global-variables)
    static tflite::MicroMutableOpResolver<10> micro_op_resolver(error_reporter);
    if (micro_op_resolver.AddPad() != kTfLiteOk) {
        return;
    }
    if (micro_op_resolver.AddPadV2() != kTfLiteOk) {
        return;
    }
    if (micro_op_resolver.AddSoftmax() != kTfLiteOk) {
        return;
    }
    if (micro_op_resolver.AddReshape() != kTfLiteOk) {
        return;
    }
    if (micro_op_resolver.AddConv2D() != kTfLiteOk) {
        return;
    }
    if (micro_op_resolver.AddDepthwiseConv2D() != kTfLiteOk) {
        return;
    }
    if (micro_op_resolver.AddTranspose() != kTfLiteOk) {
        return;
    }
    if (micro_op_resolver.AddAveragePool2D() != kTfLiteOk) {
        return;
    }
    if (micro_op_resolver.AddFullyConnected() != kTfLiteOk) {
        return;
    }
    if (micro_op_resolver.AddElu() != kTfLiteOk){
        return;
    }

    // Build an interpreter to run the model with.
    static tflite::MicroInterpreter static_interpreter(
            model, micro_op_resolver, tensor_arena, kTensorArenaSize, error_reporter);
    interpreter = &static_interpreter;

    // Allocate memory from the tensor_arena for the model's tensors.
    TfLiteStatus allocate_status = interpreter->AllocateTensors();
    if (allocate_status != kTfLiteOk) {
        TF_LITE_REPORT_ERROR(error_reporter, "AllocateTensors() failed");
        return;
    }

    // Get information about the memory area to use for the model's input.
    model_input = interpreter->input(0);

    TF_LITE_REPORT_ERROR(error_reporter, "Input dimensions for this model is: %d", model_input->dims->size);
    TF_LITE_REPORT_ERROR(error_reporter, "Input dimensions for this model is: %d", model_input->dims->size);
    TF_LITE_REPORT_ERROR(error_reporter, "Input dimensions for this model is: %d", model_input->dims->size);
}

void loop(){
    RespondToClassification(error_reporter);
}
