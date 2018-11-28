#include<Servo.h>

const int pingPin = 7;
Servo turret;
int i=0;
boolean f=true;
long dist;

void setup(){
pinMode(12, OUTPUT);
turret.attach(12);
Serial.begin(9600);
}

void loop(){
 
 dist = getDistance();

 if(!(dist < 5))
 {
   turnTurret();
 }
   

 
}
