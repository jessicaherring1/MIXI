// MIXI Test
// Jessica Herring

//state
int state = 0;

// Buttons
#include <Bounce2.h>
int numButtons = 8;
int buttonPins [8] = {2, 3, 4, 5, 6, 7, 8, 9};
Bounce * buttons = new Bounce[8];
boolean buttonStates0[8] = {false, false, false, false, false, false, false, false};
boolean buttonStates1[8] = {false, false, false, false, false, false, false, false};
boolean buttonStates2[8] = {false, false, false, false, false, false, false, false};


// Potentiometers
int numPots = 4;
int potPins[4] = {0, 1, 2, 3};
int potStates[4] = {0, 0, 0, 0};

int curVal0;
int pastVal0 = 0;
int curVal1;
int pastVal1;
int curVal2;
int pastVal2;
int curVal3;
int pastVal3;
int thresh = 20;

int colors[3] = {(255, 0, 0), (255, 255, 255), (0, 0, 255)};

// LEDs
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 10, NEO_RGB + NEO_KHZ800);
int numLED = 8;

// MIDI
#include "MIDIUSB.h"

void setup() {
  Serial.begin(9600);
  initButtons();
  initLED();
  introFunc();
}

void loop() {
  //checkPots();
  switchCase();

  switch (state) {

    case 0: // drums

      for (int i = 0; i < 8; i++) {
        strip.setPixelColor(i, 255, 0, 0);
        strip.show();
      }

      for (int i = 0; i < numButtons; i++)  {
        buttons[i].update();
        if (buttons[i].rose() ) {
          buttonStates0[i] = !buttonStates0[i];
          if (buttonStates0[i]) {
            controlChange(0, 1, 127);
          } else {
            controlChange(0, 1, 0);
          }
          String printStr = "State 0, button " + String(i);
          Serial.println(printStr);
        }
      }
      break;

    case 1: // piano

      for (int i = 0; i < 8; i++) {
        strip.setPixelColor(i, 255, 255, 255);
        strip.show();
      }
      for (int i = 0; i < numButtons; i++)  {
        buttons[i].update();
        if (buttons[i].rose() ) {
          buttonStates1[i] = !buttonStates1[i];
          if (buttonStates1[i]) {
            controlChange(0, 2, 127); //change
          } else {
            controlChange(0, 2, 0);
          }
          String printStr = "State 1, button " + String(i);
          Serial.println(printStr);
        }
      }
      break;

    case 2: // sounds

      for (int i = 0; i < 8; i++) {
        strip.setPixelColor(i, 0, 0, 255);
        strip.show();
      }
      for (int i = 0; i < numButtons; i++)  {
        buttons[i].update();
        if (buttons[i].rose() ) {
          buttonStates2[i] = !buttonStates2[i];
          if (buttonStates2[i]) {
            controlChange(0, i+1, 127);
            Serial.println(i+1);
          } else {
            controlChange(0, i+1, 0);
          }
          String printStr = "State 2, button " + String(i);
          Serial.println(printStr);
        }
      }
      break;
  }

  curVal0 = analogRead(potPins[0]);
  if (abs(curVal0 - pastVal0) > thresh) {
    int outPot = map(curVal0, 0, 1023, 127, 0);
    Serial.println(curVal0);
    controlChange(0, 10, outPot);
    pastVal0 = curVal0;
  }

  curVal1 = analogRead(potPins[1]);
  if (abs(curVal1 - pastVal1) > thresh) {
    int outPot = map(curVal1, 0, 1023, 127, 0);
    Serial.println(outPot);
    controlChange(0, 11, outPot);
    //Serial.println(curVal1);
    pastVal1 = curVal1;
  }

  curVal2 = analogRead(potPins[2]);
  if (abs(curVal2 - pastVal2) > thresh) {
    int outPot = map(curVal2, 0, 1023, 127, 0);
    Serial.println(outPot);
    controlChange(0, 12, outPot);
    //Serial.println(curVal2);
    pastVal2 = curVal2;
  }

  curVal3 = analogRead(potPins[3]);
  if (abs(curVal3 - pastVal3) > thresh) {
    int outPot = map(curVal3, 0, 1023, 127, 0);
    Serial.println(outPot);
    controlChange(0, 13, outPot);
    //Serial.println(curVal3);
    pastVal3 = curVal3;
  }

}

void introFunc() {
  for (int i = 0; i < 8; i++) {
    int c = random(4);
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
    delay(100);
  }
  delay(50);
  for (int i = 0; i < 8; i++) {
    int c = random(4);
    strip.setPixelColor(i, 255, 255, 255);
    strip.show();
    delay(100);
  }
  delay(50);
  for (int i = 0; i < 8; i++) {
    int c = random(4);
    strip.setPixelColor(i, 0, 0, 255);
    strip.show();
    delay(100);
  }

}

void switchCase() {
  int curVal = analogRead(potPins[1]);
  if (curVal <= 350) {
    state = 0;
  }
  if (curVal > 350 && curVal <= 700) {
    state = 1;
  }
  if (curVal > 750) {
    state = 2;
  }
}
