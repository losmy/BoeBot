double leftConst = 1;
double rightConst = 1;



double startIncrValue = 0.03;
double startDecValue = 0.03;

double incrLeft = 0.05;
double decLeft = 0.05;

double incrRight = 0.05;
double decRight = 0.05;

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
//negativt = höger
void moveRobot(int distToMiddle)
{ 
  

  if(distToMiddle > 0)
  {
    
    //decRight = map(distToMiddle,0,40,0,200);
    //decRight = decRight/10000;
      decRight = distToMiddle/20 * startDecValue;
    Serial.println((String)"H:" + rightConst);
  }
  if(distToMiddle < 0)
  {
    //decLeft = map(distToMiddle,0,40,0,200);
    //decLeft = decLeft/10000;
    decLeft = abs(distToMiddle/20 * startDecValue);
   // Serial.println((String)"V:" + leftConst);
  }



  if(distToMiddle > 0) //höger
  {
   rightConst -= decRight;
    if(rightConst < 0)
      rightConst = 0;
  }
  else if(distToMiddle < 0 )
  {
     rightConst += incrRight;
      if(rightConst > 1)
        rightConst = 1;
  }
  
  if(distToMiddle < 0) //vänster
  {
    leftConst -= decLeft;
    if(leftConst < 0)
      leftConst = 0;
  }
 else if(distToMiddle > 0)
  {
    leftConst += incrLeft;
    if(leftConst > 1)
      leftConst = 1;
  }
 
  //setLeftSpeed();
  //setRightSpeed();
}
