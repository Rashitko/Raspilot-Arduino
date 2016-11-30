#ifndef LocationCommandHandler_h
#define LocationCommandHandler_h

#include "Arduino.h"

#include "BaseCommandHandler.h"
#include "FlightController.h"
#include "ConversionUtils.h"

class LocationCommandHandler: public BaseCommandHandler {
  private:
    const static byte COMMAND_TYPE = 'l';
    const static byte PAYLOAD_SIZE = 8;
    FlightController flightController;
  public:
    LocationCommandHandler(FlightController &flightController): flightController(flightController) {}
    bool canHandle(const byte commandType);
    int getPayloadSize();
    bool hasExecuted(byte payload[], const int payloadSize);
    void executeConfirm();
};

#endif
