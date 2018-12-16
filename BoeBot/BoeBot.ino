#include<Servo.h>

const int pingPin = 7;
const int turretPin=12;
const int tmitt=70;
const int stepCount= 14;
int distArr[(tmitt*2/stepCount)+1] = { 0 };
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
turret.write(140);
Serial.begin(9600);
Serial.print("ArraySize:");
Serial.println(tmitt*2/stepCount+1);
delay(2000);
}

void loop(){
  if(i >= (tmitt*2) && !startScan)
  {
    startScan = true;
  }
  else
  {
      distArr[i/stepCount]=getDistance();  
      //Serial.println(i/stepCount);
  }
  turnTurret();
  if(startScan)
  {
        distArr[i/stepCount]=getDistance(); 
        int maxIndex = findMaxIndex();  
        moveRobot(distanceFromMiddle(maxIndex),distArr[maxIndex]);     
}
    /*  if(i == 80)
      {
          for(int p = 0; p < ((tmitt*2/stepCount)+1); p++)
          {
            Serial.print(p);
            Serial.print(":");
            Serial.print( distArr[p]);
            Serial.print(",");
          }
          Serial.println();
          findMaxIndex();
      }*/

          
        
    //delay(stepCount);
}


int distanceFromMiddle(int index)
{
  index = index * stepCount;
  
  int dist = tmitt - index;
  

  return dist;
}
