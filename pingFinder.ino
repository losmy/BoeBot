#include <Servo.h>

Servo servoLeft;
Servo servoRight;

double leftConst = 1;
double rightConst = 1;



double startIncrValue = 0.03;
double startDecValue = 0.03;

double incrLeft = 0.05;
double decLeft = 0.04;

double incrRight = 0.05;
double decRight = 0.04;
Turret turret;
void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT); pinMode(13,INPUT); //Left IR LED & Receiver
  pinMode(4, OUTPUT); pinMode(2, INPUT); //Right IR LED & Receiver

  pinMode(3,OUTPUT);
  pinMode(12,OUTPUT);

  pinMode(8,INPUT);
  
  servoLeft.attach(10);
  servoRight.attach(11);
  Serial.begin(9600);
  turret.

}

void loop() {
  // put your main code here, to run repeatedly:
  if(rcTime(8) < 120)
  {
    servoLeft.detach();
    servoRight.detach();
  }
  setLeftSpeed();
  setRightSpeed();

  
  if(irLeft == 0 && irRight == 0)
  {
    if(leftConst < rightConst)
    {
      decLeft = 0.1;
      decRight = 0.01;
    }
    if(rightConst < leftConst)
    {
      decLeft = 0.01;
      decRight = 0.1;
    }
  }
  else
  {
    decRight = startDecValue;
    decLeft = startDecValue;
  }
 
  if(irLeft == 0)
  {  
    digitalWrite(12,HIGH);
    rightConst -= decRight;
    if(rightConst < 0)
      rightConst = 0;
  }
  else if(irLeft == 1 && rightConst < 1)
  {
      rightConst += incrRight;
      if(rightConst > 1)
        rightConst = 1;
  }
  else
  {  
    digitalWrite(12,LOW);
  }
  
  if(irRight == 0)
  {
    digitalWrite(3,HIGH);
    leftConst -= decLeft;
    if(leftConst < 0)
      leftConst = 0;
  }
  else if(irRight == 1 && leftConst < 1)
  {
    leftConst += incrLeft;
    if(leftConst > 1)
      leftConst = 1;
  }
  else
  {
    digitalWrite(3,LOW);
  }
  
 delay(20);
}


int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);
  delay(1);
  int ir = digitalRead(irReceiverPin);
  delay(1);
  return ir;
}

void setLeftSpeed()
{
  int leftSpeed = 1500+(100*leftConst);
  servoLeft.writeMicroseconds(leftSpeed);
}

void setRightSpeed()
{
  int rightSpeed = 1500-(100*rightConst);
  servoRight.writeMicroseconds(rightSpeed);

}
long rcTime(int pin) // ..returns decay time
{
pinMode(pin, OUTPUT); // Charge capacitor
digitalWrite(pin, HIGH); // ..by setting pin ouput-high
delay(1); // ..for 5 ms
pinMode(pin, INPUT); // Set pin to input
digitalWrite(pin, LOW); // ..with no pullup
long time = micros(); // Mark the time
while(digitalRead(pin)); // Wait for voltage < threshold
time = micros() - time; // Calculate decay time
return time; // Return decay time
}
