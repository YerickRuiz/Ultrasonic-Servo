#include <Servo.h>
int pos = 0;
int servo_pin = 9;

Servo myservo;


const int us_trigger = 2;
const int us_echo = 3;

int us_get_distance() {
  int distance;
  long duration;

  digitalWrite(us_trigger, HIGH);
  delay(100);
  digitalWrite(us_trigger, LOW);

  duration = pulseIn(us_echo, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}



void setup() {
  pinMode(us_trigger, OUTPUT);
  pinMode(us_echo, INPUT);

  Serial.begin(9600);
  digitalWrite(us_trigger, LOW);
  myservo.attach(9);
  myservo.write(pos);
  delay(100);
}

void loop() {
  int distance = us_get_distance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  //Send distance to servo
  myservo.write(pos);
  delay(50);
}