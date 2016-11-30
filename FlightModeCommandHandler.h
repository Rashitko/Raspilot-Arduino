#ifndef FlightModeCommandHandler_h
#define FlightModeCommandHandler_H

#include "Arduino.h"

#include "BaseCommandHandler.h"
#include "FlightController.h"

class FlightModeCommandHandler: public BaseCommandHandler {
  private:
    const static byte REQUEST_COMMAND_TYPE = 'm';
    const static byte MODE_CHANGE_COMMAND_TYPE = 'M';
    const static byte REQUEST_COMMAND_SIZE = 0;
    const static byte MODE_CHANGE_COMMAND_SIZE = 1;
    
    byte mode = FlightController::FLIGHT_MODE_RATE;
    byte receivedCommandType;
    FlightController &flightController;
  public:
    FlightModeCommandHandler(FlightController &flightController): flightController(flightController) {};
    bool canHandle(const byte commandType);
    int getPayloadSize();
    bool hasExecuted(byte payload[], const int payloadSize);
    const bool isArmed();
};

#endif
