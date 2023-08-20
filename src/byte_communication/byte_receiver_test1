#include <SoftwareSerial.h>
#include <Arduino.h>

typedef struct{
  int date;
  int data;
  unsigned long a;
  int f;
} Payload;

int data_pack_ASCII;
char data_pack_str[100] = "";
char data_pack_char;
int size = 0;

SoftwareSerial mySerial(A5, A4);

void HexToPayload(const uint8_t* HexData, Payload &pl){
  memcpy(&pl, HexData, sizeof(Payload));
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(57600);
  mySerial.begin(57600);
}

void loop() {
  Payload pl;
  pl.date = 0x00;
  pl.data = 0x00;
  pl.a = 0x00;
  pl.f = 0x00;
  Payload receivedPayload;

  int data_size = sizeof(pl) * 2;
  int size_str = sizeof(pl) / 5;

  if(mySerial.available()){
    data_pack_ASCII = mySerial.read();
    data_pack_char = (char)data_pack_ASCII;
    if(size < data_size + 19){
      data_pack_str[size] = data_pack_char;
      size++; 
    }
    if(strlen(data_pack_str) >= (data_size + 19)){
      char mydata[100];
      Serial.println(data_pack_str);
      delay(1000);
      for(int i= 9 + size_str; i < 8 + size_str + sizeof(pl) * 2; i++){
        mydata[i-(9+size_str)] = data_pack_str[i];
      }
      Serial.println(mydata);
      delay(1000);
      HexToPayload(mydata, receivedPayload);
      Serial.println(receivedPayload.date);
      data_pack_str[0] = '\0';
      size = 0;
      delay(1000);
    }
  }
}
