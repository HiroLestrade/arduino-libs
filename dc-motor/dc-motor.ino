#include "dc-motor.h"

DCMotor motor(5, 6, 100); //motorPinA = 5  / motorPinB = 6

void setup(){
  Serial.begin(9600);  
}

void loop(){
  motor.forward();
  Serial.println(motor.toString());
  delay(1000);
  
  motor.stop();
  Serial.println(motor.toString());
  delay(1000);
  
  motor.backward();
  Serial.println(motor.toString());
  delay(1000);

  motor.stop();
  Serial.println(motor.toString());
  delay(1000);

  for(int i = 0; i < 255; i++){
    motor.forward(i);
    Serial.println((String) i + "\t" + (String)motor.getSignal());
    delay(4);
  }
  motor.stop();
  delay(1000);

  for(int i = 255; i > 0; i--){
    motor.forward(i);
    Serial.println((String) i + "\t" + (String)motor.getSignal());
    delay(4);
  }
  motor.stop();
  delay(1000);
}

