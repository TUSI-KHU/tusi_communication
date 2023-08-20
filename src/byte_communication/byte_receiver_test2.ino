#include <SoftwareSerial.h>
#include <Arduino.h>

typedef struct{
  int date;
  int data;
  unsigned long a;
  int f;
} Payload;

SoftwareSerial mySerial(A5, A4);

void HexToPayload(const uint8_t* Hexdata, Payload &pl){
  memcpy(&pl, Hexdata, sizeof(Payload));
}

void setup() {
  Serial.begin(57600);
  mySerial.begin(57600);

}

void loop() {
  Payload pl;
  pl.date = 0x00;
  pl.data = 0x00;
  pl.a = 0x00;
  pl.f = 0x00;

  size_t bufSize = sizeof(pl);

  if(mySerial.available() >= bufSize * 2){
    uint8_t receivedData[bufSize * 2];
    for(size_t i = 0; i < bufSize * 2; i++){
      receivedData[i] = mySerial.read();
      Serial.print(receivedData[i]);
    }

    Payload receivedPayload;
    HexToPayload(receivedData, receivedPayload);
  }

  if(Serial.available()){
    Serial.println(pl.date);
    Serial.println(pl.data);
    Serial.println(pl.a);
    Serial.println(pl.f);
  }

}
