 #include <JeeLib.h>
ISR(WDT_vect) { Sleepy::watchdogEvent(); }

int ledPins[] = {3, 5, 6, 9, 10, 11}; 
int numPins = (sizeof(ledPins) / sizeof(int));

void setup()
{
  for (int i = 0; i < numPins; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
  }
  
  randomSeed(analogRead(0)); 
}

void loop()
{
  int ledToBlink = ledPins[random(0, numPins)];
  int timeToSleep = random(5000, 12000);
  
  blinkLed(ledToBlink);
  
  Sleepy::loseSomeTime(timeToSleep);
}

void blinkLed(int pin) {  
  int totalDuration = random(500, 1750);
  int numFades = random(1, 3);
   
  int minBrightness = 0;
  int maxBrightness = 52);
  int currentBrightness = minBrightness;
  int fadeIncrement = 2;
  int delayTime = round((totalDuration / numFades) / ((maxBrightness - minBrightness) / fadeIncrement));

  int fadeCount = 0;
  while(fadeCount < numFades) {
    while(currentBrightness <= maxBrightness) {
          analogWrite(pin, currentBrightness + random(-5, 5));
          currentBrightness += fadeIncrement;
          delay(delayTime);
    }
    
    while(currentBrightness >= minBrightness) {
          analogWrite(pin, currentBrightness + random(-5, 5));
          currentBrightness =- fadeIncrement;
          delay(delayTime);
    }    
    fadeCount += 1;
  }
  analogWrite(pin, 0);
}


