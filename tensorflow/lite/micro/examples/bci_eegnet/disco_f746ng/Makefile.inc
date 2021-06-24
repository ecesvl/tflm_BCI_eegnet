# Settings for the Discovery STM32F746NG board.
ifeq ($(TARGET), disco_f746ng)
  bci_eegnet_MBED_PROJECT_FILES += \
    BSP_DISCO_F746NG.lib \
    SDRAM_DISCO_F746NG.lib \
    LCD_DISCO_F746NG.lib
endif