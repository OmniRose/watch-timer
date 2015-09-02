#include "Arduino.h"
#include "Display.h"

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

#define SEGMENT_ON  LOW
#define SEGMENT_OFF HIGH

Display::Display() {
  pinMode(PIN_DISPLAY_SEGMENT_A, OUTPUT);
  pinMode(PIN_DISPLAY_SEGMENT_B, OUTPUT);
  pinMode(PIN_DISPLAY_SEGMENT_C, OUTPUT);
  pinMode(PIN_DISPLAY_SEGMENT_D, OUTPUT);
  pinMode(PIN_DISPLAY_SEGMENT_E, OUTPUT);
  pinMode(PIN_DISPLAY_SEGMENT_F, OUTPUT);
  pinMode(PIN_DISPLAY_SEGMENT_G, OUTPUT);
  pinMode(PIN_DISPLAY_SEGMENT_COLON, OUTPUT);

  pinMode(PIN_DISPLAY_DIGIT_1, OUTPUT);
  pinMode(PIN_DISPLAY_DIGIT_2, OUTPUT);
  pinMode(PIN_DISPLAY_DIGIT_3, OUTPUT);
  pinMode(PIN_DISPLAY_DIGIT_4, OUTPUT);

  digitalWrite(PIN_DISPLAY_SEGMENT_COLON, SEGMENT_ON);
}

void Display::displayTime(int toDisplay) {

  long beginTime = millis();

  int minutes = toDisplay / 60;
  int seconds = toDisplay % 60;
  int digitToDisplay = 0;

  for(int digit = 4 ; digit > 0 ; digit--) {

    //Turn on a digit for a short amount of time
    switch(digit) {
      case 1:
        digitalWrite(PIN_DISPLAY_DIGIT_1, DIGIT_ON);
        digitToDisplay = minutes / 10 % 10;
        break;
      case 2:
        digitalWrite(PIN_DISPLAY_DIGIT_2, DIGIT_ON);
        digitToDisplay = minutes % 10;
        break;
      case 3:
        digitalWrite(PIN_DISPLAY_DIGIT_3, DIGIT_ON);
        digitToDisplay = seconds / 10;
        break;
      case 4:
        digitalWrite(PIN_DISPLAY_DIGIT_4, DIGIT_ON);
        digitToDisplay = seconds % 10;
        break;
    }

    //Turn on the right segments for this digit
    _lightNumber(digitToDisplay);

    delayMicroseconds(DISPLAY_BRIGHTNESS);
    //Display digit for fraction of a second (1us to 5000us, 500 is pretty good)

    //Turn off all segments
    _lightNumber(10);

    //Turn off all digits
    digitalWrite(PIN_DISPLAY_DIGIT_1, DIGIT_OFF);
    digitalWrite(PIN_DISPLAY_DIGIT_2, DIGIT_OFF);
    digitalWrite(PIN_DISPLAY_DIGIT_3, DIGIT_OFF);
    digitalWrite(PIN_DISPLAY_DIGIT_4, DIGIT_OFF);
  }

  while( (millis() - beginTime) < DISPLAY_LOOP_TIME) ;
  //Wait for 20ms to pass before we paint the display again
}

// Given a number, turns on those segments
// If number == 10, then turn off number
void Display::_lightNumber(int numberToDisplay) {


  switch (numberToDisplay){

  case 0:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_OFF);
    break;

  case 1:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_OFF);
    break;

  case 2:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_ON);
    break;

  case 3:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_ON);
    break;

  case 4:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_ON);
    break;

  case 5:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_ON);
    break;

  case 6:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_ON);
    break;

  case 7:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_OFF);
    break;

  case 8:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_ON);
    break;

  case 9:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_ON);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_ON);
    break;

  case 10:
    digitalWrite(PIN_DISPLAY_SEGMENT_A, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_B, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_C, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_D, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_E, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_F, SEGMENT_OFF);
    digitalWrite(PIN_DISPLAY_SEGMENT_G, SEGMENT_OFF);
    break;
  }
}
