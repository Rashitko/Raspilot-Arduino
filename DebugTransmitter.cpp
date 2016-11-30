#include "DebugTransmitter.h"

const  void DebugTransmitter::debugMessage(const String debugMessage) {
  #ifdef DEBUG_MESSAGES_ENABLED
  Serial.print(COMMAND_TYPE);
  Serial.println(debugMessage);
  #endif
}

