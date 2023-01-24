/*
 * Project remotechest
 * Description:
 * Author: Ian Nobile
 * Date: 2022-09-01
 */
#include "remotechest.h"
int counter = 0;
SerialLogHandler logHandler; // Use primary serial over USB interface for logging output
// setup() runs once, when the device is first turned on.
void setup() {
  Log.info("Remote Chest version %lf\nSystem version: %s", VERSION, (const char*)System.version());
  pinMode(SOLENOID0_PIN, OUTPUT); 
  Log.info("Testing solenoid on D1");
  digitalWrite(SOLENOID0_PIN, HIGH);
  delay(WARMUP);
  digitalWrite(SOLENOID0_PIN, LOW);
  Particle.subscribe("action", myHandler);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
	Log.debug("Waiting for input");

}


int i = 0;

void myHandler(const char *event, const char *data)
// Handler for subscription to the event queue.
{
  i++;
  Log.info("%d: event=%s data=%s", i, event, (data ? data : "NULL"));
  if (strcmp(data,"open")==0) {
    blinkled(RGB_COLOR_YELLOW, 100);
    triggersolenoid(SOLENOID0_PIN, 0);
  }else if (strcmp(data,"closed")==0) {
    blinkled(RGB_COLOR_RED, 100);
    triggersolenoid(SOLENOID0_PIN, 1);
}
}


int blinkled(int ledColor, int pause){
  // Flash the onboard LED the passed color and wait the passed value to turn it off again.
  LEDStatus blink(ledColor, LED_PATTERN_BLINK, LED_SPEED_NORMAL, LED_PRIORITY_IMPORTANT);
  blink.setActive(true);
  delay(pause);
  blink.setActive(false);
  // LEDStatus blinkGreen(RGB_COLOR_GREEN, LED_PATTERN_BLINK, LED_SPEED_NORMAL, LED_PRIORITY_IMPORTANT);

  return 0;
}

int triggersolenoid(int solenoid, int direction){
  // Trigger the passed solenoid, reversing direction if the solenoid is a push/pull type.
  // int solenoid: Passed solenoid pin
  // int direction: direction of push/pull solenoid: 0 = pull, 1 = push
  blinkled(RGB_COLOR_WHITE, 500);
  switch(direction) {
    case 0:
      Log.info("Pulling solenoid %d", solenoid);
      digitalWrite(solenoid, HIGH);
      delay(60000);
      Log.info("Pushing solenoid %d", solenoid);
      digitalWrite(solenoid, LOW);
      break;
    case 1:
      Log.info("Pushing solenoid %d", solenoid);
      digitalWrite(solenoid, LOW);
      break;
    default:
      Log.info("Pulling solenoid %d", solenoid);
      digitalWrite(solenoid, HIGH);
  }
  blinkled(RGB_COLOR_ORANGE, 500);
  // digitalWrite(solenoid, LOW);

  return 0;
}