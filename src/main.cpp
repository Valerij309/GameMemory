#include <Arduino.h>
#include "mainH.h"
void setup() {
  Serial.begin(9600); 

  for(int i = 0; i < 4; i++){
    pinMode(leds[i],OUTPUT);
    pinMode(button[i],INPUT_PULLUP);
 }
 randomSeed(analogRead(A0) + analogRead(A1));
   for(int i = 0; i < 5; i++){
      Serial.println(seq[i]);
   }
}



void loop() {
  mainfunc();
}

