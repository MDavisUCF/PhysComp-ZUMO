////////////////////////////////////////////////
// RECEIVER -- BOT /////////////////////////////
// HC-05 BLUETOOTH MODULE /////////////////////
// Madeline Davis, UCF - Physcial Computing ///
///////////////////////////////////////////////

#include <SoftwareSerial.h>
#include <ZumoMotors.h> // ZUMO

SoftwareSerial mySerial(3, 2);

ZumoMotors motors; // ZUMO



void setup() {
  Serial.begin(9600);
  mySerial.begin(38400);
}

void loop() {
  if (mySerial.available())
    Serial.write(mySerial.read());

// MAIN MOVEMENTS FBLR
  if (mySerial.read() == 'F')
  {
    motors.setSpeeds(400, 400);  //ZUMO Forward
  }
  else if (mySerial.read() == 'B')
  {
    motors.setSpeeds(-400, -400);  //ZUMO Back
  }
    else if (mySerial.read() == 'L')
  {
    motors.setSpeeds(-250, 250);  //ZUMO Left
  }
      else if (mySerial.read() == 'R')
  {
    motors.setSpeeds(250, -250);  //ZUMO Right
  }

// FUN STUFF
  if (mySerial.read() == 'A')
  {
    motors.setSpeeds(400, 400);  //ZUMO Something like a buzzer
  }
}
