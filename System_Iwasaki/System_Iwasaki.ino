#include <Servo.h>

//Arduino側設定
const int Servo_PIN = 6;
const int AIN_PIN = 2;
const int DIN_PIN = 7;

//サーボモーター設定
const int Pulse_MIN = 560;
const int Pulse_MAX = 2480;

Servo servo1;

void setup() {
  servo1.attach(Servo_PIN);
  pinMode(DIN_PIN, INPUT);
}

void loop() {
  int analogInput;
  int uSec;
  int i = 0;
  
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
