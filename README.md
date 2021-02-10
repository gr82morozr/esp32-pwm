# ESP32PWM
PWM Library for ESP32

ESP32 built in PWM, total 16 channels, can be attached to most digital pins. 

Max frequency  = 40MHz (resolution = 1) 

Max resolution = 10 (2^10 = 1024 levels, Max freq = 78.125KHz.)

Usage:

`ESP32PWM pwm =  ESP32PWM(int pin);`

`ESP32PWM pwm =  ESP32PWM(int pin, int channel, long freq, int resolution, float dutycycle);`

Sample Code for PWM:

```
#include <ESP32PWM.h>
ESP32PWM pwm =  ESP32PWM(13);
// or 
ESP32PWM pwm =  ESP32PWM(13,1,40000, 10, 0.5);

void setup() {
  pwm.init();
  pwm.run(0.7);
}

void loop() {
  delay(1000);
}
```
Sample Code for Beeper:

```
#include <ESP32PWM.h>
Beeper buz15 = Beeper(15);


void setup() {
  buz15.init();
}

void loop() {
  delay(1000);
  buz15.tone(1000,0.1);
  buz15.notone();
  delay(2000);
  buz15.tone_success();
  delay(2000);
  buz15.tone_warning();
  delay(2000);
  buz15.tone_error();
  delay(2000);
  buz15.tone_tick();
  delay(2000);
  buz15.tone_beep();
}
```
