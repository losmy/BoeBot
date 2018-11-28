void turnTurret(){
  turret.write(i);
  if(f){
    i=i+1;
    if(i>=90){
      f=false;
    }
  }
  else{
    i=i-1;
    if(i<=0){
      f=true;
    }
  }
  delay(5);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

long getDistance()
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
  
  return microsecondsToCentimeters(duration);
}
