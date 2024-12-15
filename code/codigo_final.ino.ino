#include <Servo.h> 

// Servos
#define MOTOR1_PIN 3
#define MOTOR2_PIN 11

// Servos
Servo motor1;
Servo motor2;

// Motores ruedas
#define MOTOR1_PIN1 9
#define MOTOR1_PIN2 10
#define MOTOR2_PIN1 5
#define MOTOR2_PIN2 6

#define BUTTON_PIN 2

void setup() {
  // Asociar servos con los pines
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  

  Serial.begin(9600);
  Serial.println("Butter Robot Rick and Morty");


  // Motores ruedas
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);

  delay(60000);

}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("Botón presionado. Iniciando prueba...");
    delay(6000);
    robotMantequilla();
  }
}

void robotMantequilla(){
  motor1.attach(MOTOR1_PIN);
  motor2.attach(MOTOR2_PIN);
  motor1.write(180);
  motor2.write(90);

  delay(1000);
  motor1.detach();
  motor2.detach();

  delay(2000);

  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, HIGH);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, HIGH);
  delay(2500);
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, LOW);

  delay(1000);

  motor1.attach(MOTOR1_PIN);
  motor2.attach(MOTOR2_PIN);

  motor1.write(135);
  motor2.write(135);

  delay(1000);

  motor1.detach();
  motor2.detach();

  delay(2000);

  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, HIGH);
  digitalWrite(MOTOR2_PIN2, LOW);
  delay(2500);
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, LOW);
}
