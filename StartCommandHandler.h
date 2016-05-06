#ifndef StartCommandHandler_h
#define StartCommandHandler_h

#include "BaseCommandHandler.h"
#include "Blinker.h"

class StartCommandHandler: public BaseCommandHandler {
  private:
    bool started = false;
    Blinker &blinker;
  public:
    const static byte COMMAND_TYPE = 's';
    StartCommandHandler(Blinker &blinker): blinker(blinker) {};
    bool canHandle(const byte commandType);
    bool hasExecuted();
    const bool isStarted();
};

#endif
