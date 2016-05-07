#include "ServoController.h"

void ServoController::setup() {
  ailerons.attach(AIL_PIN, PWM_MIN, PWM_MAX);
  ailerons.write(DEFAULT_CHANNEL);

  elevator.attach(ELE_PIN, PWM_MIN, PWM_MAX);
  elevator.write(DEFAULT_CHANNEL);

  throttle.attach(THR_PIN, PWM_MIN, PWM_MAX);
  throttle.write(DEFAULT_THROTTLE);

  rudder.attach(RUD_PIN, PWM_MIN, PWM_MAX);
  rudder.write(DEFAULT_CHANNEL);
}

void ServoController::newLoop() {
  if (mode == RX) {
    setOutputFromRX();
  } else if (mode == STABILIZE) {
    
    setOutputFromStabilizator();
  }
}

void ServoController::setOutputFromRX() {
  // TODO Read data from RX and set the servo positions accordingly
}

void ServoController::setOutputFromStabilizator() {
  const byte aileronOutput = clip(outputHandler.getAilerons(), MIN_ANGLE, MAX_ANGLE);
  const byte elevatorOutput = clip(outputHandler.getElevator(), MIN_ANGLE, MAX_ANGLE);
  const byte throttleOutput = clip(outputHandler.getThrottle(), MIN_ANGLE, MAX_ANGLE);
  const byte rudderOutput = clip(outputHandler.getRudder(), MIN_ANGLE, MAX_ANGLE);
  #ifdef DEBUG
  Serial.print("AIL: ");
  Serial.print(aileronOutput);
  Serial.print(" ELE: ");
  Serial.print(elevatorOutput);
  Serial.print(" THR: ");
  Serial.print(throttleOutput);
  Serial.print(" RUD: ");
  Serial.println(rudderOutput);
  delay(100);
  #endif
  ailerons.write(clip(aileronOutput, 0, 180));
  elevator.write(clip(elevatorOutput, 0, 180));
  throttle.write(clip(throttleOutput, 0, 180));
  rudder.write(clip(rudderOutput, 0, 180));
}

const int ServoController::clip(const int input, const int min, const int max) {
  if (input > max) {
    return max;
  }
  if (input < min) {
    return min;
  }
  return input;
}

