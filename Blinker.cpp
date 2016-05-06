#include "Blinker.h"

void Blinker::setup(){
  pinMode(LED_PIN, OUTPUT);
  pinMode(RX_LED_PIN, OUTPUT);
}

void Blinker::newLoop(){
  if (rxLedOn) {
    setRxLedStatus(rxLedOn);
  }
}

void Blinker::setLedStatus(const bool light){
  const int status = light ? HIGH : LOW;
  digitalWrite(LED_PIN, status);
}

void Blinker::setRxLedStatus(const bool light){
  const int status = light ? HIGH : LOW;
  rxLedOn = light;
  digitalWrite(RX_LED_PIN, status);
}

