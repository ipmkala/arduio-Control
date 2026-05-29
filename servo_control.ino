/*
 * Project: Arduino Servo Motor Controller
 * Description: Control standard servo motor (0-180 degrees) with sweep functionality
 * Hardware: Arduino Uno, SG90/MG995 Servo Motor
 * Pin Mapping: Servo Signal -> Digital Pin 9
 * Author: [Your Name]
 * License: MIT
 */

#include <Servo.h>

// Pin Definitions
const int SERVO_PIN = 9;      // Signal pin for servo

// Servo Objects
Servo myServo;

// Program Variables
int currentAngle = 0;
int sweepDelay = 15;          // milliseconds per step (smoother = 10-20ms)

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
  myServo.write(0);
  
  Serial.println("Servo Controller Ready!");
  Serial.println("Commands: s[0-180] - Set angle");
  Serial.println("          sweep     - Start sweep mode");
}

void loop() {
  // Manual control via Serial Monitor
  if (Serial.available() > 0) {
    String command = Serial.readString();
    command.trim();
    
    if (command == "sweep") {
      runSweep();
    } 
    else if (command.startsWith("s")) {
      int angle = command.substring(1).toInt();
      if (angle >= 0 && angle <= 180) {
        setServoAngle(angle);
      } else {
        Serial.println("Error: Angle must be between 0 and 180");
      }
    }
  }
}

void setServoAngle(int angle) {
  myServo.write(angle);
  currentAngle = angle;
  Serial.print("Servo moved to: ");
  Serial.print(angle);
  Serial.println("°");
  delay(sweepDelay);
}

void runSweep() {
  Serial.println("Starting sweep mode...");
  
  // Sweep from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(sweepDelay);
  }
  
  // Sweep back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(sweepDelay);
  }
  
  Serial.println("Sweep completed!");
}
