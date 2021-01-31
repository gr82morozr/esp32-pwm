#include <Arduino.h>
#include <ESP32PWM.h>

int ESP32PWM::channel = -1;


ESP32PWM::ESP32PWM(int pin) {
  this->pwm_pin         = pin;
  this->pwm_channel     = ESP32PWM::get_next_channel();
  this->pwm_freq        = _DEFAULT_FREQUENCY ;
  this->pwm_resolution  = _DEFAULT_RESOUTION;
  this->pwm_dutycycle   = _DEFAULT_DUTYCYCLE;
};


ESP32PWM::ESP32PWM(int pin, int channel, long freq, int resolution, float dutycycle) {
   this->pwm_channel = channel;
   this->pwm_pin = pin;
   this->pwm_freq = freq;
   this->pwm_resolution = resolution;
   this->pwm_dutycycle = (int) (pow(2,this->pwm_resolution) * dutycycle);
}


void ESP32PWM::init(void) {
  if (_ESP32PWM_DEBUG == 1) {
    Serial.println("pwm_pin:" + String(this->pwm_pin));
    Serial.println("pwm_freq:" + String(this->pwm_freq));
    Serial.println("pwm_channel:" + String(this->pwm_channel));
    Serial.println("pwm_resolution:" + String(this->pwm_resolution));
    Serial.println("pwm_dutycycle:" +String(this->pwm_dutycycle));  
  };
  ledcSetup(this->pwm_channel, this->pwm_freq, this->pwm_resolution);
  ledcAttachPin(this->pwm_pin , this->pwm_channel);   
};


void ESP32PWM::run(float dutycycle) {
  this->pwm_dutycycle = dutycycle;
  ledcWrite(this->pwm_channel, (int) (pow(2,this->pwm_resolution) *  this->pwm_dutycycle)) ;   
};

int ESP32PWM::get_next_channel() {
  ESP32PWM::channel ++;
  if (ESP32PWM::channel >= 15) {
    ESP32PWM::channel = 15;
  }
  return ESP32PWM::channel;
}