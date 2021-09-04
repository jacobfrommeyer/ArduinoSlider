#ifndef Slider_h
#define Slider_h

#include "Arduino.h"
#include "Stepper.h"

class Slider
{
  public:
    Slider(int limitSwitch_1, int limitSwitch_2, const int shutterTrigger, int stepper_speed, int stepper_pin1, int stepper_pin2, int stepper_pin3, int stepper_pin4);
    int calcStepTime();
    int calibrateSlider();

    int frameRate;
    int timeLapseLength;
    int shootTime;
    int maxExposureLength;
    int totalSteps;
    int totalFrames;

  private:
    int seconds;
    int switch1;
    int switch2;
    int cameraTrigger;
    int speed;
    int pin1;
    int pin2;
    int pin3;
    int pin4;
    Stepper stepper(int speed, int pin1, int pin2, int pin3, int pin4);

};

#endif