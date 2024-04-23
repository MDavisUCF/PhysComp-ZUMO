////////////////////////////////////////////////
// TRANSMITTER -- CONTROLLER ///////////////////
// HC-05 BLUETOOTH MODULE /////////////////////
// Madeline Davis, UCF - Physcial Computing ///
///////////////////////////////////////////////

// STUDENTS: Use the following in your existing controller code to interface with the bot via bluetooth.

#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // The bluetooth module connects to these pins on your Arduino (TX, RX)

/// The following is a simple example of button inputs. Here is where you would include your own.
int Button1 = 4; // Example button input (1)
int Button2 = 5; // Example button input (2)
int Button3 = 6; // Example button input (3)
int Button4 = 7; // Example button input (4)

void setup() {
  Serial.begin(9600);
  mySerial.begin(38400);

// Example button inputs - Looking for button presses for 4 seperate buttons
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP); 
  pinMode(Button3, INPUT_PULLUP); 
  pinMode(Button4, INPUT_PULLUP); 
}

void loop() {
  
  // Example button input readings
  int button1 = digitalRead(Button1);
  int button2 = digitalRead(Button2);
  int button3 = digitalRead(Button3);
  int button4 = digitalRead(Button4); 

// This makes the magic happen...
  if(button1 == LOW) // If button is pressed... 
  {
    mySerial.println("F"); // ... Send this letter to the bot. F is being sent here.
  }
  else if (button2 == LOW)
  {
    mySerial.println("B");
  }
    else if (button3 == LOW)
  {
    mySerial.println("L");
  }
      else if (button4 == LOW)
  {
    mySerial.println("R");
  }

  /// Button1 when pressed, sends "F" to bot. Bot knows "F" means move Forward.

}

// That's it!
/// To add additional letters, you will just need to create an other else if statement with a mySerial.println("LETTER");

// else if (CONTROLLER INPUT)
//{
// mySerial.println("LETTER");
// }
