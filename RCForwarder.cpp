#include "RCForwarder.h"

const void RCForwarder::printChannels() {
  Serial.print("RC: ail: ");
  Serial.print(ailerons);
  Serial.print(" ele: ");
  Serial.print(elevator);
  Serial.print(" thr: ");
  Serial.print(guard.getThrottle(throttle));
  Serial.print(" rud: ");
  Serial.print(rudder);
  Serial.print(" ax1: ");
  Serial.print(aux1);
  Serial.print(" ax2: ");
  Serial.println(aux2);
}

void RCForwarder::newLoop() {
  const unsigned long currentTime = millis();
  const unsigned long timeDiff = currentTime - prevSentStamp;
  if (timeDiff >= panicHandler.getDelay()) {
    #ifdef DEBUG
    printChannels();
    #endif
    Serial.write(RCForwarder::COMMAND_TYPE);
    Serial.write(ailerons);
    Serial.write(elevator);
    Serial.write(guard.getThrottle(throttle));
    Serial.write(rudder);
    Serial.write(aux1);
    Serial.write(aux2);
    prevSentStamp = currentTime;
  }
}
