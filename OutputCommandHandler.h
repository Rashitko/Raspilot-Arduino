#ifndef OutputCommandHandler_h
#define OutputCommandHandler_h

#include "Arduino.h"
#include "BaseCommandHandler.h"
#include "Globals.h"
#include "ThrottleGuard.h"

#define OUTPUT_COMMAND_PAYLOAD_SIZE 4
#define PAYLOAD_AIL_POSITION 0
#define PAYLOAD_ELE_POSITION 1
#define PAYLOAD_THR_POSITION 2
#define PAYLOAD_RUD_POSITION 3

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
    int getPayloadSize();
    bool hasExecuted(byte payload[], const int payloadSize);
    const int getAilerons();
    const int getElevator();
    const int getThrottle();
    const int getRudder();
};

#endif

