#include <Arduino.h>
#include <AFMotor.h>

AF_DCMotor degree2(1);
AF_DCMotor degree3(2);
AF_DCMotor degree1(3);

float curr_ang_2 = 0;

void setup() {
  Serial.begin(9600);
  degree1.setSpeed(250);
  degree2.setSpeed(250);
  degree3.setSpeed(250);

}

void loop() {
  Serial.println("Elija grado de libertad que desea mover");
  while (Serial.available()==0){
  }
  int Movement_Degree = Serial.parseInt();
  Serial.println(Movement_Degree);
  switch (Movement_Degree) {
  case 1:
    while (Serial.available()==0){
    }
    Serial.println("seleccione los grados que desea mover");   
    float Movement_Angle1 = Serial.parseFloat();
    float time = Movement_Angle1/14;
    Serial.println("Moviendo");
    degree1.run(FORWARD);
    delay(time); 
    degree1.run(RELEASE);
    break;
  
  case 2:
    while (Serial.available()==0){
    }
    Serial.println("seleccione los grados que desea mover");
    float Movement_Angle2 = Serial.parseFloat();
    float time2 = Movement_Angle2/28;
    Serial.println("Moviendo");
    degree2.run(FORWARD);
    delay(time2);
    degree2.run(RELEASE);
    break;
  
  case 3:
    while (Serial.available()==0){
    }
    Serial.println("seleccione los grados que desea mover");
    float Movement_Angle3 = Serial.parseFloat();
    float time3 = Movement_Angle3/28;
    Serial.println("Moviendo");
    degree3.run(FORWARD);
    delay(time3);
    degree3.run(RELEASE);
    break;

  default:
    Serial.println("Opción no disponible");
    break;
  }

}

