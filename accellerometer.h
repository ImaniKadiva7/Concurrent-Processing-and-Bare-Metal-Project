#ifndef accellerometer
#define accellerometer

class theAccellerometer
{
  public: 
    theAccellerometer(int port);
    void initialize();
    int showOrientation(),
    checkAngles();

  private:
    int AcX, AcY, AcZ;
    float xaxis = 0.0,
    yaxis = 0.0;

    #define latchPin  B10000000 //DigitalPin 7
    #define clockpin  B01000000 //DigitalPin 6
    #define datapin   B00100000 //DigitalPin 5

    int Hex = 0x80;
    #define MPU_addr 0x68
    #define ACCEL_XOUT_H 0x3B
};

#endif