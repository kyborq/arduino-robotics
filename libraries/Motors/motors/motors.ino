#include <Motors.h>

// создание объекта, через который будем взаимодействовать с нашим роботом
// подключение пинов по порядку: in1, in2, in3, in4
Motors robot(3, 5, 6, 9);

void setup() {
  // robot.setSpeed(100);     - установка скорости для обоих моторов
  // robot.setSpeed(50, 100); - установка скорости для моторов по отдельности
  
  robot.setSpeed(100);  
}

void loop() {
  // robot.forward();       - простое движение прямо
  // robot.forward(100, 0); - движение вперед по настраиваемым скоростям
  // robot.back();          - простое движение назад
  // robot.back(0, 100);    - движение назад по настраиваемым скоростям
  // robot.left();          - поворот налево
  // robot.right();         - поворот направо
  // robot.brake();         - остановка
  
  robot.forward();
  delay(500);
  robot.left();
  delay(500);
  robot.right();
  delay(500);
}
