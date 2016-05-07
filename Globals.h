#ifndef Globals_h
#define Globals_h

#define DEFAULT_CHANNEL 90
#define DEFAULT_THROTTLE 0

#define DEBUG

// when SUPPRESS_RX_FORWARD is defined, RX will not be forwarded over Serial, used mainly to clear the debug Serial output
#define SUPPRESS_RX_FORWARD
// when SUPPRESS_SERVO_OUTPUT is defined, Servos will not be controlled
//#define SUPPRESS_SERVO_OUTPUT

// Number of hanlders used by the CommandReceiver
#define HANDLERS_COUNT 2

#endif
