#include "StartCommandHandler.h"

bool StartCommandHandler::canHandle(const byte commandType) {
  return commandType == StartCommandHandler::COMMAND_TYPE;
}

int StartCommandHandler::getPayloadSize() {
  return 0;
}

bool StartCommandHandler::hasExecuted(byte payload[], const int payloadSize) {
  blinker.setLedStatus(ON);
  started = true;
  Serial.write(StartCommandHandler::COMMAND_TYPE);
  return true;
}

const bool StartCommandHandler::isStarted() {
  return started;
}

