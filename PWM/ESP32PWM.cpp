#include <Arduino.h>
#include "ESP32PWM.h"


/* 
 *==================================================
 *
 *  PWM Class Implementation
 * 
 * 
 * 
 * ================================================== 
 */


int ESP32PWM::channel_in_use = -1;


ESP32PWM::ESP32PWM(int pin) {
  this->pin               = pin;
  this->channel           = ESP32PWM::get_next_channel();
  this->freq              = _DEFAULT_FREQUENCY ;
  this->resolution_bits   = _DEFAULT_RESOUTION_BITS;
  this->dutycycle         = _DEFAULT_DUTYCYCLE;
};

ESP32PWM::ESP32PWM(int pin, long freq) {
  this->pin               = pin;
  this->channel           = ESP32PWM::get_next_channel();
  this->freq              = freq;
  this->resolution_bits   = _DEFAULT_RESOUTION_BITS;
  this->dutycycle         = _DEFAULT_DUTYCYCLE;
}

ESP32PWM::ESP32PWM(int pin, int channel, long freq, int resolution_bits, float dutycycle) {
   this->channel          = channel;
   this->pin              = pin;
   this->freq             = freq;
   this->resolution_bits  = resolution_bits;
   this->dutycycle        = dutycycle;
}


void ESP32PWM::init(void) {
  this->debug();
  ledcSetup(this->channel, this->freq, this->resolution_bits);
  ledcAttachPin(this->pin , this->channel);   
};

void ESP32PWM::set_freq(long freq) {
  this->freq = freq;
};

void ESP32PWM::set_resolution_bits(int resolution_bits) {
  this->resolution_bits = resolution_bits;
};


void ESP32PWM::run(float dutycycle) {
  this->dutycycle = dutycycle;
  ledcWrite(this->channel, (int) (pow(2,this->resolution_bits) *  this->dutycycle)) ;   
};


int ESP32PWM::get_next_channel() {
  ESP32PWM::channel_in_use ++;
  if (ESP32PWM::channel_in_use >= 15) {
    ESP32PWM::channel_in_use = 15;
  };
  return ESP32PWM::channel_in_use;
}

void ESP32PWM::debug() {
  if (_ESP32PWM_DEBUG ) {
    Serial.println("DEBUG:  pin:" + String(this->pin));
    Serial.println("DEBUG:  freq:" + String(this->freq));
    Serial.println("DEBUG:  channel:" + String(this->channel));
    Serial.println("DEBUG:  resolution_bits:" + String(this->resolution_bits));
    Serial.println("DEBUG:  dutycycle:" +String(this->dutycycle));  
  };
}


