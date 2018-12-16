



void setup(){
pinMode(turretPin, OUTPUT);
turret.attach(turretPin);
pinMode(3,OUTPUT);
pinMode(12,OUTPUT);
pinMode(8,INPUT);
pinMode(3, INPUT);
pinMode(2, OUTPUT); // Left IR LED & Receiver
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
servoLeft.attach(10);
servoRight.attach(11);
turret.write(0);
Serial.begin(9600);
delay(2000);
}
