#include "Arduino.h"
#include "Line.h"
 
Line::Line(int pin1) {
  pinMode(pin1, OUTPUT);

  _pin1 = pin1;
}

bool Line::getState(int id) {
  int state;
  switch (id) {
    case 1:
      state = digitalRead(_pin1);
      break;
  }
  return state;
}
