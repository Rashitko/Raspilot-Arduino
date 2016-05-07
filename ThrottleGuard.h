#ifndef ThrottleGuard_h
#define ThrottleGuard_h

#include "Arduino.h"
#include "Blinker.h"

#define NOT_ARMED_THROTTLE 0;

class ThrottleGuard {
  private:
    bool armed;
    Blinker &blinker;
  public:
    ThrottleGuard(Blinker &blinker):blinker(blinker){};
    void arm();
    void disarm();
    int getThrottle(const int rxThrottle);
};

#endif
