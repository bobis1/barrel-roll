#include <Arduino.h>
#include <AlfredoCRSF.h>
#include <Servo.h>



int driveMotor1Output1 = 36;
int driveMotor1Output2 = 39;
int driveMotor2Output1 = 35;
int driveMotor2Output2 = 34;
int weaponMotorOutput = 13;

float leftJoystickX;
float leftJoystickY;
float rightJoystickX;
float rightJoystickY;
bool isWeaponActive = false;
bool isSpinningForward = true;
Servo weaponMotor;
AlfredoCRSF crsf;

void setup() {
    pinMode(driveMotor1Output1, OUTPUT);
    pinMode(driveMotor1Output2, OUTPUT);
    pinMode(driveMotor2Output1,   OUTPUT);
    pinMode(driveMotor2Output2, OUTPUT);
    weaponMotor.attach(weaponMotorOutput);
    Serial1.begin(420000);
    crsf.begin(Serial1);

}

void loop() {
  crsf.update();
  leftJoystickY = crsf.getChannel(1);
  rightJoystickY = crsf.getChannel(2);
  leftJoystickX = crsf.getChannel(3);
  rightJoystickX = crsf.getChannel(4);
  if(!crsf.isLinkUp()){
    analogWrite(driveMotor1Output2, 0);
    analogWrite(driveMotor1Output1, 0);
    weaponMotor.writeMicroseconds(1000);
    isWeaponActive = false;
    return;
  }
  if (leftJoystickY >= 1600) {
    analogWrite(driveMotor1Output1, 120);
    analogWrite(driveMotor1Output2, 0);
  } else if(leftJoystickY <= 1400){
    analogWrite(driveMotor1Output1, 0);
    analogWrite(driveMotor1Output2, 120);
  } else{
    analogWrite(driveMotor1Output1, 0);
    analogWrite(driveMotor1Output2, 0);
  }
  if(rightJoystickY >= 1600){
    analogWrite(driveMotor2Output1, 120);
    analogWrite(driveMotor2Output2, 0);
  } else if(rightJoystickY <= 1400){
    analogWrite(driveMotor2Output1, 0);
    analogWrite(driveMotor2Output2, 120);
  } else{
    analogWrite(driveMotor2Output1, 0);
    analogWrite(driveMotor2Output2, 0);
  }
  if(leftJoystickX >= 1600){
    isWeaponActive = true;
  } else if (leftJoystickX <= 2000)
  {
    isWeaponActive = false;
  }
  if(rightJoystickX >= 1400){
    isSpinningForward = true;
  } else if (rightJoystickX <= 2000)
  {
    isSpinningForward = false;
  }
  if (isWeaponActive){
    if(isSpinningForward){
      weaponMotor.writeMicroseconds(2000);
    } else{
      weaponMotor.writeMicroseconds(1000);
    }
  }
}