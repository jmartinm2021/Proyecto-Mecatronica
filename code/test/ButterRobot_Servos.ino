#include <Servo.h>

// Servos
#define MOTOR1_PIN 3
#define MOTOR2_PIN 11

// Motores ruedas
#define MOTOR1_PIN1 9
#define MOTOR1_PIN2 10
#define MOTOR2_PIN1 5
#define MOTOR2_PIN2 6

#define BUTTON_PIN A1

// Servos
Servo motor1;
Servo motor2;

void setup() {
  // Asociar servos con los pines
  motor1.attach(MOTOR1_PIN);
  motor2.attach(MOTOR2_PIN);

  // Motores ruedas
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(115200);
  Serial.println("Butter Robot Rick and Morty ready for commands");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Eliminar caracteres no deseados

    if (command == "FWD") {
      avanzar();
    } else if (command == "BACK") {
      retroceder();
    } else if (command == "LEFT") {
      girarIzquierda();
    } else if (command == "RIGHT") {
      girarDerecha();
    } else if (command == "STOP") {
      detener();
    } else if (command == "ARMS_UP") {
      brazosArriba();
    } else if (command == "ARMS_DOWN") {
      brazosAbajo();
    }

    delay(1000);
  }
}

void avanzar() {
  Serial.println("Avanzar");
  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, HIGH);
  digitalWrite(MOTOR2_PIN2, LOW);
}

void retroceder() {
  Serial.println("Retroceder");
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, HIGH);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, HIGH);
}

void girarIzquierda() {
  Serial.println("Girar izquierda");
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, HIGH);
  digitalWrite(MOTOR2_PIN1, HIGH);
  digitalWrite(MOTOR2_PIN2, LOW);
}

void girarDerecha() {
  Serial.println("Girar derecha");
  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, HIGH);
}

void detener() {
  Serial.println("Detener");
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, LOW);
}

void brazosArriba() {
  Serial.println("Brazos arriba");
  motor1.write(180);
  motor2.write(180);
}

void brazosAbajo() {
  Serial.println("Brazos abajo");
  motor1.write(0);
  motor2.write(0);
}
