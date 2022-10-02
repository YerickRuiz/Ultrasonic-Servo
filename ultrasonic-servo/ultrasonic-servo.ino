#include <Servo.h>
int pos = 0;
int servo_pin = 9;

Servo myservo;


void setup() {
  myservo.attach(9);
  myservo.write(pos);
  delay(100);
}

void loop() {

  myservo.write(pos);
  delay(50);
}