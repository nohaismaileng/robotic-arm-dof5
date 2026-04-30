#include <Servo.h>

// Define servo objects
Servo waistServo;
Servo shoulderServo;
Servo elbowServo;
Servo wristRollServo;
Servo wristPitchServo;
Servo gripperServo;

// Assign pins (change if you connected differently)
int waistPin = 3;
int shoulderPin = 5;
int elbowPin = 6;
int wristRollPin = 9;
int wristPitchPin = 10;
int gripperPin = 11;

// Center position (90° is usually middle for standard servos)
int centerPos = 90;
int moveAngle = 30;  
int delayTime = 250; // 250 ms delay

void setup() {
  waistServo.attach(waistPin);
  shoulderServo.attach(shoulderPin);
  elbowServo.attach(elbowPin);
  wristRollServo.attach(wristRollPin);
  wristPitchServo.attach(wristPitchPin);
  gripperServo.attach(gripperPin);

  // Move all servos to center first
  waistServo.write(centerPos);
  shoulderServo.write(centerPos);
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

  // Shoulder servo
  shoulderServo.write(centerPos - moveAngle); delay(delayTime);
  shoulderServo.write(centerPos); delay(delayTime);
  shoulderServo.write(centerPos + moveAngle); delay(delayTime);
  shoulderServo.write(centerPos); delay(delayTime);

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

  // Gripper servo
  gripperServo.write(centerPos - moveAngle); delay(delayTime);
  gripperServo.write(centerPos); delay(delayTime);
  gripperServo.write(centerPos + moveAngle); delay(delayTime);
  gripperServo.write(centerPos); delay(delayTime);

  delay(1000); // pause before repeating the cycle
}
