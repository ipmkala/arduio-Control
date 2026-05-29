# Arduino Servo Motor Controller

[![Arduino](https://img.shields.io/badge/Arduino-00979D?logo=arduino&logoColor=fff)](#)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A simple yet comprehensive Arduino project for controlling standard servo motors with multiple control modes and precise angle positioning.

## 📌 Features

- **Sweep Mode** - Automatic 0° to 180° oscillation
- **Manual Control** - Set exact angle via Serial Monitor
- **Smooth Movement** - Configurable speed and delay
- **Serial Feedback** - Real-time position reporting

## 🧱 Hardware Requirements

| Component | Quantity |
|-----------|----------|
| Arduino Uno (or compatible) | 1 |
| Servo Motor (SG90/MG995/MG90S) | 1 |
| Jumper Wires (Male-to-Female) | 3 |
| External Power Supply (for multiple servos) | Optional |

## 🔌 Wiring Diagram

| Servo Wire | Color | Arduino Pin |
|------------|-------|-------------|
| Signal | Orange/Yellow | Digital Pin 9 |
| Power (VCC) | Red | 5V |
| Ground (GND) | Brown/Black | GND |

> ⚠️ **Important**: For multiple servos (more than 2), use an external 5V power supply to avoid damaging the Arduino's voltage regulator.

## 💻 Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/YOUR_USERNAME/arduino-servo-controller.git
