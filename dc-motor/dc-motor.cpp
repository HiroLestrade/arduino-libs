#include "dc-motor.h"

DCMotor::DCMotor(int motorPinA, int motorPinB){
  _motorPinA = motorPinA;
  _motorPinB = motorPinB;
  _minSignal = 0;
  _signal = 0;
  setTurn(STOP);

  pinMode(_motorPinA, OUTPUT);
  pinMode(_motorPinB, OUTPUT);
}

DCMotor::DCMotor(int motorPinA, int motorPinB, int minSignal){
  _motorPinA = motorPinA;
  _motorPinB = motorPinB;
  _minSignal = minSignal;
  _signal = 0;
  setTurn(STOP);

  pinMode(_motorPinA, OUTPUT);
  pinMode(_motorPinB, OUTPUT);
}

DCMotor::~DCMotor(){}

//************************* Getters
int DCMotor::getMinSignal(){
  return _minSignal;
}

int DCMotor::getSignal(){
  return _signal;
}

//************************* Setters
void DCMotor::setMinSignal(int minSignal){
  _minSignal = minSignal;
}

void DCMotor::setTurn(int turn){
  switch(turn){
    case STOP:
      _turn = "STOP";
      break;
    case CLOCKWISE:
      _turn = "Clockwise";
      break;
    case COUNTER_CLOCKWISE:
      _turn = "Counter clockwise";
      break;      
  }
}

//************************* Methods
void DCMotor::forward(){
  _signal = 255;
  setTurn(CLOCKWISE);
  digitalWrite(_motorPinA, HIGH);
  digitalWrite(_motorPinB, LOW);
}

void DCMotor::backward(){
  _signal = 255;
  setTurn(COUNTER_CLOCKWISE);
  digitalWrite(_motorPinA, LOW);
  digitalWrite(_motorPinB, HIGH);
}

void DCMotor::forward(int signal){
  _signal = signal + _minSignal;
  setTurn(CLOCKWISE);
  verifySignal();
  analogWrite(_motorPinA, signal);
  analogWrite(_motorPinB, 0);
}

void DCMotor::backward(int signal){
  _signal = signal + _minSignal;
  setTurn(COUNTER_CLOCKWISE);
  verifySignal();
  analogWrite(_motorPinA, 0);
  analogWrite(_motorPinB, signal);
}

void DCMotor::stop(){
  _signal = 0;
  setTurn(STOP);
  digitalWrite(_motorPinA, LOW);
  digitalWrite(_motorPinB, LOW);
}

String DCMotor::toString(){
  return  (String) "********* DC Motor *********\n" 
          + "Pin A: "   + (String)_motorPinA  + "\t" 
          + "Pin B: "   + (String)_motorPinB  + "\n" 
          + "Signal: "  + (String)_signal     + "\n"
          + "Turn: "    + _turn               + "\n"
          + "Signal offset: " + (String)_minSignal + "\n"
          + (String) "****************************\n";
}

String DCMotor::jsonString(){
  return "";
}

void DCMotor::verifySignal(){
  _signal = _signal > 255 ? 255 : _signal;
  _signal = _signal < _minSignal ? _minSignal : _signal;
}
