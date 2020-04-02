/*
 * Connections->
 *  GSM    Arduino
 *  RX       10
 *  TX        9
 *  GND     GND
 */

#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
 
int inputPin = 5;               // choose the input pin (for PIR sensor)
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(inputPin, INPUT);     // declare sensor as input
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH    
    mySerial.begin(9600);       // set the data rate for the SoftwareSerial port
    delay(2000);                // necessary delay
    mySerial.println("ATD0921142XXX;"); // Thay SĐT 
  }
  else {
    //Nothing to be done here
  }
  delay(2000);                  // Check for motion after 2 seconds
}
