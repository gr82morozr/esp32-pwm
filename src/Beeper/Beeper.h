#pragma once
#include <Arduino.h>
#include <PWM/ESP32PWM.h>

/* 
 *==================================================
 *
 *  Beeper Class
 *  
 *  ESP32/Arduino generate sound by pwm
 * 
 * 
 * ================================================== 
 */


#define _TONE_DUTYCYCLE       0.5

class Beeper {
  public:
    Beeper(int pin);
    
    // init Beeper
    void init();
    
    // run pwm with given freq and duration    
    void tone(long freq, float duration_sec);

    // run pwm with given freq and duration patterns
    void tone(long freq, float on_duration_sec, float off_duration_sec, int repeat);

    // pre-defined beeping pattern
    void tone_error();

    void tone_warning();

    void tone_success();

    void tone_ready();

    void tone_tick();

    void tone_beep();
    
    // stop the tone    
    void notone();

  private:
    int pin ;
    long freq;
    ESP32PWM *pwm;
};