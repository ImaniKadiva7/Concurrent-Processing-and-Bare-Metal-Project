#include "traffic.h"
#include "sevenSegment.h"
#include "accellerometer.h"

TRAFFICLIGHTS trafficLights(8);
Seven_Segment segmentDisplay(4);
theAccellerometer surfaceOrientation(6);

int modeSwitchButtonPress = 0;
#define modeSwitchButton B00001000
#define modeSwitchButtonPressed !(PIND & modeSwitchButton);
#define modeSwitchButtonReleased !modeSwitchButtonPressed;
int buttonState = 1;
unsigned long buttonDebounceTimer = 300,
time = 0;

int lock = true,
moduleState = 0,
oldModeState = 0;

unsigned long previousTimeSchedule = 0,
timeForAccelerometer = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  trafficLights.initialize();
  segmentDisplay.initialize();
  surfaceOrientation.initialize();
  DDRD &= ~modeSwitchButton;
}

void loop() {
  // put your main code here, to run repeatedly:
  modeSwitchButtonPress = modeSwitchButtonPressed;
  if(modeSwitchButtonPress == 0)
  {
    modeSwitchButtonPress = modeSwitchButtonPressed;
    time = millis();
    buttonState = 1;
  }
  if((millis() - time) > buttonDebounceTimer && buttonState == 1)
  {
    time = millis();
    lock = true;
    buttonState = 0;
    moduleState = oldModeState + 1;
  }

  switch(moduleState)
  {
    case 1:
    {
      if(lock == true)
      {
        segmentDisplay.displayt();
        lock = false;
        oldModeState = moduleState;
      }
      trafficLights.on();
      segmentDisplay.heartbeat();
      break;
    }
    case 2:
    {
      if(lock == true)
      {
        trafficLights.off();
        segmentDisplay.record();
        lock = false;
        oldModeState = moduleState;
      }
      segmentDisplay.show();
      segmentDisplay.heartbeat();
      break;
    }
    case 3:
    {
      if(lock == true)
      {
        trafficLights.off();
        segmentDisplay.dontShow();
        lock = false;
        oldModeState = moduleState;
      }
      if(millis() - previousTimeSchedule >= timeForAccelerometer)
      {
        previousTimeSchedule = millis();
        surfaceOrientation.checkAngles();
        segmentDisplay.orientation(surfaceOrientation.showOrientation());
      }
      segmentDisplay.heartbeat();
      break;
    }
    case 4:
    {
      if(lock == true)
      {
        segmentDisplay.record();
        trafficLights.reset();
        lock = false;
        oldModeState = moduleState;
      }
      trafficLights.on();
      segmentDisplay.show();
      segmentDisplay.heartbeat();
      break;
    }
    case 5:
    {
      if(lock == true)
      {
        segmentDisplay.dontShow();
        oldModeState = moduleState;
        lock = false;
      }
      trafficLights.on();
      segmentDisplay.heartbeat();
      if(millis() - previousTimeSchedule >= timeForAccelerometer)
      {
        previousTimeSchedule = millis();
        surfaceOrientation.checkAngles();
        segmentDisplay.orientation(surfaceOrientation.showOrientation());
        if(surfaceOrientation.showOrientation() == 19) // right potrait
        {
          trafficLights.priorityState(2);
        }
        else if(surfaceOrientation.showOrientation() == 18) // left potrait
        {
          trafficLights.priorityState(3);
        }
        else
        {
          trafficLights.priorityState(1);
        }
      }
      break;
    }

    default:
      oldModeState = 0;
      moduleState = 1;
      break;
  }
}
