#include "OutputCommandHandler.h"

bool OutputCommandHandler::canHandle(const byte commandType) {
  return commandType == OutputCommandHandler::COMMAND_TYPE;
}

int OutputCommandHandler::getPayloadSize() {
  return OUTPUT_COMMAND_PAYLOAD_SIZE;
}

bool OutputCommandHandler::hasExecuted(byte payload[], const int payloadSize) {
  if (payloadSize == OUTPUT_COMMAND_PAYLOAD_SIZE) {
    ailerons = payload[PAYLOAD_AIL_POSITION];
    elevator = payload[PAYLOAD_ELE_POSITION];
    throttle = payload[PAYLOAD_THR_POSITION];
    rudder = payload[PAYLOAD_RUD_POSITION];
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

