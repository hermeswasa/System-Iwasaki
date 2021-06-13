#include <Servo.h>

//Arduino側設定
const int Servo_PIN = 6;
const int AIN_PIN = 2;

//サーボモーター設定
const int Pulse_MIN = 560;
const int Pulse_MAX = 2480;

//for miuzei MS18 MIN 900 to MAX 2100

Servo servo1;

void setup() {
  servo1.attach(Servo_PIN);
}

void loop() {
  int analogInput;
  int uSec;
  
  while(1){
    analogInput = analogRead(AIN_PIN);
    uSec = AnalogToPulse(analogInput);
    servo1.write(uSec);
  }
}

int AnalogToPulse(int input){
  int rtnPulse = (input/1023)*(Pulse_MAX-Pulse_MIN)+Pulse_MIN;
  return rtnPulse;
}
