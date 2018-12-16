#include<Servo.h>
//--------- TURRET ------------
Servo turret;
boolean forward = false;
int minTurn = 0;
int maxTurn = 60;
//---------- MOVEMENT ---------
Servo servoLeft;
Servo servoRight;
int wantedDist = 700;
int leftAdjust, rightAdjust;
//------ IR LED --------
int ledpin = 3;
int recieverPin = 2;
int servoDelay = 300;

int distForward;
int dist;
int offset;
int irFront;


void loop(){
  dist = 0;
  for(int i = 0; i < 10; i++)
  {
    dist += ping();
    delay(1);
  }
  dist = (int)dist/10; //get average of 10 messures to remove spikes
  //Serial.println(dist);
  UpdatePID();
//  setRightSpeed();
 // setLeftSpeed();
  //rotate();
  //moveRobot();
  //delay(servoDelay);
  delay(10);
  
}
