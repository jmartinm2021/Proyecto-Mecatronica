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

  Serial.begin(9600);
  Serial.println("Butter Robot Rick and Morty");
}

void loop() {
  // Esperar a que el boton swe pulse para iniciar el comportamiento
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("Botón presionado. Iniciando prueba...");
    robotMantequilla();
  }
}

robotMantequilla(){
  delay(5000)

  // Levantar los brazos

  // Avanzar
  Serial.println("Avanzar");
  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, HIGH);
  digitalWrite(MOTOR2_PIN2, LOW);
  delay(3000);

  // Detener
  Serial.println("Stop");
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, LOW);
  delay(1000);

  // Bajar los brazos

  // Retroceder
  Serial.println("Avanzar");
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, HIGH);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, HIGH);
  delay(3000);

  // Detener
  Serial.println("Stop");
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, LOW);
  delay(1000);
 
  // BORRAR ESTO
  // Mover motor 1 hacia la posición 0 grados
  Serial.println("Motor 1 en posición 0 grados");
  motor1.write(0);  // 0 grados
  delay(1000); // Esperar 1 segundo

  // Mover motor 1 hacia la posición 90 grados
  Serial.println("Motor 1 en posición 90 grados");
  motor1.write(90);  // 90 grados
  delay(1000);

  // Mover motor 1 hacia la posición 180 grados
  Serial.println("Motor 1 en posición 180 grados");
  motor1.write(180);  // 180 grados
  delay(1000);

  // Mover motor 2 hacia la posición 0 grados
  Serial.println("Motor 2 en posición 0 grados");
  motor2.write(0);  // 0 grados
  delay(1000);

  // Mover motor 2 hacia la posición 90 grados
  Serial.println("Motor 2 en posición 90 grados");
  motor2.write(90);  // 90 grados
  delay(1000);

  // Mover motor 2 hacia la posición 180 grados
  Serial.println("Motor 2 en posición 180 grados");
  motor2.write(180);  // 180 grados
  delay(1000);
}

