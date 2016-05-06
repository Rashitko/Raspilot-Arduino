#ifndef Blinker_h
#define Blinker_h

#include "Arduino.h"
#define LED_PIN 13
#define RX_LED_PIN 17
#define ON true
#define OFF false

class Blinker {
  private:
    bool ledOn = false;
    bool rxLedOn = false;
  public:
    void setup();
    void newLoop();
    void setLedStatus(const bool light);
    void setRxLedStatus(const bool light);
};


#endif
