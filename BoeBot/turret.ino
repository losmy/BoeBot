void turnTurret(){
  turret.write(i);
  if(f){
    i=i+stepCount;
    if(i>=tmitt*2){
      f=false;
    }
  }
  else{
    i=i-stepCount;
    if(i<=0){
      f=true;
    }
  }
  //delay(stepCount*2);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

int getDistance()
{
  long duration, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  delay(stepCount);
  return duration;
  //return microsecondsToCentimeters(duration);
}

int findMaxIndex(){
  int maxIndex= 0;
  long maxValue = 0;
  for(int j=0;j<tmitt*2/stepCount;j++){

    if(distArr[j]>maxValue){
      maxIndex = j;
      maxValue = distArr[j];
    }
  }
  return maxIndex;
}
