#ifndef Motors_h
#define Motors_h
 
#include "Arduino.h"
 
class Motors {
  public:
    Motors(int in1, int in2, int in3, int in4);
    
    void forward();
    void left();
    void right();
    void back();
    void brake();

    void forward(int left, int right);
    void back(int left, int right);

    void setSpeed(int newLeftSpeed, int newRightSpeed);
    void setSpeed(int newSpeed);
  private:
    int lf;
    int lb;
    int rf;
    int rb;

    int leftSpeed;
    int rightSpeed;
};
 
#endif
