#ifndef RCForwarder_h
#define RCForwarder_h

#include "Arduino.h"
#include "Globals.h"
#include "ThrottleGuard.h"
#include "PanicCommandHandler.h"

class RCForwarder {
  private:
    byte ailerons = DEFAULT_CHANNEL;
    byte elevator = DEFAULT_CHANNEL;
    byte throttle = DEFAULT_THROTTLE;
    byte rudder = DEFAULT_CHANNEL;
    byte aux1 = DEFAULT_CHANNEL;
    byte aux2 = DEFAULT_CHANNEL;
    ThrottleGuard &guard;
    PanicCommandHandler &panicHandler;
    unsigned long prevSentStamp = 0;
    const void printChannels();
   public:
    const static byte COMMAND_TYPE = 'f';
    RCForwarder(ThrottleGuard &guard, PanicCommandHandler &panicHandler):guard(guard), panicHandler(panicHandler) {};
    void newLoop();
};

#endif
