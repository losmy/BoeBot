#include<Servo.h>

const int pingPin = 7;
const int turretPin=12;
const int tmitt=40;
const int stepCount=5;
long distArr[tmitt*2/stepCount+1] = { 0 };
boolean startScan = false;
Servo turret;
int i=0;
boolean f=true;
long dist;

void setup(){
pinMode(turretPin, OUTPUT);
turret.attach(turretPin);
Serial.begin(9600);
turret.write(25);
}

void loop(){
  if(i >= (tmitt*2))
  {
    startScan = true;
  }
  turnTurret();
  if(startScan)
  {
     distArr[i/stepCount]=getDistance();
     //Serial.println(i/stepCount);
     findMaxIndex();
    //for(int j=0;j<tmitt*2;j+=stepCount){
      /*Serial.print(distArr[i]);
      Serial.print(" ");
      Serial.println(findMaxIndex());
      Serial.print(" ");
      Serial.println(i);*/
    //}
  }
 

    delay(100);

 
}
