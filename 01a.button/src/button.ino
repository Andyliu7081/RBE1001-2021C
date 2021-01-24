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

  // TODO: Set the LED pin to be an OUTPUT
  
  // Initialize the button object
  bootButton.Init();
}

/* Here is where all the fun happens. For each state, check for and respond to a button press.
 */ 
void loop()
{
  // Go through the state machine
  if(robotState == ROBOT_IDLE)
  {
    if(bootButton.CheckButtonPress()) //if the button was pressed, switch to ACTIVE
    {
      // Notify us that we're switching to ACTIVE
      Serial.println("Button press -> ACTIVE");

      // TODO: Turn the LED on

      // Finally, update the state
      robotState = ROBOT_ACTIVE;
    }
  }

  //note that we use else..if for each additional state, so it doesn't get confused
  else if(robotState == ROBOT_ACTIVE)
  {
    if(bootButton.CheckButtonPress()) //if the button was pressed, switch to IDLE
    {
      // Notify us that we're switching to IDLE
      Serial.println("Button press -> IDLE");

      // TODO: Turn the LED off

      // Finally, update the state
      robotState = ROBOT_IDLE;
    }
  }
}