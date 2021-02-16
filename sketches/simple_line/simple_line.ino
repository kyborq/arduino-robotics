// --- пины драйвера к ардуино
// in1, in2, in3, in4
// при необходимости поменять номера пинов на нужные
int lf = 5;
int lb = 3;
int rf = 9;
int rb = 6;

// --- параметры моторов
int left_speed = 255;  // скорость левого мотора
int right_speed = 240; // скорость правого мотора

// --- пины датчиков линии к ардуино
int sensor_1 = 2; // пины датчиков
int sensor_2 = 4;

int line_1; // состояние датчиков <- на белом или черном поле
int line_2;

void setup() {
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);

  pinMode(sensor_1, INPUT);
  pinMode(sensor_2, INPUT);
}

void loop() {
  // список функций:
  // forward(); - вперед
  // left();    - поворот налево
  // right();   - поворот направо
  // brake();   - остановка моторов

  line_1 = digitalRead(sensor_1);
  line_2 = digitalRead(sensor_2);

  // если оба датчика на белом поле - робот едет вперед
  if (line_1 == HIGH && line_2 == HIGH) {
    forward();
  }

  // если первый датчик заметил линию - робот поворачивает налево
  if (line_1 == LOW  && line_2 == HIGH) {
    left();
  }

  // если второй датчик заметил линию - робот поворачивает налево
  if (line_1 == HIGH && line_2 == LOW) {
    right();
  }
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

void brake() {
  analogWrite(lf, 0);
  analogWrite(lb, 0);
  analogWrite(rf, 0);
  analogWrite(rb, 0);
}
