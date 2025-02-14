#include <Servo.h>
#include <HCSR04.h>
#include <PID.h>

const byte trigger = 13;
const byte echo = 12;
int throttle = 0;
int Kp = 1;
int Ki = 0;
int Kd = 0;
int targetDist = 200;

Servo motor;
UltraSonicDistanceSensor sensor(trigger, echo);
PID control(Kp, Ki, Kd);

void setup() {
  Serial.begin(9600);
  motor.attach(11);
}

void loop() {
  float dist = sensor.measureDistanceCm();
  control.calcErr(targetDist, dist);
  throttle = map(control.getOutput(), 0, 180, 0, 180);// untuk jika memakai .writeMicroseconds
  motor.write(throttle);
  Serial.print("Kp: ");
  Serial.print(control.getKp());
  Serial.print("  Ki: ");
  Serial.print(control.getKi());
  Serial.print("  Kd: ");
  Serial.println(control.getKd());
  delay(60);
}