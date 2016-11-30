#include "HeadingCommandHandler.h"

bool HeadingCommandHandler::canHandle(const byte commandType) {
  return commandType == COMMAND_TYPE;
}
int HeadingCommandHandler::getPayloadSize() {
  return PAYLOAD_SIZE;
}
bool HeadingCommandHandler::hasExecuted(byte payload[], const int payloadSize) {
  return false;
}

void HeadingCommandHandler::executeConfirm() {

}

