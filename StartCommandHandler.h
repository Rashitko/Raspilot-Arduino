#ifndef StartCommandHandler_h
#define StartCommandHandler_h

#include "BaseCommandHandler.h"
#include "Blinker.h"
#include "Globals.h"

class StartCommandHandler: public BaseCommandHandler {
  private:
    bool started = false;
    Blinker &blinker;
  public:
    const static byte COMMAND_TYPE = 's';
    StartCommandHandler(Blinker &blinker): blinker(blinker) {};
    bool canHandle(const byte commandType);
    int getPayloadSize();
    bool hasExecuted(byte payload[], const int payloadSize);
    const bool isStarted();
};

#endif
