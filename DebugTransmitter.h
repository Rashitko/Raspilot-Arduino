#ifndef DebugTransmitter_h
#define DebugTransmitter_h

#include "Arduino.h"

class DebugTransmitter {
  private:
    const static byte COMMAND_TYPE = 'D';
  public:
    const static void debugMessage(const String message);
};

#endif
