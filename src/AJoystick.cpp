
#include "AJoystick.h"

AJoystick::AJoystick(int pinX, int pinY, int pinButton)
  : _pinX(pinX),
    _pinY(pinY),
    _pinButton(pinButton),
    _x(512),
    _y(512),
    _button(false) {}

void AJoystick::begin() {
  pinMode(_pinX, INPUT);
  pinMode(_pinY, INPUT);
  pinMode(_pinButton, INPUT_PULLUP);
}

void AJoystick::update() {
  _x = analogRead(_pinX);
  _y = analogRead(_pinY);

  _button = !digitalRead(_pinButton);
}

int AJoystick::getX() const {
  return _x;
}

int AJoystick::getY() const {
  return _y;
}

bool AJoystick::getButton() const {
  return _button;
}

int AJoystick::normalizeX(int start, int end) const {
  return map(_x, 0, 1023, start, end);
}

int AJoystick::normalizeY(int start, int end) const {
  return map(_y, 0, 1023, start, end);
}

bool AJoystick::up() const {
  return _y > 600;
}

bool AJoystick::down() const {
  return _y < 400;
}

bool AJoystick::left() const {
  return _x < 400;
}

bool AJoystick::right() const {
  return _x > 600;
}

bool AJoystick::center() const {
  return _x > 400 && _x < 600 &&
         _y > 400 && _y < 600;
}
