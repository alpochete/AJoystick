
#ifndef AJOYSTICK_H
#define AJOYSTICK_H

#include <Arduino.h>

class AJoystick {

private:
  int _pinX;
  int _pinY;
  int _pinButton;

  int _x;
  int _y;

  bool _button;
  bool _invert;

public:
  AJoystick(int pinX, int pinY, int pinButton, int invert = 0);

  void begin();
  void update();

  int getX() const;
  int getY() const;

  int normalizeX(int start, int end) const;
  int normalizeY(int start, int end) const;

  bool getButton() const;

  bool up() const;
  bool down() const;
  bool left() const;
  bool right() const;
  bool center() const;
};

#endif
