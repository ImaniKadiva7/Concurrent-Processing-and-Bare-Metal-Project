#include "accellerometer.h"
#include "Arduino.h"
#include <Wire.h>

theAccellerometer::theAccellerometer(int port)
{

}

void theAccellerometer::initialize()
{
  DDRD |= B11110000;
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}

int theAccellerometer::checkAngles()
{
  Wire.beginTransmission(MPU_addr);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 6, true);
  AcX=Wire.read()<<8|Wire.read();
  AcY=Wire.read()<<8|Wire.read();
  AcZ=Wire.read()<<8|Wire.read();
  xaxis=atan2(AcY, AcZ);
  //Serial.println("xaxis = ", xaxis);
  yaxis=atan2(AcX,((AcY*sin(xaxis)) + (AcZ*cos(xaxis))));
}

int theAccellerometer::showOrientation()
{
  // Checking for flat orientation
  if((yaxis>=-0.20 && xaxis >= -0.04 && xaxis<=0.38 && yaxis<=0.65)|| (xaxis<=-2.98 && yaxis<=1.12)) 
  {
    return 15;
  }
  // Cheking landscape orientation
  else if(xaxis<-0.05 && yaxis<=-0.70)
  {
    return 17;
  }
  // Cheking left potrait orientation
  else if(xaxis>=0.70 && yaxis>=-0.55 && xaxis<=1.02 && yaxis<=0.19)
  {
    return 18;
  }
  // Cheking right potrait orientation
  else if(yaxis>=-0.19 && xaxis<=-1.01 && yaxis<=0.33)
  {
    return 19;
  }
  // Cheking upside down orientation
  else if(xaxis>=-0.35 && yaxis>=0.95 && xaxis>-2.19 && yaxis<=1.52)
  {
    return 20;
  }
  else 
  {
    return 0;
  }
}