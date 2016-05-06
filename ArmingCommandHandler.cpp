#include "ArmingCommandHandler.h"
bool ArmingCommandHandler::canHandle(const byte commandType){
  if (commandType == ArmingCommandHandler::ARM_COMMAND_TYPE || commandType == ArmingCommandHandler::DISARM_COMMAND_TYPE) {
    receivedCommandType = commandType;
    return true;
  }
  return false;
}

bool ArmingCommandHandler::hasExecuted(){
  if (receivedCommandType== ArmingCommandHandler::ARM_COMMAND_TYPE) {
    armed = true;
    guard.arm();
    Serial.write(ArmingCommandHandler::ARM_COMMAND_TYPE);
    return true;
  }
  if (receivedCommandType== ArmingCommandHandler::DISARM_COMMAND_TYPE) {
    armed = false;
    guard.disarm();
    Serial.write(ArmingCommandHandler::DISARM_COMMAND_TYPE);
    return true;
  }
  return false;
}

const bool ArmingCommandHandler::isArmed(){
  return armed;
}

