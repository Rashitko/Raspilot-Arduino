#ifndef HeadingCommandHandler_h
#define HeadingCommandHandler_h

#include "Arduino.h"

#include "BaseCommandHandler.h"
#include "ConversionUtils.h"

class HeadingCommandHandler: public BaseCommandHandler {
  private:
    static const byte COMMAND_TYPE = 'h';
    static const byte PAYLOAD_SIZE = 2;
  public:
    bool canHandle(const byte commandType);
    int getPayloadSize();
    bool hasExecuted(byte payload[], const int payloadSize);
    void executeConfirm();
};

#endif
