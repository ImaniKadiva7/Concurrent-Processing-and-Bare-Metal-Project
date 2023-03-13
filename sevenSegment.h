#ifndef sevenSegment
#define sevenSegment

                    //          0    1   2    3    4    5    6    7   8    9    A    B    C    D    E    F    t     L    l   r    U
const unsigned char Hexval[] ={0x3F,0x6,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71,0x78,0x38,0x18,0x50,0x3E};

class Seven_Segment
{
  public:
    Seven_Segment(int pin);
    void heartbeat();
    void initialize();
    void displayt();
    void dontShow();
    void show();
    void orientation(int values);
    void record();

  private:
    #define latchPin  B10000000 //DigitalPin 7
    #define clockpin  B01000000 //DigitalPin 6
    #define datapin   B00100000 //DigitalPin 5
    
    int buttonPress = 0;

    #define button B00000100 // digital pin 2
    #define buttonPressed !(PIND & button)
    #define buttonReleased !buttonPressed
    
    int counter=0, recordCounter = 0;
    int heartbeatState = 0,
    buttonState = 1;
    unsigned long previoustime = 0;
    unsigned long buttonDebounceTimer = 300,
    buttonTimer = 0; // 300ms
    const long interval = 340;
    void writeToShiftRegister(int values);
    void sevenwrite(int val);
    int Hex = 0x80;
};

#endif