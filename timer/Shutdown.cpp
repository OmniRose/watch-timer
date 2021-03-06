#include "Arduino.h"
#include "Shutdown.h"
#include <avr/sleep.h>

// http://playground.arduino.cc/Learning/ArduinoSleepCode

Shutdown::Shutdown() {
}

void wake_up () {
}

void Shutdown::suspend() {
    Serial.println("OFF!");

    // FIXME - add code here to powerdown the rest of the system, eg set pins to
    // input etc.

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    attachInterrupt(WAKE_FROM_SLEEP_INTERRUPT, wake_up, LOW);

    // Serial.println("to sleep");
    // delay(500); // send chars to serial.

    sleep_mode();

    // Timer is now asleep. Upon waking code will continue exectuing.

    sleep_disable();
    detachInterrupt(WAKE_FROM_SLEEP_INTERRUPT);

    // Serial.println("awake");

    // FIXME - add code here to powerup the rest of the system, undo the steps
    // taken above before sleeping.

}
