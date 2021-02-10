#pragma once
#include <Arduino.h>
#include "ESP32PWM.h"

#define _TONE_DUTYCYCLE       0.5

class Beeper {
  public:
    Beeper(int pin);
    
    // init Beeper
    void init();
    
    // run pwm with given freq and duration    
    void tone(long freq, float duration);

    // run pwm with given freq and duration patterns
    void tone(long freq, float on_duration, float off_duration, int repeat);

    // pre-defined beeping pattern
    void tone_error();

    void tone_warning();

    void tone_success();

    void tone_tick();

    void tone_beep();
    
    // stop the tone    
    void notone();

  private:
    int pin ;
    long freq;
    ESP32PWM *pwm;
};