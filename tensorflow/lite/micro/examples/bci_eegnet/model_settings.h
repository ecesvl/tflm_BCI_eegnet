#ifndef TENSORFLOW_LITE_MICRO_EXAMPLES_MICRO_SPEECH_BCI_EEGNET_MODEL_SETTINGS_H_
#define TENSORFLOW_LITE_MICRO_EXAMPLES_MICRO_SPEECH_BCI_EEGNET_MODEL_SETTINGS_H_

// Keeping these as constant expressions allow us to allocate fixed-sized arrays
// on the stack for our working memory.

// The following values are derived from values used during model training.
// If you change the way you preprocess the input, update all these constants.
constexpr int kNumberEEGChannels = 64;
constexpr int kBatchSize = 1;
constexpr int kNumberTimeSamples = 480;
constexpr int kclass = 2; 

// Variables for the model's output categories.
constexpr int kLeftIndex = 0;
constexpr int kRightIndex = 1;
// If you modify the output categories, you need to update the following values.
constexpr int kCategoryCount = kclass;
extern const char* kCategoryLabels[kCategoryCount];

#endif  // TENSORFLOW_LITE_MICRO_EXAMPLES_MICRO_SPEECH_BCI_EEGNET_MODEL_SETTINGS_H_