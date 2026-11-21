
#include "Joystick.h"

Joystick::Joystick(int pinX, int pinY, int pinButton)
  : _pinX(pinX),
    _pinY(pinY),
    _pinButton(pinButton),
    _x(512),
    _y(512),
    _button(false) {}

void Joystick::begin() {
  pinMode(_pinX, INPUT);
  pinMode(_pinY, INPUT);
  pinMode(_pinButton, INPUT_PULLUP);
}

void Joystick::update() {
  _x = analogRead(_pinX);
  _y = analogRead(_pinY);

  _button = !digitalRead(_pinButton);
}

int Joystick::getX() const {
  return _x;
}

int Joystick::getY() const {
  return _y;
}

bool Joystick::getButton() const {
  return _button;
}

int Joystick::normalizeX(int start, int end) const {
  return map(_x, 0, 1023, start, end);
}

int Joystick::normalizeY(int start, int end) const {
  return map(_y, 0, 1023, start, end);
}

bool Joystick::up() const {
  return _y > 600;
}

bool Joystick::down() const {
  return _y < 400;
}

bool Joystick::left() const {
  return _x < 400;
}

bool Joystick::right() const {
  return _x > 600;
}

bool Joystick::center() const {
  return _x > 400 && _x < 600 &&
         _y > 400 && _y < 600;
}
