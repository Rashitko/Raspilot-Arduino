#ifndef OutputCommandHandler_h
#define OutputCommandHandler_h

#include "Arduino.h"
#include "BaseCommandHandler.h"
#include "Globals.h"
#include "ThrottleGuard.h"

#define OUTPUT_COMMAND_PAYLOAD_SIZE 4

class OutputCommandHandler: public BaseCommandHandler {
  private:
    ThrottleGuard &guard;
    byte ailerons = DEFAULT_CHANNEL;
    byte elevator = DEFAULT_CHANNEL;
    byte throttle = DEFAULT_CHANNEL;
    byte rudder = DEFAULT_CHANNEL;

  public:
    OutputCommandHandler(ThrottleGuard &guard): guard(guard) {};
    const static byte COMMAND_TYPE = 'o';
    bool canHandle(const byte commandType);
    bool hasExecuted();
    const int getAilerons();
    const int getElevator();
    const int getThrottle();
    const int getRudder();
};

#endif

