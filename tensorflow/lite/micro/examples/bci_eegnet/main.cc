#include "tensorflow/lite/micro/examples/bci_eegnet/main_functions.h"

// This is the default main used on systems that have the standard C entry
// point. Other devices (for example FreeRTOS or ESP32) that have different
// requirements for entry code (like an app_main function) should specialize
// this main.cc file in a target-specific subfolder.
int main(int argc, char* argv[]) {
  setup();
  while (true) {
    loop();
  }
}