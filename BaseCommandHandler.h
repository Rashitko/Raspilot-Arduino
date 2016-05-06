#ifndef BaseCommandHandler_h
#define BaseCommandHandler_h

#include "Arduino.h"

class BaseCommandHandler {
  public:
    virtual bool canHandle(const byte commandType) = 0;
    virtual bool hasExecuted() = 0;
};

#endif
