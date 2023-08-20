#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);

  mySerial.begin(9600);
}

void loop() { // run over and over
 mySerial.println("AT+SEND=120,1,0");
 Serial.println("0");
 delay(1000);
 mySerial.println("AT+SEND=120,1,1");
 Serial.println("1");
 delay(1000);
}
