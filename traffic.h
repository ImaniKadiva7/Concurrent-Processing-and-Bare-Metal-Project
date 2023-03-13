#ifndef traffic
#define traffic
/*primaryGreen = digitalPin 13
  primaryYellow = digitalPin 12
  primaryRed = digitalPin 11

  secondaryRed = digitalPin 8
  secondaryYellow = digitalPin 9
  secondaryGreen = digitalPin 10
*/

const int equalPriority[] = {
                             B010010, B001001, B011001,
                             B100001, B010001, B001001,
                             B001011, B001100, B001010
                            };

class TRAFFICLIGHTS
{
  int state,
  timeChange;
  unsigned long previousTime = 0;
  int priorityStatus = 1;

  public:
    TRAFFICLIGHTS(int pin);
    void initialize(),
    on(), 
    off(),
    reset(),
    priorityState(int priority);

  private:
    void wait(const long interval),
    Write(int value);
    int _pin;
};
#endif