#ifndef FlightController_h
#define FlightController_h

#include "Arduino.h"

#include "Globals.h"

class FlightController {
  private:
    byte mode = FLIGHT_MODE_RATE;
    short altitude = 0;
    float latitude = -1;
    float longitude = -1;
  public:
    const static byte FLIGHT_MODE_RATE = 'r';
    const static byte FLIGHT_MODE_FBW = 'f';
    const static byte FLIGHT_MODE_RTH = 'h';

    void setAltitude(const short altitude);
    const short getAltitude();
    bool setMode(const byte mode);
    const byte getMode();    
    void setLatitude(const float latitude);
    const float getLatitude();
    void setLongitude(const float longitude);
    const float getLongitude();
};

#endif

