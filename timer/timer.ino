#include "timer.h"

Timer t(100);

void setup(){
  Serial.begin(9600);
}

void loop(){
  t.update();
  if(t.getCurrentTime() < 5000){
    if(t.diff()){
      sample();
      t.reset();
    }
  }
}

void sample(){
  Serial.println("Current time: " + (String)t.getCurrentTime());
}
