#ifndef ArmingCommandHandler_h
#define ArmingCommandHandler_h

#include "BaseCommandHandler.h"
#include "Blinker.h"
#include "ThrottleGuard.h"
#include "Globals.h"

class ArmingCommandHandler: public BaseCommandHandler {
  private:
    bool armed = false;
    ThrottleGuard &guard;
    byte receivedCommandType;
  public:
    const static byte ARM_COMMAND_TYPE = 'a';
    const static byte DISARM_COMMAND_TYPE = 'd';
    ArmingCommandHandler(ThrottleGuard &guard): guard(guard) {};
    bool canHandle(const byte commandType);
    int getPayloadSize();
    bool hasExecuted(byte payload[], const int payloadSize);
    const bool isArmed();
};

#endif
