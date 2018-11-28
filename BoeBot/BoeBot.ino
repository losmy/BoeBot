#include<Servo.h>

const int pingPin = 7;
const int turretPin=12;
Servo turret;
int i=0;
boolean f=true;
long dist;

void setup(){
pinMode(turretPin, OUTPUT);
turret.attach(turretPin);
Serial.begin(9600);
}

void loop(){
 
 dist = getDistance();

 if(!(dist < 5))
 {
   turnTurret();
 }
   

 
}
