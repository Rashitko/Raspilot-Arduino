#include "Globals.h"

#include "Blinker.h"
#include "CommandReceiver.h"
#include "StartCommandHandler.h"
#include "ArmingCommandHandler.h"
#include "ThrottleGuard.h"
#include "RCForwarder.h"
#include "OutputCommandHandler.h"

Blinker blinker;
StartCommandHandler startHandler(blinker);
ThrottleGuard throttleGuard(blinker);
RCForwarder forwarder(throttleGuard);
ArmingCommandHandler armingHandler(throttleGuard);
OutputCommandHandler outputHandler;
BaseCommandHandler *handlers[] = {&armingHandler, &outputHandler};
CommandReceiver cmdReceiver(startHandler, handlers);

void setup() {
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
