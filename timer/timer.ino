int led = 13;
int ledState = HIGH;

int sampleTime = 100;
uint32_t currentTime  = 0;
uint32_t previousTime = 0;
uint32_t elapsedTime  = 0;

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  
}

void setTimeOut(uint32_t sampleTime){
  currentTime = millis();
  elapsedTime = currentTime - previousTime;
  if(elapsedTime > sampleTime){
    //do something
    ledState = !ledState;
    digitalWrite(led, ledState);

    previousTime = currentTime;
  }
}
