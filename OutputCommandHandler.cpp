#include "OutputCommandHandler.h"

bool OutputCommandHandler::canHandle(const byte commandType) {
  return commandType == OutputCommandHandler::COMMAND_TYPE;
}

bool OutputCommandHandler::hasExecuted() {
  const int available = Serial.available();
  if (available >= OUTPUT_COMMAND_PAYLOAD_SIZE) {
    ailerons = Serial.read();
    elevator = Serial.read();
    throttle = Serial.read();
    rudder = Serial.read();
    return true;
  }
  return false;
}

const int OutputCommandHandler::getAilerons() {
  return ailerons;
}

const int OutputCommandHandler::getElevator() {
  return elevator;
}

const int OutputCommandHandler::getThrottle() {
  return guard.getThrottle(throttle);
}

const int OutputCommandHandler::getRudder() {
  return rudder;
}

