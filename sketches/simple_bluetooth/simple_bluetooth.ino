#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

// подключение драйвера к ардуино
// in1, in2, in3, in4
// при необходимости поменять номера пинов на нужные
int lf = 5;
int lb = 3;
int rf = 9;
int rb = 6;

int left_speed = 255;
int right_speed = 240;

float k_slow = 0.8;

char command;

void setup() {
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);

  mySerial.begin(9600);
}

void loop() {
  // список функций:
  // forward(); - вперед
  // left();    - поворот налево
  // right();   - поворот направо
  // back();    - назад
  // brake();   - остановка моторов

  // right();

  if (mySerial.available()) {
    command = mySerial.read();

    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'R':
        right();
        break;
      case 'L':
        left();
        break;
      case 'G':
        forward_left();
        break;
      case 'I':
        forward_right();
        break;
      case 'H':
        back_left();
        break;
      case 'J':
        back_right();
        break;
      default:
        brake();
        break;
    }
  }
}

void forward_left() {
  analogWrite(lf, left_speed * k_slow);
  analogWrite(lb, 0);
  analogWrite(rf, right_speed);
  analogWrite(rb, 0);
}

void forward_right() {
  analogWrite(lf, left_speed);
  analogWrite(lb, 0);
  analogWrite(rf, right_speed * k_slow);
  analogWrite(rb, 0);
}

void back_left() {
  analogWrite(lf, 0);
  analogWrite(lb, left_speed * k_slow);
  analogWrite(rf, 0);
  analogWrite(rb, right_speed);
}

void back_right() {
  analogWrite(lf, 0);
  analogWrite(lb, left_speed);
  analogWrite(rf, 0);
  analogWrite(rb, right_speed * k_slow);
}

void forward() {
  analogWrite(lf, left_speed);
  analogWrite(lb, 0);
  analogWrite(rf, right_speed);
  analogWrite(rb, 0);
}

void left() {
  analogWrite(lf, 0);
  analogWrite(lb, left_speed);
  analogWrite(rf, right_speed);
  analogWrite(rb, 0);
}

void right() {
  analogWrite(lf, left_speed);
  analogWrite(lb, 0);
  analogWrite(rf, 0);
  analogWrite(rb, right_speed);
}

void back() {
  analogWrite(lf, 0);
  analogWrite(lb, left_speed);
  analogWrite(rf, 0);
  analogWrite(rb, right_speed);
}

void brake() {
  analogWrite(lf, 0);
  analogWrite(lb, 0);
  analogWrite(rf, 0);
  analogWrite(rb, 0);
}
