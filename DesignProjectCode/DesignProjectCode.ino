//Serial communications switch control logic by Amine & Ryan
//writen: 11/28/18 using arduino nano v3 & RXB6 RF reciever
//data pin from RXB6 ---> D10
//D13 controls on board LED
//D5 to controls a switch 


#include <SoftwareSerial.h>

//Need to simulate a TX RX port because the pins on the board get overriden if usb power is used
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  //intilizing outputs
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // waits for serial port to connect from the computer
  }
  Serial.println("Connected!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(2000);
  mySerial.println("Now Loading...\n");
}

void loop() { // run over and over
  
  if (mySerial.available()) {
    //writes the input from the reciver to the serial monitor
    Serial.write(mySerial.read());
    //Turns on the LED and digital pin 5 when the correct messge is recieved
    if (mySerial.read() == "Okay this is epic")
    {
      digitalWrite(13, HIGH);
      digitalWrite(5, HIGH);
    }
    //Turns off the LED and digital pin 5 when the correct messge is recieved
    else if (mySerial.read() == "delet this")
    {
     digitalWrite(13, LOW);
     digitalWrite(5, LOW);
    }
    else
    {
    //handels exceptions
    if (Serial.available()) 
    {
    Serial.println("sike that's the wrong number\n");
    }
    }
  }

}
