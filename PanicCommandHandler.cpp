#include "PanicCommandHandler.h"

bool PanicCommandHandler::canHandle(const byte commandType){
  return commandType == PanicCommandHandler::COMMAND_TYPE;
}
int PanicCommandHandler::getPayloadSize(){
  return PANIC_COMMAND_PAYLOAD_SIZE;  
}

bool PanicCommandHandler::hasExecuted(byte payload[], const int payloadSize) {
  if (payloadSize == PANIC_COMMAND_PAYLOAD_SIZE) {
    delay = payload[0];
    return true;
  }
  return false;
}

const int PanicCommandHandler::getDelay() {
  return delay;
}

const bool PanicCommandHandler::isInPanic() {
  return panic;
}

