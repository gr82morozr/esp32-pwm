#pragma once
#include <Arduino.h>


#define _ESP32PWM_DEBUG               0
#define _DEFAULT_RESOUTION_BITS       10
#define _DEFAULT_FREQUENCY            10000
#define _DEFAULT_DUTYCYCLE            0.1



/*
  ESP32 built in PWM, total 16 channels, can be attached to most digital pins.
  Max frequency  = 40MHz (resolution = 1) 
  Max resolution = 10 (2^10 = 1024 levels, Max freq = 78.125KHz.)

  // ========================================================
  //    Sample code:
  // ========================================================
  // include customized headers
  #include <ESP32PWM.h>

  ESP32PWM pwm =  ESP32PWM(13);
  
  void setup() {
    pwm.init();
    pwm.run(0.7);
  }

  void loop() {
    delay(1000);
  }
  // ========================================================


  Note:
  - PWM channels are grouped by pairs (0,1) (2,3) ... (14, 15)
    the same pair can only have same frequency but different dutycycle
    the diffetent pair can have different frequency and dutycycle 


  Change Log:
    - 2021-01-31 : updated to simplify the constructors 
*/


class ESP32PWM {
  public:
    // simple constructor - all default values
    ESP32PWM(int pin);

    // advanced constructor - some costomized values
    ESP32PWM(int pin, long freq);

    // advanced constructor - some costomized values
    ESP32PWM(int pin, long freq, float dutycycle);

    // advanced constructor - some costomized values
    ESP32PWM(int pin, long freq, int resolution_bits, float dutycycle);

    // advanced constructor - all costomized values
    ESP32PWM(int pin, int channel, long freq, int resolution_bits, float dutycycle);

    // init pwm    
    void init();

    // set freq   
    void set_freq(long freq);

    // set resolution_bits
    void set_resolution_bits(int resolution);

    // run pwm with given dutycycle    
    void run(float dutycycle);
   
    // 
    int get_channel(void);
   
  private:
    long        freq              ;
    int         pin               ;
    int         channel           ;
    int         resolution_bits   ;
    float       dutycycle         ;
    static int  channel_in_use    ;

    // get next free channel, 0 ~ 15
    static int  get_next_channel();
    void        debug();
};
