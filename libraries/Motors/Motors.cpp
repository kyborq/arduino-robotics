#include "Arduino.h"
#include "Motors.h"
 
Motors::Motors(int in1, int in2, int in3, int in4) {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  lf = in1;
  lb = in2;
  rf = in3;
  rb = in4;

  leftSpeed = 255;
  rightSpeed = 255;
}

void Motors::forward() {
  analogWrite(lf, leftSpeed);
  analogWrite(lb, 0);
  analogWrite(rf, rightSpeed);
  analogWrite(rb, 0);
}

void Motors::forward(int left, int right) {
  analogWrite(lf, left);
  analogWrite(lb, 0);
  analogWrite(rf, right);
  analogWrite(rb, 0);
}
 
void Motors::left() {
  analogWrite(lf, 0);
  analogWrite(lb, leftSpeed);
  analogWrite(rf, rightSpeed);
  analogWrite(rb, 0);
}

void Motors::right() {
  analogWrite(lf, leftSpeed);
  analogWrite(lb, 0);
  analogWrite(rf, 0);
  analogWrite(rb, rightSpeed);
}

void Motors::back() {
  analogWrite(lf, 0);
  analogWrite(lb, leftSpeed);
  analogWrite(rf, 0);
  analogWrite(rb, rightSpeed);
}

void Motors::back(int left, int right) {
  analogWrite(lf, 0);
  analogWrite(lb, left);
  analogWrite(rf, 0);
  analogWrite(rb, right);
}

void Motors::brake() {
  analogWrite(lf, 0);
  analogWrite(lb, 0);
  analogWrite(rf, 0);
  analogWrite(rb, 0);
}

void Motors::setSpeed(int newLeftSpeed, int newRightSpeed) {
  leftSpeed = newLeftSpeed;
  rightSpeed = newRightSpeed;
}

void Motors::setSpeed(int newSpeed) {
  leftSpeed = newSpeed;
  rightSpeed = newSpeed;
}
