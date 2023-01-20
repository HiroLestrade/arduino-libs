#include "timer.h"

Timer::Timer(int sampleTime){
  _sampleTime   = sampleTime;
  _currentTime  = 0;
  _previousTime = 0;
  _elapsedTime  = 0;
}

Timer::~Timer(){}

//************************* Getters
int Timer::getSampleTime(){
  return _sampleTime;
}

uint32_t Timer::getCurrentTime(){
  return _currentTime;
}

uint32_t Timer::getPreviousTime(){
  return _previousTime;
}

uint32_t Timer::getElapsedTime(){
  return _elapsedTime;
}

//************************* Setters
void Timer::setSampleTime(int sampleTime){
  _sampleTime = sampleTime;
}

//************************* Methods
void Timer::update(){
  _currentTime = millis();
  _elapsedTime = _currentTime - _previousTime;
}

void Timer::reset(){
  _previousTime = _currentTime;
  _elapsedTime = 0;
}

bool Timer::diff(){
   return _elapsedTime > _sampleTime;
}

void Timer::sample(void (*callback)()){
  update();
  if(diff()){
    callback();
    reset();
  }
}
