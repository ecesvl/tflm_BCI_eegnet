EXAMPLE_NAME:=bci_eegnet

BCI_EEGNET_SRCS := \
tensorflow/lite/micro/examples/bci_eegnet/main.cc \
tensorflow/lite/micro/examples/bci_eegnet/main_functions.cc \
tensorflow/lite/micro/examples/bci_eegnet/model.cc \
tensorflow/lite/micro/examples/bci_eegnet/classification_responder.cc\
tensorflow/lite/micro/examples/bci_eegnet/model_settings.cc

BCI_EEGNET_HDRS := \
tensorflow/lite/micro/examples/bci_eegnet/model.h \
tensorflow/lite/micro/examples/bci_eegnet/main_functions.h\
tensorflow/lite/micro/examples/bci_eegnet/classification_responder.h\
tensorflow/lite/micro/examples/bci_eegnet/model_settings.h


#Find any platform - specific rules for this example.
include $(wildcard tensorflow/lite/micro/examples/bci_eegnet/*/Makefile.inc)

# Builds a standalone binary.
$(eval $(call microlite_test,$(EXAMPLE_NAME),\
$(BCI_EEGNET_SRCS),$(BCI_EEGNET_HDRS)))

list_$(EXAMPLE_NAME)_example_sources:
	@echo $(BCI_EEGNET_SRCS)

list_$(EXAMPLE_NAME)_example_headers:
	@echo $(BCI_EEGNET_HDRS)