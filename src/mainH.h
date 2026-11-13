#pragma once
#include <Arduino.h>

int leds[4] = {13, 12, 11, 10};
int button[4] = {7, 6, 5, 4};

int level = 1;
int seq[20] = {};
int valuebuttonpressed = -1;

void setupGame() {
  for (int i = 0; i < level; i++) {
    int randIndex = random(0, 4);
    seq[i] = randIndex;

    digitalWrite(leds[randIndex], HIGH);
    delay(500);
    digitalWrite(leds[randIndex], LOW);
    delay(300);
  }
}

void buttonWait() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(button[i]) == LOW) {
        valuebuttonpressed = i;
        delay(50);
        digitalWrite(leds[i],1); 
        while (digitalRead(button[i]) == LOW) {
          delay(10);
        }
        digitalWrite(leds[i],0);
        delay(150);
        return;
      }
    }
  }
}

void mainfunc() {
  Serial.print("Level: ");
  Serial.println(level);

  setupGame();

  for (int i = 0; i < level; i++) {
    buttonWait();

    if (valuebuttonpressed == seq[i]) {
      Serial.println("Next");
    } else {
      Serial.println("You lose");


      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 4; k++) digitalWrite(leds[k], HIGH);
        delay(200);
        for (int k = 0; k < 4; k++) digitalWrite(leds[k], LOW);
        delay(200);
      }

      level = 1;
      delay(1000);
      return;
    }
  }

  level++;
    Serial.println("Next level");
  delay(1000);
}