#ifndef RCForwarder_h
#define RCForwarder_h

#include "Arduino.h"
#include "Globals.h"
#include "ThrottleGuard.h"

#define DEFAULT_DELAY 100
#define DEFAULT_CHANNEL 1500
#define DEFAULT_THROTTLE 1000

class RCForwarder {
  private:
    int ailerons = DEFAULT_CHANNEL;
    int elevator = DEFAULT_CHANNEL;
    int throttle = DEFAULT_THROTTLE;
    int rudder = DEFAULT_CHANNEL;
    int aux1 = DEFAULT_CHANNEL;
    int aux2 = DEFAULT_CHANNEL;
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
