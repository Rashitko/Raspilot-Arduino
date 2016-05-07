#ifndef ServoController_h
#define ServoController_h

#include "Arduino.h"
#include "Globals.h"
#include <Servo.h>
#include "OutputCommandHandler.h"

#define AIL_PIN 4
#define ELE_PIN 5
#define THR_PIN 6
#define RUD_PIN 7

#define PWM_MIN 1000
#define PWM_MAX 2000
#define MIN_ANGLE 0
#define MAX_ANGLE 180

typedef enum {
  RX, STABILIZE
} FlightMode;

class ServoController {
  private:
    Servo ailerons;
    Servo elevator;
    Servo throttle;
    Servo rudder;
    FlightMode mode = STABILIZE;
    OutputCommandHandler &outputHandler;
    void setOutputFromRX();
    void setOutputFromStabilizator();
    const int clip(const int input, const int min, const int max);
  public:
    ServoController(OutputCommandHandler &outputHandler): outputHandler(outputHandler) {};
    void setup();
    void newLoop();
};

#endif
