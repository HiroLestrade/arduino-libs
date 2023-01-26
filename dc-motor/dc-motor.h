class DCMotor{
  public:
    DCMotor(int motorPinA, int motorPinB);
    DCMotor(int motorPinA, int motorPinB), int minSignal;
    ~DCMotor();

    //************************* Getters
    int getMinSignal();

    //************************* Setters
    void setMinSignal(int minSignal);

    //************************* Methods
    void forward();
    void forward(int signal);
    void backward();
    void backward(int signal);
    void stop();
    void toString();


  private:
    int _motorPinA;
    int _motorPinB;
    int _signal;
    int _minSignal;
    
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