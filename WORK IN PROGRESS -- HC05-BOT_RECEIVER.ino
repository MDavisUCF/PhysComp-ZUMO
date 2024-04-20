////////////////////////////////////////////////
// RECEIVER -- BOT /////////////////////////////
// HC-05 BLUETOOTH MODULE /////////////////////
// Madeline Davis, UCF - Physcial Computing ///
///////////////////////////////////////////////

#include <SoftwareSerial.h>
#include <ZumoMotors.h> // Include the Zumo Motors library
#include <ZumoBuzzer.h> // Include Zumo Buzzer Library


SoftwareSerial mySerial(11, 10); // RX, TX

ZumoMotors motors; 

ZumoBuzzer buzzer;
// Store in program space using the PROGMEM macro.  Later we will play
// it directly from program space, bypassing the need to load it all
// into RAM first.
const char melody1[] PROGMEM =
  "! O5 L16 agafaea dac+adaea fa<aa<bac#a dac#adaea f"
  "O6 dcd<b-d<ad<g d<f+d<gd<ad<b- d<dd<ed<f+d<g d<f+d<gd<ad"
  "L8 MS <b-d<b-d MLe-<ge-<g MSc<ac<a ML d<fd<f O5 MS b-gb-g"
  "ML >c#e>c#e MS afaf ML gc#gc# MS fdfd ML e<b-e<b-"
  "O6 L16ragafaea dac#adaea fa<aa<bac#a dac#adaea faeadaca"
  "<b-acadg<b-g egdgcg<b-g <ag<b-gcf<af dfcf<b-f<af"
  "<gf<af<b-e<ge c#e<b-e<ae<ge <fe<ge<ad<fd"
  "O5 e>ee>ef>df>d b->c#b->c#a>df>d e>ee>ef>df>d"
  "e>d>c#>db>d>c#b >c#agaegfe f O6 dc#dfdc#<b c#4";


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
        buzzer.playFromProgramSpace(melody1);
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
