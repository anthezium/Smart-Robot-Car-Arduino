//This demo is used for testing the Motor module.
#include <UCMotor.h>

UC_DCMotor leftMotor1(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor1(4, MOTOR34_64KHZ);
UC_DCMotor leftMotor2(1, MOTOR34_64KHZ);
UC_DCMotor rightMotor2(2, MOTOR34_64KHZ);

UC_DCMotor motors[] = {leftMotor1, rightMotor1, leftMotor2, rightMotor2}; 
#define N_MOTORS 4
#define FWD 0x01
#define BCK 0x02
#define LFT 0x03
#define RGT 0x04
#define STP 0x05

void setup() {
  // put your setup code here, to run once:

}

void stopAll() {
  leftMotor1.run(0x05); leftMotor2.run(0x05);
  rightMotor1.run(0x05); rightMotor2.run(0x05);
  leftMotor1.setSpeed(0); leftMotor2.setSpeed(0);
  rightMotor1.setSpeed(0); rightMotor2.setSpeed(0);
}

void goDir(UC_DCMotor motor, int dir, int speed) {
  motor.run(dir);
  motor.setSpeed(speed);
}

void goFwd(UC_DCMotor motor) {
  goDir(motor, 0x01, 200);
}
void goBck(UC_DCMotor motor) {
  goDir(motor, 0x02, 200);
}
void goLft(UC_DCMotor motor) {
  goDir(motor, 0x03, 200);
}
void goRgt(UC_DCMotor motor) {
  goDir(motor, 0x04, 200);
}

void allDir(UC_DCMotor *motors, int n, int dir) {
  int i;
  for(i=0; i<n; ++i) {
    goDir(motors[i], dir, 200);
  }
}

void go(int dir) {
  allDir(motors, N_MOTORS, dir);
}

void loop() {

  go(FWD);
  delay(2000);
  stopAll();
  delay(2000);
  go(BCK);
  delay(2000);
  stopAll();
  delay(2000);
  go(LFT);
  delay(2000);
  stopAll();
  delay(2000);
  go(RGT);
  delay(2000);
  stopAll();
  delay(5000);
  
  /* //Forward
   goFwd(leftMotor1);
   goFwd(rightMotor1);
   delay(2000);
   stopAll();
   delay(2000);
   
   //Backward
   goBck(leftMotor1);
   goBck(rightMotor1);
   delay(2000);
   stopAll();
   delay(2000);
   
   //left
   goLft(leftMotor1);
   goLft(rightMotor1);
   delay(2000); 
   stopAll();
   delay(2000);
   
   //Right
   goRgt(leftMotor1);
   goRgt(rightMotor1);
   delay(2000);
   //Stop
   stopAll();
   delay(6000);
   while(1); */
}
