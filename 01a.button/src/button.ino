#include <Arduino.h>
#include <RBE1001Lib.h>
#include <button.h>

// declare the pin for the LED
const int LED_PIN = 33;

// Create a button object for the built-in button on the ESP32
Button bootButton(BOOT_FLAG_PIN);

// Define two basic states. For this program, they will correspond to an LED state (on or off).
// "enum" stands for "enumerate". Basically, we define a new variable type called ROBOT_STATE.
// We prepend "ROBOT_" to everything to avoid conflicts with other variables that may be defined elsewhere.
enum ROBOT_STATE {ROBOT_IDLE, ROBOT_ACTIVE};

// Declare a variable, robotState, of our new type, ROBOT_STATE. Initialize it to ROBOT_IDLE.
ROBOT_STATE robotState = ROBOT_IDLE;

/*
 * This is the standard setup function that is called when the ESP32 is rebooted.
 * It is used to initialize anything that needs to be done once.
 */
void setup() 
{
  // This will initialize the Serial at a baud rate of 115200 for prints
  // Be sure to set your Serial Monitor appropriately in platformio.ini
  Serial.begin(115200);

  // Set the LED pin to be an OUTPUT
  pinMode(LED_PIN, OUTPUT);

  // Initialize the button object
  bootButton.Init();
}

void HandleButtonPress(void)
{
  // TODO: count button presses
  
  if(robotState == ROBOT_IDLE)
  {
      // Notify us that we're switching to ACTIVE
      Serial.println("Button press -> ACTIVE");

      // TODO: Turn on the LED

      // Finally, update the state
      robotState = ROBOT_ACTIVE;
  }

  else if(robotState == ROBOT_ACTIVE)
  {
      // Notify us that we're switching to IDLE
      Serial.println("Button press -> IDLE");

      // TODO: Turn off the LED

      // Finally, update the state
      robotState = ROBOT_IDLE;
  }
}

void loop()
{
  // Check to see if the button is pressed
  if(bootButton.CheckButtonPress()) HandleButtonPress();
}