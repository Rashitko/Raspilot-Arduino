#ifndef HeadingCommandHandler_h
#define HeadingCommandHandler_h

#include "Arduino.h"

#include "BaseCommandHandler.h"
#include "ConversionUtils.h"
#include "FlightController.h"

class HeadingCommandHandler: public BaseCommandHandler {
  private:
    static const byte CURRENT_HEADING_COMMAND_TYPE = 'h';
    static const byte REQUIRED_HEADING_COMMAND_TYPE = 'h';
    static const byte PAYLOAD_SIZE = 2;
    byte receivedCommandType = 0;
    FlightController flightController;
  public:
    HeadingCommandHandler(FlightController &flightController): flightController(flightController) {}
    bool canHandle(const byte commandType);
    int getPayloadSize();
    bool hasExecuted(byte payload[], const int payloadSize);
    void executeConfirm();
};

#endif
