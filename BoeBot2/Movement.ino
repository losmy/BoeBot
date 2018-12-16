int maxConst = 100;
int leftConst = maxConst; 
int rightConst = maxConst;

int startDec = 10;

int decRight = 10;
int decLeft = 10;
int incRight = 10;
int incLeft = 10;




double leftPID;
double rightPID;
//negative = turn right
//positve = turn left

//------------- auto ------
int maxSteeringAngle = 50; 
int baseSpeedL = 1580;
int baseSpeedR = 1420;
int motorConst;
float adjustRate;
//int leftConst = 1;//
//int rightConst = 1;
int steering; // (-100-100)
int motorSpeed;
int counter;
bool ir = false;
bool ultra = false;

void steerRobot(float steering)//steering -50 till 50
{
  //steering += adjustSteering;
 // steering = constrain(steering,-maxSteeringAngle, maxSteeringAngle);
  setMotorSpeed(steering);  
}

void setMotorSpeed(float adjust)
{
  
  
  
    if(irDetect(2, 3, 42000) == 0) // Check for object
    {
      Serial.println("Wall Detected");
      wantedDist= 1800;
      baseSpeedL = 1575;
      counter = 0;
      digitalWrite(13,HIGH);
    }
    else if(counter > 8) 
    {
      digitalWrite(13,LOW);
      wantedDist = 700; 
      baseSpeedL = 1580;
    }
    counter++;
      Serial.println(adjust);
        Serial.println(counter);
    adjust = constrain(adjust, -1,1);  
    adjust = adjust*maxSteeringAngle;
    servoLeft.writeMicroseconds(baseSpeedL + adjust);//leftConst*maxSteeringAngle);
    servoRight.writeMicroseconds(baseSpeedR + adjust); //rightConst*maxSteeringAngle);
  /*  Serial.print(baseSpeedL + adjust);
    Serial.print(":");
    Serial.print(baseSpeedR + adjust);
    Serial.println();*/


}
void setLeftSpeed(int motorSpeed)
{
//  int leftSpeed = 1500+();
  servoLeft.writeMicroseconds(motorSpeed);
}

void setRightSpeed(int motorSpeed)
{
  //int rightSpeed = 1500-(rightConst);
  servoRight.writeMicroseconds(motorSpeed);
}
