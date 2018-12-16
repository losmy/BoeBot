double leftConst = 1;
double rightConst = 1;


double slowTurn = 0.01;
double fastTurn = 0.1;

double incFast = 0.1;
double incSlow = 0.05;


double startIncrValue = 0.03;
double startDecValue = 0.03;

double incrLeft = 0.1;
double decLeft = 0.05;

double incrRight = 0.1;
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
void moveRobot(int distToMiddle, int dist)
{ 
    // Serial.println((String)"H:" + rightConst);
    Serial.print(distToMiddle);
    Serial.print(":");
    Serial.print(dist);
    Serial.println();
  /*if(distToMiddle > 20)
  {
    
    //decRight = map(distToMiddle,0,40,0,200);
    //decRight = decRight/10000;
      //decRight = distToMiddle/20 * startDecValue;
      decRight = fastTurn;
  }
  else
  {
    decRight = slowTurn;
  }
  if(distToMiddle < -20)
  {
    //decLeft = map(distToMiddle,0,40,0,200);
    //decLeft = decLeft/10000;
    //decLeft = abs(distToMiddle/20 * startDecValue);
   // Serial.println((String)"V:" + leftConst);
   decLeft = fastTurn;
  }
  else
  {
    decLeft = slowTurn;
  }*/


  if(distToMiddle > 5 )//&& dist > 600) //höger
  {
   rightConst -= decRight;
    if(rightConst < 0.2)
      rightConst = 0.2;
  }
  else if(distToMiddle < 5 )
  {
     rightConst += incSlow;
      if(rightConst > 1)
        rightConst = 1;
  }
  else
  {
      rightConst += incFast;
      if(rightConst > 1)
        rightConst = 1;
  }
  
  if(distToMiddle < -5 )//&& dist > 600) //vänster
  {
    leftConst -= decLeft;
    if(leftConst < 0.2)
      leftConst = 0.2;
  }
 else if(distToMiddle > -5)
  {
    leftConst += incSlow;
    if(leftConst > 1)
      leftConst = 1;
  }
  else
  {
    leftConst += incFast;
    if(leftConst > 1)
      leftConst = 1;
  }
 
  setLeftSpeed();
  setRightSpeed();
}
