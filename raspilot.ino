#include "Blinker.h"
#include "CommandReceiver.h"
#include "StartCommandHandler.h"
#include "ArmingCommandHandler.h"
#include "ThrottleGuard.h"
#include "RCForwarder.h"

Blinker blinker;
StartCommandHandler startHandler(blinker);
ThrottleGuard throttleGuard(blinker);
RCForwarder forwarder(throttleGuard);
ArmingCommandHandler armingHandler(throttleGuard);
CommandReceiver cmdReceiver(blinker, startHandler, armingHandler);

void setup() {
  blinker.setup();
}

void loop() {
  blinker.newLoop();
  cmdReceiver.newLoop();
  if (startHandler.isStarted()) {
    forwarder.newLoop();
  }
}
