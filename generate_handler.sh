#!/usr/bin/env bash

NAME=${NAME}
HEADER_FILE=${NAME}.h
SOURCE_FILE=${NAME}.cpp

if [[ -a ${HEADER_FILE} ]]; then
  echo ${HEADER_FILE} "already exists."
  exit;
fi
if [[ -a ${SOURCE_FILE} ]]; then
  echo ${SOURCE_FILE} "already exists."
  exit;
fi

cat << EOF > ${HEADER_FILE}
#ifndef ${NAME}_h
#define ${NAME}_h

#include "Arduino.h"

#include "BaseCommandHandler.h"
#include "ConversionUtils.h"

class ${NAME}: public BaseCommandHandler {
  private:
    static const byte COMMAND_TYPE = '${TYPE}';
    static const byte PAYLOAD_SIZE = ${SIZE};
  public:
    bool canHandle(const byte commandType);
    int getPayloadSize();
    bool hasExecuted(byte payload[], const int payloadSize);
    void executeConfirm();
};

#endif
EOF

cat << EOF > ${SOURCE_FILE}
#include "${NAME}.h"

bool ${NAME}::canHandle(const byte commandType) {
  return commandType == COMMAND_TYPE;
}
int ${NAME}::getPayloadSize() {
  return PAYLOAD_SIZE;
}
bool ${NAME}::hasExecuted(byte payload[], const int payloadSize) {
  return false;
}

void ${NAME}::executeConfirm() {

}

EOF
