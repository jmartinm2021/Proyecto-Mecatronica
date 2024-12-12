#include <Bluepad32.h>

ControllerPtr myController = nullptr;

void onConnectedController(ControllerPtr ctl) {
  if (myController == nullptr) {
    myController = ctl;
    Serial.printf("Controller connected: %s\n", ctl->getModelName().c_str());
  } else {
    Serial.println("Already connected to a controller!");
  }
}

void onDisconnectedController(ControllerPtr ctl) {
  if (myController == ctl) {
    Serial.println("Controller disconnected.");
    myController = nullptr;
  }
}

void processGamepad(ControllerPtr ctl) {
  if (ctl->axisY() <= -50) {
    Serial.println("FWD"); // Avanzar
  } else if (ctl->axisY() >= 50) {
    Serial.println("BACK"); // Retroceder
  } else if (ctl->axisX() <= -50) {
    Serial.println("LEFT"); // Girar izquierda
  } else if (ctl->axisX() >= 50) {
    Serial.println("RIGHT"); // Girar derecha
  } else {
    Serial.println("STOP"); // Detener
  }

  if (ctl->axisRY() <= -50) {
    Serial.println("ARMS_UP"); // Subir brazos
  } else if (ctl->axisRY() >= 50) {
    Serial.println("ARMS_DOWN"); // Bajar brazos
  }
}

void setup() {
  Serial.begin(115200);
  BP32.setup(&onConnectedController, &onDisconnectedController);
}

void loop() {
  BP32.update();
  if (myController && myController->isConnected() && myController->hasData()) {
    processGamepad(myController);
  }
  delay(150);
}
