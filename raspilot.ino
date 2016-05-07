#include <Servo.h>

#include "Globals.h"

#include "Blinker.h"
#include "CommandReceiver.h"
#include "StartCommandHandler.h"
#include "ArmingCommandHandler.h"
#include "ThrottleGuard.h"
#include "RCForwarder.h"
#include "OutputCommandHandler.h"
#include "ServoController.h"

Blinker blinker;
StartCommandHandler startHandler(blinker);
ThrottleGuard throttleGuard(blinker);
RCForwarder forwarder(throttleGuard);
ArmingCommandHandler armingHandler(throttleGuard);
OutputCommandHandler outputHandler(throttleGuard);
BaseCommandHandler *handlers[] = {&armingHandler, &outputHandler};
CommandReceiver cmdReceiver(startHandler, handlers);
ServoController servoController(outputHandler);

void setup() {
  Serial.begin(9600);
  blinker.setup();
  servoController.setup();
}

void loop() {
  blinker.newLoop();
  cmdReceiver.newLoop();
  #ifndef SUPPRESS_RX_FORWARD
  if (startHandler.isStarted()) {
    forwarder.newLoop();
  }
  #endif
  #ifndef SUPPRESS_SERVO_OUTPUT
  servoController.newLoop();
  #endif
}
