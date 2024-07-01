#include <Arduino.h>
#include <Wire.h>

#define I2C_ADDRESS 0x3C
#define Encoder (0x36)

int Dato;
int DatoH;
int DatoL;
int Dato1;

//char dataReceived;
double angleFromSensor;
String angleToString;

void ReadRawAngle() {
  Wire.beginTransmission(Encoder);
  Wire.write(0x0C);
  Wire.endTransmission();
  Wire.requestFrom(Encoder, 2);

  if (Wire.available() == 2) {
    Dato = Wire.read();
    DatoH = Dato * 256;
    Dato = Wire.read();
    DatoL = Dato;
  }

  Dato1 = DatoH + DatoL;
  //Serial.println(Dato1);
  angleFromSensor = 0.087912 * Dato1;
}

void setup() {
  Serial1.begin(115200);
  Wire.begin();  // Inicia la comunicación I2C

  Dato = 0;
  DatoH = 0;
  DatoL = 0;
  Dato1 = 0;

  //dataReceived = 0;
  angleFromSensor = 0;
  angleToString = "";
} // <--- setup end

void loop() {
  ReadRawAngle();
  angleToString = String(angleFromSensor);
  Serial.println(angleToString);
//  if (Serial.available()) {
//    dataReceived = Serial.read();
//    if (dataReceived == 's') {
//      Serial.println(angleToString);
//    }
//  }
  delay(100);
}  // <--- loop end

