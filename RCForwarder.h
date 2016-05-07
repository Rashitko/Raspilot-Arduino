#ifndef RCForwarder_h
#define RCForwarder_h

#include "Arduino.h"
#include "Globals.h"
#include "ThrottleGuard.h"

#define DEFAULT_DELAY 100

class RCForwarder {
  private:
    byte ailerons = DEFAULT_CHANNEL;
    byte elevator = DEFAULT_CHANNEL;
    byte throttle = DEFAULT_THROTTLE;
    byte rudder = DEFAULT_CHANNEL;
    byte aux1 = DEFAULT_CHANNEL;
    byte aux2 = DEFAULT_CHANNEL;
    ThrottleGuard &guard;
    unsigned long prevSentStamp = 0;
    unsigned long delay = DEFAULT_DELAY;
    const void printChannels();
   public:
    const static byte COMMAND_TYPE = 'f';
    RCForwarder(ThrottleGuard &guard):guard(guard) {};
    void newLoop();
    void setDelay(const int newDelay);
};

#endif
