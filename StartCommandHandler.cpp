#include "StartCommandHandler.h"

bool StartCommandHandler::canHandle(const byte commandType) {
  return commandType == StartCommandHandler::COMMAND_TYPE;
}

bool StartCommandHandler::hasExecuted() {
  blinker.setLedStatus(ON);
  started = true;
  Serial.write(StartCommandHandler::COMMAND_TYPE);
  return true;
}

const bool StartCommandHandler::isStarted() {
  return started;
}

