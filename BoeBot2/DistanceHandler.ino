
int maxOffset = 2000;
int maxTurnRate = 10;
void getSpeed(int offset)
{
   return map(offset,0,maxOffset,0,maxTurnRate);
}


void getOffset() //negativ to close to wall, positiv, to far away
{
  offset = wantedDist - dist;
}
