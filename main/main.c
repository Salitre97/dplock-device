#include <stdio.h>
#include "freeertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void) {

/*
Task1 for button : state machine 
psuedo code:
if button closed then door is closed
if open then door is open 


Task2 for Accelerometer : will monitor voltage feed back (ADC) 
Increase in voltage means acceleration increase
low voltage (mV) : low acceleration (relative)
high voltage (mV) : high acceleration (relative)


Task3 Photodiod : will monitor voltage feedback (ADC)
the photodiode will measure light sensitivity


Task4 DC motor : PWM signal will be generated to control servo motor
signal recieved via ble from smartphone will activate servo motor
(open / close)

Task5 transmit data : peripheral data will be stored on nonvolatile memory (NVM)[SRAM]
once transmitted to smarpthone, data is erased from device

Task6 RTC: will record time stamps of times container was opened.
Will also be used to track time duration of transit from point of origin to destination.

*/
}
