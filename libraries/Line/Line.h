#ifndef Line_h
#define Line_h
 
#include "Arduino.h"
 
class Line {
  public:
    Line(int pin1);
    // TODO: Add constructor for 2, 3, 4 and 5 sensors
    
    bool getState(int id); // Get info about sensor state
  private:
    int _pin1;
};
 
#endif
