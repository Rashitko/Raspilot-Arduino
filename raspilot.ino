#include "Globals.h"

#include "Blinker.h"
#include "CommandReceiver.h"
#include "StartCommandHandler.h"
#include "ArmingCommandHandler.h"
#include "ThrottleGuard.h"
#include "RCForwarder.h"
#include "PanicCommandHandler.h"
#include "FlightController.h"
#include "FlightModeCommandHandler.h"
#include "AltitudeCommandHandler.h"
#include "LocationCommandHandler.h"
#include "HeadingCommandHandler.h"

Blinker blinker;
ThrottleGuard throttleGuard(blinker);
PanicCommandHandler panicHandler;
RCForwarder forwarder(throttleGuard, panicHandler);

StartCommandHandler startHandler(blinker);
ArmingCommandHandler armingHandler(throttleGuard);

FlightController flightController;
LocationCommandHandler locationCmdHandler(flightController);
AltitudeCommandHandler altitudeCmdHandler(flightController);
FlightModeCommandHandler flightCmdHandler(flightController);

BaseCommandHandler *handlers[] = {&armingHandler, &panicHandler, &flightCmdHandler, &altitudeCmdHandler, &locationCmdHandler};
CommandReceiver cmdReceiver(startHandler, handlers);

void setup() {
  Serial.begin(BAUDRATE);
  blinker.setup();
}

void loop() {
  blinker.newLoop();
  cmdReceiver.newLoop();
#ifndef SUPPRESS_RX_FORWARD
  if (startHandler.isStarted()) {
    forwarder.newLoop();
  }
#endif
}
