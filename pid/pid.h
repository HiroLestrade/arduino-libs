#include<Arduino.h>
#include "Timer.h"

class PID{
  public:
    PID();
    ~PID();

    double getError();
    double getLastError();
    double getAccumError();
    double getRateError();
    double getOutput();
    
    double getKp();
    double getKi();
    double getKd();

    void setup(double kp, double ki, double kd);
    void tolerance(int minError, int maxError);
    void setOffset(int offset);
    
    double computePID(double input, double setpoint);
  
  private:
    Timer t();

    double error;
    double lastError;
    double accumError;
    double rateError;
    double output;

    int _maxError;
    int _minError;

    double _kp;
    double _ki;
    double _kd;

    int offset;
};