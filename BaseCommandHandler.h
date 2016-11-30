#ifndef BaseCommandHandler_h
#define BaseCommandHandler_h

#include "Arduino.h"

class BaseCommandHandler {
  public:
    virtual bool canHandle(const byte commandType) = 0;
    virtual int getPayloadSize() = 0;
    virtual bool hasExecuted(byte payload[], const int payloadSize) = 0;
    virtual void executeConfirm() {
      
    };
};

#endif
