#include <Servo.h>

const int us_trigger = 2;
const int us_echo = 3;
const int servo_pin = 9;
const int average_num = 5;

Servo myservo;

int us_get_distance() {
  int distance;
  long duration;

  digitalWrite(us_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(us_trigger, LOW);

  duration = pulseIn(us_echo, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}

int filter_distance() {
  int distance = 0;
  int average = 0;
  int position = 0;
  
  for (int i = 0; i < average_num; i++) {
    average += us_get_distance();
    delay(20);
  }
  
  distance = average / average_num;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  position = distance * 4;
  if (position >= 180) {
    position = 180;
  }
  return position;
}

void setup() {
  pinMode(us_trigger, OUTPUT);
  pinMode(us_echo, INPUT);

  Serial.begin(9600);
  digitalWrite(us_trigger, LOW);
  myservo.attach(servo_pin);
  delay(100);
}

void loop() {

  //Send distance to servo
  myservo.write(filter_distance());
}