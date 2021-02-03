// подключение драйвера к ардуино
// in1, in2, in3, in4
// при необходимости поменять номера пинов на нужные
int lf = 6;
int lb = 9;
int rf = 3;
int rb = 5;

int left_speed = 100;
int right_speed = 100;

void setup() {
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
}

void loop() {
  // список функций:
  // forward(); - вперед
  // left();    - поворот налево
  // right();   - поворот направо
  // back();    - назад
  // brake();   - остановка моторов
  
  forward();
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
