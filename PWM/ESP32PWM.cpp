#include <Arduino.h>
#include <PWM/ESP32PWM.h>


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
  this->pin         = pin;
  this->channel     = ESP32PWM::get_next_channel();
  this->freq        = _DEFAULT_FREQUENCY ;
  this->resolution  = _DEFAULT_RESOUTION;
  this->dutycycle   = _DEFAULT_DUTYCYCLE;
};

ESP32PWM::ESP32PWM(int pin, long freq) {
  this->pin         = pin;
  this->channel     = ESP32PWM::get_next_channel();
  this->freq        = freq;
  this->resolution  = _DEFAULT_RESOUTION;
  this->dutycycle   = _DEFAULT_DUTYCYCLE;
}

ESP32PWM::ESP32PWM(int pin, int channel, long freq, int resolution, float dutycycle) {
   this->channel = channel;
   this->pin = pin;
   this->freq = freq;
   this->resolution = resolution;
   this->dutycycle = (int) (pow(2,this->resolution) * dutycycle);
}


void ESP32PWM::init(void) {
  if (_ESP32PWM_DEBUG == 1) {
    Serial.println("pin:" + String(this->pin));
    Serial.println("freq:" + String(this->freq));
    Serial.println("channel:" + String(this->channel));
    Serial.println("resolution:" + String(this->resolution));
    Serial.println("dutycycle:" +String(this->dutycycle));  
  };
  ledcSetup(this->channel, this->freq, this->resolution);
  ledcAttachPin(this->pin , this->channel);   
};

void ESP32PWM::set_freq(long freq) {
  this->freq = freq;
};

void ESP32PWM::set_resolution(float resolution) {
  this->resolution = resolution;
};


void ESP32PWM::run(float dutycycle) {
  this->dutycycle = dutycycle;
  ledcWrite(this->channel, (int) (pow(2,this->resolution) *  this->dutycycle)) ;   
};


int ESP32PWM::get_next_channel() {
  ESP32PWM::channel_in_use ++;
  if (ESP32PWM::channel_in_use >= 15) {
    ESP32PWM::channel_in_use = 15;
  }
  return ESP32PWM::channel_in_use;
}




