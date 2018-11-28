#include<Servo.h>

const int pingPin = 7;
const int turretPin=12;
const int tmitt=40;
const int stepCount= 5;
long distArr[tmitt*2/stepCount+1] = { 0 };
boolean startScan = false;
Servo turret;
Servo servoLeft;
Servo servoRight;
int i=0;
boolean f=true;
long dist;

void setup(){
pinMode(turretPin, OUTPUT);
turret.attach(turretPin);
pinMode(3,OUTPUT);
pinMode(12,OUTPUT);
pinMode(8,INPUT);
servoLeft.attach(10);
servoRight.attach(11);
turret.write(tmitt);
Serial.begin(9600);
Serial.print("ArraySize:");
Serial.println(tmitt*2/stepCount+1);
delay(5000);
}

void loop(){
  if(i >= (tmitt*2) && !startScan)
  {
    startScan = true;
  }
  else
  {
      distArr[i/stepCount]=getDistance();  
  }
  turnTurret();
  if(startScan)
  {
        distArr[i/stepCount]=getDistance();   
        moveRobot(distanceFromMiddle(findMaxIndex()));     
  }
          
    //delay(stepCount);
}


int distanceFromMiddle(int index)
{
  index = index * stepCount;

  int dist = tmitt - index;
  

  return dist;
}
