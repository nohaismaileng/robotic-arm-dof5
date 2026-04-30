#include <Servo.h>

// Define servo objects
Servo waistServo;
Servo shoulderServo;
Servo elbowServo;
Servo wristRollServo;
Servo wristPitchServo;
Servo gripperServo;

// Assign pins (change if you connected differently)
int waistPin = 5;
int shoulderPin = 6;
int elbowPin = 7;
int wristRollPin = 8;
int wristPitchPin = 9;
int gripperPin = 10;

// Center position for most servos
int centerPos = 90;
int moveAngle = 30;  
int gripperMoveAngle = 150; // gripper moves 100°

// Special calibration for shoulder servo (adjust until it's UP)
int shoulderCenterPos = 360;  // try 120 first; increase/decrease until "up"

// Delay
int delayTime = 250; // 250 ms

void setup() {
  waistServo.attach(waistPin);
  shoulderServo.attach(shoulderPin);
  elbowServo.attach(elbowPin);
  wristRollServo.attach(wristRollPin);
  wristPitchServo.attach(wristPitchPin);
  gripperServo.attach(gripperPin);

  // Move all servos to center first
  waistServo.write(centerPos);
  shoulderServo.write(shoulderCenterPos); // custom center
  elbowServo.write(centerPos);
  wristRollServo.write(centerPos);
  wristPitchServo.write(centerPos);
  gripperServo.write(centerPos);

  delay(2000); // wait 2 seconds before starting test
}

void loop() {
  // Waist servo
  waistServo.write(centerPos - moveAngle); delay(delayTime);
  waistServo.write(centerPos); delay(delayTime);
  waistServo.write(centerPos + moveAngle); delay(delayTime);
  waistServo.write(centerPos); delay(delayTime);

  // Shoulder servo (using its own center position)
  shoulderServo.write(shoulderCenterPos - moveAngle); delay(delayTime);
  shoulderServo.write(shoulderCenterPos); delay(delayTime);
  shoulderServo.write(shoulderCenterPos + moveAngle); delay(delayTime);
  shoulderServo.write(shoulderCenterPos); delay(delayTime);

  // Elbow servo
  elbowServo.write(centerPos - moveAngle); delay(delayTime);
  elbowServo.write(centerPos); delay(delayTime);
  elbowServo.write(centerPos + moveAngle); delay(delayTime);
  elbowServo.write(centerPos); delay(delayTime);

  // Wrist Roll servo
  wristRollServo.write(centerPos - moveAngle); delay(delayTime);
  wristRollServo.write(centerPos); delay(delayTime);
  wristRollServo.write(centerPos + moveAngle); delay(delayTime);
  wristRollServo.write(centerPos); delay(delayTime);

  // Wrist Pitch servo
  wristPitchServo.write(centerPos - moveAngle); delay(delayTime);
  wristPitchServo.write(centerPos); delay(delayTime);
  wristPitchServo.write(centerPos + moveAngle); delay(delayTime);
  wristPitchServo.write(centerPos); delay(delayTime);

  // Gripper servo (moves 60° instead of 30°)
  gripperServo.write(centerPos - gripperMoveAngle); delay(delayTime);
  gripperServo.write(centerPos); delay(delayTime);
  gripperServo.write(centerPos + gripperMoveAngle); delay(delayTime);
  gripperServo.write(centerPos); delay(delayTime);

  delay(1000); // pause before repeating the cycle
}
