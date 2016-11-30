#include "FlightController.h"

void FlightController::setAltitude(const short altitude) {
  this->altitude = altitude;
}

const short FlightController::getAltitude() {
  return altitude;
}

bool FlightController::setMode(const byte mode){
  switch (mode) {
    case FlightController::FLIGHT_MODE_RATE:
      this->mode = mode;
      return true;
    case FlightController::FLIGHT_MODE_FBW:
      this->mode = mode;
      return true;
    case FlightController::FLIGHT_MODE_RTH:
      this->mode = mode;
      return true;
    default:
      Serial.println(mode);
      Serial.println(FlightController::FLIGHT_MODE_RATE);
      Serial.println(FlightController::FLIGHT_MODE_FBW);
      Serial.println(FlightController::FLIGHT_MODE_RTH);
      return false;
  }
}

const byte FlightController::getMode() {
  return mode;
}

void FlightController::setLatitude(const float latitude) {
  this->latitude = latitude;
}

const float FlightController::getLatitude() {
  return latitude;
}

void FlightController::setLongitude(const float longitude) {
  this->longitude = longitude;
}

const float FlightController::getLongitude() {
  return longitude;
}

