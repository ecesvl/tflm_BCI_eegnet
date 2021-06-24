#include "tensorflow/lite/micro/examples/bci_eegnet/classification_responder.h"

#include "LCD_DISCO_F746NG.h"

LCD_DISCO_F746NG lcd;
#define LCD_COLOR_WHITE 0xFFFFFFFF

// When a command is detected, write it to the display and log it to the
// serial port.
void RespondToClassification(tflite::ErrorReporter* error_reporter) {
    /*TODO: an output on LCD screen which shows the result of the classification
     * therefore also some additional parameters have to be passed on
     */

    //Right now jut something to output on LCD in endless loop
    lcd.Clear(LCD_COLOR_WHITE);
    lcd.DisplayStringAt(0, LINE(5), (uint8_t*)"Hello World:)", CENTER_MODE);

}