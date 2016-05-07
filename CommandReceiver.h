#ifndef CommandReceiver_h
#define CommandReceiver_h

#include "Arduino.h"
#include "Globals.h"
#include "BaseCommandHandler.h"
#include "StartCommandHandler.h"

#define COMMAND_RECEIVE_TIMEOUT 100

typedef enum {
  STATE_AVAITING_COMMAND, STATE_RECEIVING_COMMAND
} InputState;

class CommandReceiver {
  private:
    StartCommandHandler &startHandler;
    BaseCommandHandler *handlers[HANDLERS_COUNT];
    BaseCommandHandler *receivingHandler = NULL;
    InputState state = STATE_AVAITING_COMMAND;
    unsigned long receiveStart = millis();
    void printState();
    void handleCommandHeader(const byte commandType);
  public:
    CommandReceiver(StartCommandHandler &startHandler, BaseCommandHandler *cmdHandlers[HANDLERS_COUNT]);
    void newLoop();
};

#endif
