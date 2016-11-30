#ifndef Globals_h
#define Globals_h

#define DEFAULT_CHANNEL 90
#define DEFAULT_THROTTLE 0

// #############################
// ########## GENERAL ##########
// #############################
// Serial baudrate
#define BAUDRATE 9600

// ###############################
// ########## DEBUGGING ##########
// ###############################
// enables transmission of the debug messages
#define DEBUG_MESSAGES_ENABLED
// invoke executeConfirm method of command handlers after execution
#define CONFIRM_COMMANDS
// when SUPPRESS_RX_FORWARD is defined, RX will not be forwarded over Serial, used mainly to clear the debug Serial output
#define SUPPRESS_RX_FORWARD
// when SUPPRESS_SERVO_OUTPUT is defined, Servos will not be controlled
#define SUPPRESS_SERVO_OUTPUT 

// ##############################
// ########## HANDLERS ##########
// ##############################
// Number of handlers used by the CommandReceiver, StartCommandHandler is not counted here
#define HANDLERS_COUNT 6

#endif
