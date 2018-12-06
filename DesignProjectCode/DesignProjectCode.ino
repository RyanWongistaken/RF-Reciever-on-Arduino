//Serial communications switch control logic by Amine & Ryan
//writen: 11/28/18 using arduino nano v3 & RXB6 RF reciever
//data pin from RXB6 ---> D10
//D13 controls on board LED
//D5 to control switch
#include <SoftwareSerial.h>

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
  Serial.println("Link Established");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(2000);
  mySerial.println("Now Loading...\n");
}

void loop() { // run over and over
  /* This section of code polls for a single character from the RF module
     if the signal is recieved, the on board LED13 will turn on
     otherwise if a signal is not recieved the LED will go off


    int index = 0;
    if (mySerial.available())
    {

    while (mySerial.read() == '@')
    {
      Serial.print("Connection Received\n");
      digitalWrite(13, HIGH);
      digitalWrite(5, HIGH);
    }
    digitalWrite(13, LOW);
    digitalWrite(5, LOW);
    Serial.print("Connection Lost\n");

    }

    }*/
  /*
     This Section of code is Similar to the previous section
     except a passcode is agreeded upon before hand, such that the LED will
     only turn on if the specific code is recieved
  */
  int index = 0;
  String tempstring;
  while (index < 30)
  {
    tempstring += mySerial.read();
    index++;
  }
  tempstring += "\n";
  Serial.print(tempstring);
  //Checks for the code "EPIC" from the transmitter in decimal
  if (tempstring.indexOf("69807367") > 0 || tempstring.indexOf("65371321") > 0  )
    //We noticed that the voltage of the raspberry pi would affect singal thereby changing the code
  {
    Serial.print("Connection Received\n");
    digitalWrite(13, HIGH);
    digitalWrite(5, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
    digitalWrite(5, LOW);
  }

  Serial.print("Connection Lost\n");


}
