# ESP32PWM
PWM Library for ESP32

ESP32 built in PWM, total 16 channels, can be attached to most digital pins. 

Max frequency  = 40MHz (resolution = 1) 

Max resolution = 10 (2^10 = 1024 levels, Max freq = 78.125KHz.)

Usage:

`ESP32PWM pwm =  ESP32PWM(int pin);`

`ESP32PWM pwm =  ESP32PWM(int pin, int channel, long freq, int resolution, float dutycycle);`

Sample Code:

```
#include <ESP32PWM.h>`
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
