
#include <AJoystick.h>

#define PIN_X A0
#define PIN_Y A1
#define PIN_BUTTON 2

Joystick joystick(PIN_X, PIN_Y, PIN_BUTTON);

void setup() {
  Serial.begin(9600);
  joystick.begin();
}

void loop() {
  joystick.update();

  Serial.print("X: ");
  Serial.print(joystick.getX());

  Serial.print(" | Y: ");
  Serial.print(joystick.getY());

  Serial.print(" | Button: ");
  Serial.println(joystick.getButton() ? "Pressed" : "Released");

  if (joystick.up()) {
    Serial.println("UP");
  }
  else if (joystick.down()) {
    Serial.println("DOWN");
  }
  else if (joystick.left()) {
    Serial.println("LEFT");
  }
  else if (joystick.right()) {
    Serial.println("RIGHT");
  }
  else if (joystick.center()) {
    Serial.println("CENTER");
  }

  delay(100);
}
