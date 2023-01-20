#include<Arduino.h>

class Timer{
  public:
    Timer(int sampleTime);
    ~Timer();

    //************************* Getters
    int       getSampleTime();
    uint32_t  getCurrentTime();
    uint32_t  getPreviousTime();
    uint32_t  getElapsedTime();

    //************************* Setters
    void setSampleTime(int sampleTime);

    //************************* Methods
    void update();
    void reset();
    bool diff();
    void sample(void (*callback)());

  private:
    uint32_t  _currentTime;
    uint32_t  _previousTime;
    uint32_t  _elapsedTime;
    int       _sampleTime;
};