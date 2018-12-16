#define Kp    4
#define Ki    1
#define Kd    4
double adjustSpeed;
double lastError;
double sumErrors;
unsigned long lastTime;
void UpdatePID()
{
  unsigned long now = millis();
  double timeChange = (double)(now - lastTime);
    
  double error = dist-wantedDist;
  double delta = (error-lastError)/timeChange;
  sumErrors += (error * timeChange);
  
  int motorSpeed = Kp * error+ Kd*delta;  //(Ki *  sumErrors)+ Kd * delta; 
  //Serial.println(motorSpeed);
  Serial.print(" kp:");
  Serial.print(Kp * error);
  Serial.print(" Ki:");
  Serial.print(Ki * sumErrors);
  Serial.print(" Kd:");
  Serial.print(Kd*delta);
  Serial.print(" MS:");
  Serial.print(motorSpeed);
  Serial.print(" error:");
  Serial.println(error);
 
  lastError = error;
  float msSpeed = map(motorSpeed,-700,700,-100,100);
  msSpeed = constrain(msSpeed,-100,100);
  msSpeed /= 100;
  steerRobot(msSpeed);
  lastTime = now;
  //Serial.println(ladjust);
    delay(20);
  //leftAdjust =  baseSpeedLeft + ladjust;
  //rightAdjust = baseSpeedRight + radjust;
  //leftAdjust = constrain(leftAdjust, 1500,1600);
  //rightAdjust = constrain(rightAdjust, 1400,1500);
 /* Serial.print(leftAdjust);
  Serial.print(":");
  Serial.print(rightAdjust);
  Serial.println();*/

}
