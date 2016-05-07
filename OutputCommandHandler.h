#ifndef OutputCommandHandler_h
#define OutputCommandHandler_h

#include "Arduino.h"
#include "BaseCommandHandler.h"

#define OUTPUT_COMMAND_PAYLOAD_SIZE 4

class OutputCommandHandler: public BaseCommandHandler {
  private:
    byte ailerons;
    byte elevator;
    byte throttle;
    byte rudder;
  public:
    const static byte COMMAND_TYPE = 'o';
    bool canHandle(const byte commandType);
    bool hasExecuted();
    const int getAilerons();
    const int getElevator();
    const int getThrottle();
    const int getRudder();
};

#endif

