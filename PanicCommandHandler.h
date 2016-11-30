#ifndef PanicCommandHandler_h
#define PanicCommandHandler_h

#include "Arduino.h"
#include "BaseCommandHandler.h"

#define PANIC_COMMAND_PAYLOAD_SIZE 1
#define DEFAULT_FORWARD_DELAY 50

class PanicCommandHandler: public BaseCommandHandler {
  private:
    bool panic;
    int delay = DEFAULT_FORWARD_DELAY;
  public:
    const static byte COMMAND_TYPE = 'p';
    bool canHandle(const byte commandType);
    int getPayloadSize();
    bool hasExecuted(byte payload[], const int payloadSize);
    const int getDelay();
    const bool isInPanic();
};

#endif
