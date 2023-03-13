#include "Arduino.h"
#include "traffic.h"

TRAFFICLIGHTS::TRAFFICLIGHTS(int pin)
{

}
void TRAFFICLIGHTS::initialize()
{
  DDRB |= B111111; // sets the LED as output
}
void TRAFFICLIGHTS::off()
{
  PORTB &= B000000;
}
void TRAFFICLIGHTS::wait(const long interval)
{
  if(millis()-previousTime >= interval)
  {
    previousTime = millis();
    timeChange = 1;
  }
  else
  {
    timeChange = 0;
  }
}
void TRAFFICLIGHTS::on()
{
  switch(state)
  {
    case 0:
      wait(0);
      if(timeChange)
      {
        timeChange = 0;
        state++;
      }
      break;
    case 1:
      Write(equalPriority[0]);
      wait(5000);
      if(timeChange)
      {
        timeChange = 0;
        state++;
      }
      break;
    case 2:
      Write(equalPriority[1]);
      wait(1000);
      if(timeChange)
      {
        timeChange = 0;
        state++;
      }
      break;
    case 3:
      Write(equalPriority[2]);
      wait(2000);
      if(timeChange)
      {
        timeChange = 0;
        state++;
      }
      break;
    case 4: 
      Write(equalPriority[3]);
      if(priorityStatus == 1)
      {
        wait(9000);
      }
      else if(priorityStatus == 2)
      {
        wait(12000);
      }
      else if(priorityStatus == 3)
      {
        wait(6000);
      }
      if(timeChange)
      {
        timeChange = 0;
        state++;
      }
      break;
    case 5:
      Write(equalPriority[4]);
      wait(2000);
      if(timeChange)
      {
        timeChange = 0;
        state++;
      }
      break;
    case 6:
      Write(equalPriority[5]);
      wait(1000);
      if(timeChange)
      {
        timeChange = 0;
        state++;
      }
      break;
    case 7:
      Write(equalPriority[6]);
      wait(2000);
      if(timeChange)
      {
        timeChange = 0;
        state++;
      }
      break;
    case 8:
      Write(equalPriority[7]);
      if(priorityStatus == 1)
      {
        wait(9000);
      }
      else if(priorityStatus == 2)
      {
        wait(6000);
      }
      else if(priorityStatus == 3)
      {
        wait(12000);
      }
      if(timeChange)
      {
        timeChange = 0;
        state++;
      }
      break;
    case 9:
      Write(equalPriority[8]);
      wait(2000);
      if(timeChange)
      {
        timeChange = 0;
        state=2;
      }
      break;
    default: state = 0;
  }

}
void TRAFFICLIGHTS::Write(int value)
{
  PORTB &= B000000;
  PORTB |= value;
}
void TRAFFICLIGHTS::priorityState(int priority)
{
  priorityStatus = priority;
}
void TRAFFICLIGHTS::reset()
{
  state = 0;
}