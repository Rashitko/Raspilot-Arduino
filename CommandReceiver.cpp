#include "CommandReceiver.h"

CommandReceiver::CommandReceiver(StartCommandHandler &startHandler, BaseCommandHandler *cmdHandlers[HANDLERS_COUNT]): startHandler(startHandler) {
  for (int i = 0; i < HANDLERS_COUNT; i++) {
    handlers[i] = cmdHandlers[i];
  }
}

void CommandReceiver::printState() {
  Serial.print("State ");
  Serial.print(this->state);
  Serial.println();
}

void CommandReceiver::handleCommandHeader(const byte commandType) {
  bool wasFound = false;
  if (startHandler.canHandle(commandType)) {
    state = STATE_RECEIVING_COMMAND;
    receivingHandler = &startHandler;
    receiveStart = millis();
    wasFound = true;
  } else if (startHandler.isStarted()) {
    for (int i = 0; i < HANDLERS_COUNT; i++) {
      if (handlers[i]->canHandle(commandType)) {
        receivingHandler = handlers[i];
        state = STATE_RECEIVING_COMMAND;
        receiveStart = millis();
        wasFound = true;
        break;
      }
    }
  }
  if (!wasFound) {
    Serial.write('!');
    Serial.write(commandType);
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
      const unsigned long currentTime = millis();
      const unsigned long timeDiff = currentTime - receiveStart;
      if (timeDiff >= COMMAND_RECEIVE_TIMEOUT) {
        state = STATE_AVAITING_COMMAND;
        receivingHandler == NULL;
        Serial.print("!");
      } else {
        const int available = Serial.available();
        const int requestedPayloadSize = receivingHandler->getPayloadSize();
        if (available >= requestedPayloadSize) {
          byte payload[requestedPayloadSize];
          Serial.readBytes(payload, requestedPayloadSize);
          bool executed = receivingHandler->hasExecuted(payload, requestedPayloadSize);
          if (executed) {
            #ifdef CONFIRM_COMMANDS
            receivingHandler->executeConfirm();
            #endif
            state = STATE_AVAITING_COMMAND;
            receivingHandler == NULL;
          }
        }
      }
    }
  }
}

