////////////////////////////////////////////////
// RECEIVER -- BOT /////////////////////////////
// HC-05 BLUETOOTH MODULE /////////////////////
// Madeline Davis, UCF - Physcial Computing ///
///////////////////////////////////////////////
// Last update April 23 //

#include <SoftwareSerial.h>
#include <ZumoMotors.h> // Include the Zumo Motors library
#include <ZumoBuzzer.h> // Include Zumo Buzzer Library


SoftwareSerial mySerial(12, 11); // RX, TX

ZumoMotors motors; 

ZumoBuzzer buzzer;
const char charge[] PROGMEM = "O4 T100 V15 L4 MS g12>c12>e12>G6>E12 ML>G2";

void setup() {
  Serial.begin(9600); // Begin serial communication with the computer
  mySerial.begin(38400); // Begin serial communication on the SoftwareSerial port
}

void loop() {
  if (mySerial.available()) {
    char command = mySerial.read(); // Read one byte from the SoftwareSerial port
    Serial.write(command); // Echo the command to the Serial Monitor for debugging

    // MAIN MOVEMENTS FBLR
    switch(command) {
      case 'F':
        motors.setSpeeds(400, 400); // Move Forward
        break;
      case 'B':
        motors.setSpeeds(-400, -400); // Move Backward
        break;
      case 'L':
        motors.setSpeeds(-250, 250); // Turn Left
        break;
      case 'R':
        motors.setSpeeds(250, -250); // Turn Right
        break;
/// Additional Inputs
      case 'A': 
        ///
        break;
      case 'C': // Plays the CHARGE! sound effect
        buzzer.playFromProgramSpace(charge);
        break;
/// Baseline
      default:
        motors.setSpeeds(0, 0); // Stop if no valid command is detected
        break;
    }
  } else {
    // If no data is available, stop the motors
    motors.setSpeeds(0, 0);
  }
}
