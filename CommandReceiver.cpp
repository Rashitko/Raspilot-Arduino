#include "CommandReceiver.h"

void CommandReceiver::printState() {
  Serial.print("State ");
  Serial.print(this->state);
  Serial.println();
}

void CommandReceiver::handleCommandHeader(const byte commandType) {
  if (startHandler.canHandle(commandType)) {
    state = STATE_RECEIVING_COMMAND;
    receivingHandler = START_HANDLER;
  } else if (startHandler.isStarted()) {
    if (armingHandler.canHandle(commandType)) {
      state = STATE_RECEIVING_COMMAND;
      receivingHandler = ARMING_HANDLER;
    } else {
      Serial.print("Received ");
      Serial.print(commandType);
      Serial.println();
    }
  }
}

void CommandReceiver::newLoop() {
  const int available = Serial.available();
  if (available > 0) {
    if (state == STATE_AVAITING_COMMAND) {
      const byte commandType = Serial.read();
      handleCommandHeader(commandType);
    }
    if (state == STATE_RECEIVING_COMMAND) {
      bool executed = false;
      if (receivingHandler == START_HANDLER) {
        executed = startHandler.hasExecuted();
      } else if (receivingHandler == ARMING_HANDLER) {
        executed = armingHandler.hasExecuted();
      }
      if (executed) {
        state = STATE_AVAITING_COMMAND;
        receivingHandler == NONE;
      }
    }
  }
}

