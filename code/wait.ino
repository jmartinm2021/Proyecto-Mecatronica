#include <Servo.h> 

// Servos
#define MOTOR1_PIN 3
#define MOTOR2_PIN 11

// Servos
Servo motor1;
Servo motor2;

void setup() {
  motor1.attach(MOTOR1_PIN);
  motor2.attach(MOTOR2_PIN);

}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.write(180);
  motor2.write(90);
  delay(1500);

  motor1.write(70);
  motor2.write(160);
  delay(200);
  motor1.write(110);
  motor2.write(180);
  delay(200);
  motor1.write(70);
  motor2.write(160);
  delay(200);
  motor1.write(110);
  motor2.write(180);
  delay(200);
  motor1.write(70);
  motor2.write(160);
  delay(200);
  motor1.write(110);
  motor2.write(180);
  delay(200);
  motor1.write(70);
  motor2.write(160);
  delay(200);
  motor1.write(110);
  motor2.write(180);
  delay(200);
  motor1.write(70);
  motor2.write(160);
  delay(200);
  motor1.write(110);
  motor2.write(180);
  delay(200);
  motor1.write(70);
  motor2.write(160);
  delay(200);
  motor1.write(110);
  motor2.write(180);
  delay(200);
}
