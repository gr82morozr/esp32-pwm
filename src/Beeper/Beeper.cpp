#include "Beeper.h"

/* 
 *==================================================
 *
 *  Beeper Class Implementation
 * 
 * 
 * 
 * ================================================== 
 */

Beeper::Beeper(int pin) {
  this->pin = pin;
  this->pwm = new ESP32PWM(this->pin);
};

void Beeper::init() {
  this->pwm->init();
};

void Beeper::tone(long freq, float duration_sec) {
  this->pwm->set_freq(freq);
  this->pwm->init();
  this->pwm->run(_TONE_DUTYCYCLE);
  delay((int) (duration_sec * 1000));
  this->notone();
};

void Beeper::tone_error() {
  for (int i=6000; i>=2000; i -=200) {
    this->tone(i, 0.01);
  };
  this->notone();
};

void Beeper::tone_warning() {
  this->tone(1600, 0.1);
  this->tone(600, 0.2);
  this->notone();
};

void Beeper::tone_success() {
  for (int i=2000; i<=6000; i +=200) {
    this->tone(i, 0.01);
  };
  this->notone();
};

void Beeper::tone_ready() {
  this->tone(1800, 0.2);
  this->tone(1800, 0.3);
  this->notone();
};

void Beeper::tone_tick() {
  this->tone(1200, 0.005);
  this->notone();
};

void Beeper::tone_beep() {
  this->tone(3000, 0.2);
  this->notone();
};

void Beeper::notone() {
  this->pwm->run(_DEFAULT_DUTYCYCLE);
}


