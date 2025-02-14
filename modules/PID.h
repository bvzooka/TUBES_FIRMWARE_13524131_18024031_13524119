#ifndef PID_h
#define PID_h

#include "Arduino.h"

class PID
{
  public: 
    PID(int Kp_, int Ki_, int Kd_);
    void calcErr(int des, int now);
    float feedback();
    float getOutput();
    int getKp();
    int getKi();
    int getKd();
  private:
    int Kp; 
    int Ki; 
    int Kd;
    int err; 
    int lastErr; 
    int errSum;
};

#endif