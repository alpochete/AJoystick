# AJoystick Library

An Arduino library for controlling and reading analog joystick modules.

## Features

- Read X and Y axis values.
- Detect button presses.
- Detect joystick directions (up, down, left, right).
- Detect when the joystick is in the center.
- Normalize axis values to custom ranges.

## Installation via ZIP

1. Download this repository as a ZIP file:
   - Click the green **Code** button on GitHub.
   - Select **Download ZIP**.

2. Open the Arduino IDE.

3. Navigate to:
   **Sketch → Include Library → Add .ZIP Library...**

4. Select the downloaded `AJoystick.zip` file.

5. Wait for the installation to finish.

6. Include the library in your sketch:

```cpp
#include <AJoystick.h>
```

The library is now ready to use!

## Wiring

| Joystick Pin | Arduino Pin |
|---|---|
| VRx | A0 |
| VRy | A1 |
| SW | D2 |
| VCC | 5V |
| GND | GND |

## Basic Usage

```cpp
#include <AJoystick.h>

#define PIN_X A0
#define PIN_Y A1
#define PIN_BUTTON 2

AJoystick joystick(PIN_X, PIN_Y, PIN_BUTTON);

void setup() {
    Serial.begin(9600);
    joystick.begin();
}

void loop() {
    joystick.update();

    Serial.print("X: ");
    Serial.println(joystick.getX());

    Serial.print("Y: ");
    Serial.println(joystick.getY());

    if (joystick.up()) {
        Serial.println("UP");
    }

    if (joystick.down()) {
        Serial.println("DOWN");
    }

    if (joystick.left()) {
        Serial.println("LEFT");
    }

    if (joystick.right()) {
        Serial.println("RIGHT");
    }

    if (joystick.getButton()) {
        Serial.println("Button pressed");
    }

    delay(100);
}
```

## Available Methods

| Method | Description |
|---|---|
| `begin()` | Initializes joystick pins. |
| `update()` | Updates joystick readings. |
| `getX()` | Returns the X axis value. |
| `getY()` | Returns the Y axis value. |
| `getButton()` | Returns the button state. |
| `normalizeX(start, end)` | Maps X to a custom range. |
| `normalizeY(start, end)` | Maps Y to a custom range. |
| `up()` | Checks if the joystick is moving up. |
| `down()` | Checks if the joystick is moving down. |
| `left()` | Checks if the joystick is moving left. |
| `right()` | Checks if the joystick is moving right. |
| `center()` | Checks if the joystick is centered. |

## Important Notes

- Call `update()` before reading joystick values.
- The button uses `INPUT_PULLUP`.
- The button returns `true` when pressed.
- Direction thresholds are currently fixed:
  - Above 600: Up or Right.
  - Below 400: Down or Left.
  - Between 400 and 600: Center region.

**Note:** Actual axis orientation may vary depending on the joystick module.

## Project Structure

```text
AJoystick/
├── src/
│   ├── AJoystick.h
│   └── AJoystick.cpp
├── examples/
│   └── BasicUsage/
│       └── BasicUsage.ino
├── keywords.txt
├── library.properties
└── README.md
```

## Version

**1.0.2**



