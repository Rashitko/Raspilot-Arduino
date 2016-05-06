#include "ThrottleGuard.h"

void ThrottleGuard::arm(){
  armed = true;
  blinker.setRxLedStatus(ON);
}
void ThrottleGuard::disarm(){
  armed = false;
  blinker.setRxLedStatus(OFF);
}
int ThrottleGuard::getThrottle(const int rxThrottle){
  if (armed) {
    return rxThrottle;
  }
  return NOT_ARMED_THROTTLE;
}

