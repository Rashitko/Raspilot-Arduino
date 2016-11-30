#ifndef AltitudeCommandHandler_h
#define AltitudeCommandHandler_h

#include "Arduino.h"

#include "BaseCommandHandler.h"
#include "FlightController.h"
#include "ConversionUtils.h"

class AltitudeCommandHandler: public BaseCommandHandler {
  private:
    static const byte ALTITUDE_COMMAND_TYPE = 'h';
    static const byte ALTITUDE_COMMAND_SIZE = 2;
    short altitude = 0;
    const FlightController flightController;
  public:
    AltitudeCommandHandler(FlightController &flightController): flightController(flightController) {}
    bool canHandle(const byte commandType);
    int getPayloadSize();
    bool hasExecuted(byte payload[], const int payloadSize);
    void executeConfirm();
    const bool isArmed();
};

#endif
