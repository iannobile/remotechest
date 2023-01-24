#ifndef _REMOTECHEST_H
#define _REMOTECHEST_H
#define VERSION 0.1
#define SOLENOID0_PIN D1    // Solenoid 1 input pin
#define LOG_STATUS true
#define WARMUP 10000         // Allow the system time to settle after initializing everything.
/* Function and class defintions. */
void setup();
void loop();
void myHandler(const char *event, const char *data);
int blinkled(int ledColor, int pause);
int triggersolenoid(int solenoid, int direction);
#endif /* end of include guard:  */