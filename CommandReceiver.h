#ifndef CommandReceiver_h
#define CommandReceiver_h

#include "Arduino.h"
#include "Blinker.h"
#include "BaseCommandHandler.h"
#include "StartCommandHandler.h"

typedef enum {
  STATE_AVAITING_COMMAND, STATE_RECEIVING_COMMAND
} InputState;

typedef enum {
  START_HANDLER, ARMING_HANDLER, NONE
} ReceivingHandler;

class CommandReceiver {
  private:
    Blinker &blinker;
    StartCommandHandler &startHandler;
    BaseCommandHandler &armingHandler;
    InputState state = STATE_AVAITING_COMMAND;
    ReceivingHandler receivingHandler = NONE;
    void printState();
    void handleCommandHeader(const byte commandType);
  public:
    CommandReceiver(Blinker &blinker, StartCommandHandler &startHandler, BaseCommandHandler &armingHandler):blinker(blinker), startHandler(startHandler), armingHandler(armingHandler){};
    void newLoop();
};

#endif
