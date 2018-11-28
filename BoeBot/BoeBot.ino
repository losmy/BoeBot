#include<Servo.h>

const int pingPin = 7;
const int turretPin=12;
Servo turret;
int i=0;
boolean f=true;

void setup(){
pinMode(turretPin, OUTPUT);
turret.attach(turretPin);
Serial.begin(9600);
}

void loop(){
  turnTurret();
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
}
