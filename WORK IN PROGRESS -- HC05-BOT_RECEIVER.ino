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
const char charge[] PROGMEM = "v12 L16 o4 cfa>cra>c4";
const char tetris[] PROGMEM = "!T240 L8 MS >e<eb>c>d>e16>d16>cba<aa>c>e<a>d>cb<g+b>c>d<e>e<e>c<aarae<bc d>d<d>f>ad16d16>g>f>e<cr>c>e<g>d>cb<g+b>c>d<e>e<e>c<aa<aa";
const char mario[] PROGMEM = 	"v12 L16 o5 eererce8g8r8<g8r8"
	"c8.<gr8<e8.<a8<b8<b-<a8<g.e.g.a8fgre8cd<b8."
	"c8.<gr8<e8.<a8<b8<b-<a8<g.e.g.a8fgre8cd<b8."
	"r8gf#fd#8er<g#<acr<acd"
	"r8gf#fd#8er>c8>c>c4"
	"r8gf#fd#8er<g#<acr<acd"
	"r8e-8rd8.c4";
const char oops[] PROGMEM = "v12 L16 o4 frc32<b32c32c#8cr8.erf";

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
      case 'T': // Plays the Tetris sound effect
        buzzer.playFromProgramSpace(tetris);
        break;
      case 'M': // Plays the Tetris sound effect
        buzzer.playFromProgramSpace(mario);
        break;
      case 'O': // Plays the Tetris sound effect
        buzzer.playFromProgramSpace(oops);
        break;
    }
  } else {
    // If no data is available, stop the motors
    motors.setSpeeds(0, 0);
  }
}
