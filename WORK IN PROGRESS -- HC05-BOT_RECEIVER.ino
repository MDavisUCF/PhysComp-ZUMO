////////////////////////////////////////////////
// RECEIVER -- BOT /////////////////////////////
// HC-05 BLUETOOTH MODULE /////////////////////
// Madeline Davis, UCF - Physcial Computing ///
///////////////////////////////////////////////

#include <SoftwareSerial.h>
#include <ZumoMotors.h> // Include the Zumo Motors library
#include <ZumoBuzzer.h> // Include Zumo Buzzer Library



SoftwareSerial mySerial(11, 12); // RX, TX

ZumoMotors motors; 

ZumoBuzzer buzzer;
const char charge[] PROGMEM = "O4 T100 V15 L4 MS g12>c12>e12>G6>E12 ML>G2";

#define REVERSE_SPEED     400 // 0 is stopped, 400 is full speed
#define TURN_SPEED        400
#define FORWARD_SPEED     400 // 200 original

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
        motors.setSpeeds(400, 400); 
        break;
      case 'B':
        motors.setSpeeds(-200, -200); // Move Backward
        break;
      case 'L':
        motors.setSpeeds(-200, 200); // Turn Left
        break;
      case 'R':
        motors.setSpeeds(200, -200); // Turn Right
        break;
/// Additional Inputs
      case 'S': 
        motors.setSpeeds(0, 0);
        break;
      case 'C': // Plays the CHARGE! sound effect
        buzzer.playFromProgramSpace(charge);
        break;
    }
  } else {
    // If no data is available, stop the motors
    motors.setSpeeds(0, 0);
  }
}
