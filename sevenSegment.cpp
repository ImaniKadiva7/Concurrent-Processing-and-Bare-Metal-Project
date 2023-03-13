#include "sevenSegment.h"
#include "Arduino.h"
Seven_Segment::Seven_Segment(int pin)
{

}
void Seven_Segment::initialize()
{
  DDRD |= B11110000;
  DDRD &= ~button;
}
void Seven_Segment::dontShow()
{
  PORTD &= B00000000;
}
void Seven_Segment::heartbeat()
{
  if(millis() - previoustime >= interval)
  {
    previoustime = millis();
    if(heartbeatState == 0)
    {
      Hex = 0X80;
      heartbeatState = 1;
    }
    else
    {
      Hex = 0x00;
      heartbeatState = 0;
    }
    writeToShiftRegister(Hex|Hexval[counter]);
  }
}
void Seven_Segment:: writeToShiftRegister(int values)
{
     int mask=0x80;
     PORTD &= ~latchPin;    //setting latchpin low
     for (int i = 7; i>=0; i--)  {
         if(((values|Hex)&mask)==LOW){
          PORTD &= ~datapin;   //setting datapin low
         }
         else
         {
          PORTD |= datapin;   //setting datapin high
         }
         PORTD |= clockpin;     //setting clockpin high
         PORTD &= ~clockpin;    //setting clockpin low
         mask>>=1;
     }
     PORTD |= latchPin;  //setting latchpin high
}
void Seven_Segment::show()
{
  if(counter < 0 || counter >= 15)
  {
    counter = 0;
  }
  writeToShiftRegister(Hex|Hexval[counter]);
  recordCounter = counter;
  buttonPress = buttonPressed;
  if(buttonPress == 0)
  {
    buttonPress = buttonPressed;
    buttonTimer = millis();
    buttonState = 1;
  }
  if((millis() - buttonTimer) > buttonDebounceTimer && buttonState == 1)
  {
    buttonTimer = millis();
    buttonState = 0;
    writeToShiftRegister(Hex|Hexval[counter]);
    counter++;
  }
}
void Seven_Segment::displayt()
{
  counter=16;
  writeToShiftRegister(0x78);  //write the value on the display
}
void Seven_Segment::orientation(int values)
{
  if(values >= 1)
  {
    counter=values;
    writeToShiftRegister(Hexval[counter]);
  }
}
void Seven_Segment::record()
{
  if(recordCounter >= 0 && recordCounter <= 15)
  {
    writeToShiftRegister(Hexval[recordCounter]);
  }
  else
  {
    recordCounter = 0;
  }
  counter = recordCounter;
}