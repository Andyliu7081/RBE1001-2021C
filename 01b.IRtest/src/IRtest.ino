/*
 * Line following with speed control. Pauses at an intersection and waits for a turn command.
 * Turns as a state.
 */ 

#include <Arduino.h>
#include <RBE1001Lib.h>
#include <IRdecoder.h>

// define the pin for the IR receiver
const uint8_t IR_DETECTOR_PIN = 15;

// create an IRDecoder object
IRDecoder decoder(IR_DETECTOR_PIN);

/*
 * This is the standard setup function that is called when the ESP32 is rebooted
 * It is used to initialize anything that needs to be done once.
 */
void setup() 
{
  // This will initialize the Serial at a baud rate of 115200 for prints
  // Be sure to set your Serial Monitor appropriately
  Serial.begin(115200);

  // Initialize the decoder
  decoder.init();
}

/*
 * The main loop for the program. The loop function is repeatedly called
 * after setup() is complete.
 */
void loop()
{
  // Check for a key press on the remote
  int16_t keyPress = decoder.getKeyCode();

  // If a valid key is pressed, print out its value
  if(keyPress >= 0) Serial.println("Key: " + String(keyPress));
}
