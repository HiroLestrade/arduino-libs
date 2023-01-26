#include<Arduino.h>

class DCMotor{
  public:
    DCMotor(int motorPinA, int motorPinB);
    DCMotor(int motorPinA, int motorPinB, int minSignal);
    ~DCMotor();

    //************************* Getters
    int getMinSignal();
    int getSignal();

    //************************* Setters
    void setMinSignal(int minSignal);
    void setTurn(int turn);

    //************************* Methods
    void forward();
    void forward(int signal);
    void backward();
    void backward(int signal);
    void stop();
    String toString();
    String jsonString();


  private:
    int _motorPinA;
    int _motorPinB;
    int _signal;
    int _minSignal;
    String _turn;
    
    enum movement{
      STOP,
      CLOCKWISE,
      COUNTER_CLOCKWISE
    };

    void verifySignal();


    
    //TODO: Include physical model values
    
    /*Characterization of DC motor
      Direct measurements:
        Vel: applied speed
        I: Measured current
        V_out: Measured voltage
      Indirect measurements:
        V_in = motorSignal/1023*Vs
        P_in = V_in*I
        P_out = V_out*I
      Kv = V_out/Vel
      nu = P_out/P_in : efficiency

    */
};