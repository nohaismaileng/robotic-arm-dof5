#include <Servo.h>

// Servo objects
Servo waist, shoulder, elbow, wristRoll, wristPitch, gripper;

// Servo pins (change if needed)
int waistPin = 3;
int shoulderPin = 5;
int elbowPin = 6;
int wristRollPin = 9;
int wristPitchPin = 10;
int gripperPin = 11;

// Servo positions
int waistPos = 90;
int shoulderPos = 120;  // calibrated so it's UP
int elbowPos = 90;
int wristRollPos = 90;
int wristPitchPos = 90;
int gripperPos = 90;

// Step size (degrees per command)
int stepAngle = 30;

void setup() {
  Serial.begin(9600);

  waist.attach(waistPin);
  shoulder.attach(shoulderPin);
  elbow.attach(elbowPin);
  wristRoll.attach(wristRollPin);
  wristPitch.attach(wristPitchPin);
  gripper.attach(gripperPin);

  // Move servos to initial positions
  waist.write(waistPos);
  shoulder.write(shoulderPos);
  elbow.write(elbowPos);
  wristRoll.write(wristRollPos);
  wristPitch.write(wristPitchPos);
  gripper.write(gripperPos);

  Serial.println("=== Robot Arm Ready ===");
  Serial.println("Controls:");
  Serial.println("W/A = Waist Left/Right");
  Serial.println("S/X = Shoulder Up/Down");
  Serial.println("E/D = Elbow Up/Down");
  Serial.println("R/F = Wrist Roll Left/Right");
  Serial.println("T/G = Wrist Pitch Up/Down");
  Serial.println("Y/H = Gripper Open/Close");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    switch (c) {
      case 'W': waistPos += stepAngle; break;
      case 'A': waistPos -= stepAngle; break;

      case 'S': shoulderPos += stepAngle; break;
      case 'X': shoulderPos -= stepAngle; break;

      case 'E': elbowPos += stepAngle; break;
      case 'D': elbowPos -= stepAngle; break;

      case 'R': wristRollPos += stepAngle; break;
      case 'F': wristRollPos -= stepAngle; break;

      case 'T': wristPitchPos += stepAngle; break;
      case 'G': wristPitchPos -= stepAngle; break;

      case 'Y': gripperPos += stepAngle; break;
      case 'H': gripperPos -= stepAngle; break;
    }

    // Keep values within 0–180 range
    waistPos = constrain(waistPos, 0, 180);
    shoulderPos = constrain(shoulderPos, 0, 180);
    elbowPos = constrain(elbowPos, 0, 180);
    wristRollPos = constrain(wristRollPos, 0, 180);
    wristPitchPos = constrain(wristPitchPos, 0, 180);
    gripperPos = constrain(gripperPos, 0, 180);

    // Write positions
    waist.write(waistPos);
    shoulder.write(shoulderPos);
    elbow.write(elbowPos);
    wristRoll.write(wristRollPos);
    wristPitch.write(wristPitchPos);
    gripper.write(gripperPos);

    // Feedback
    Serial.print("Moved: ");
    Serial.print(c);
    Serial.print(" -> New position = ");
    Serial.println(waistPos); // only prints waist for example
  }
}
