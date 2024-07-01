#include <Arduino.h>
#include <AFMotor.h>

AF_DCMotor degree2(1);
AF_DCMotor degree3(2);

void setup() {
  degree2.setSpeed(250);
  degree3.setSpeed(250);

}

void loop() {
  degree2.run(BACKWARD);
  delay(1000);
  degree2.run(RELEASE);
  delay(500);
  degree2.run(FORWARD);
  delay(1000);
}

