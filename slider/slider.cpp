#include "slider.h"
#include "Stepper.h"

/****************************************************
 * This is the constructor, it sets default values
 * that will be overwritten.
 * 
 * No parameters
 * 
 * Returns default values.
 ****************************************************/

Slider::Slider(int limitSwitch_1, int limitSwitch_2, const int shutterTrigger, int stepper_speed, int stepper_pin1, int stepper_pin2, int stepper_pin3, int stepper_pin4)
{
    frameRate = 30;
    timeLapseLength = 30;
    shootTime = 3600;
    totalSteps = 0;

    switch1 = limitSwitch_1;
    switch2 = limitSwitch_2;
    cameraTrigger = shutterTrigger;

    speed = stepper_speed;
    pin1 = stepper_pin1;
    pin2 = stepper_pin2;
    pin3 = stepper_pin3;
    pin4 = stepper_pin4;

    //Stepper sled(speed, pin1, pin2, pin3, pin4);             
}

/****************************************************
 * This function reads in the variables sent by the
 * phone over bluetooth.  It parses each value into
 * the specific variable.  It then calculates the
 * amount of time required in between each movement
 * to take the picture.
 * 
 * value order
 * framerate,timelapselength,shoottime
 * 
 * No parameters
 * 
 * Returns time between each movement for pictures.
 ***************************************************/

int Slider::calcStepTime()
{
    String temp;
    Serial.println("Enter values (framerate, timelapselength, shoottime)");
    while(Serial.available() == 0)
    {
        temp = Serial.read();
    }

    Serial.println(temp);

    // Serial.println("Enter desired frame rate: ");
    // while(Serial.available() == 0)
    // {
    // //frameRate = Serial.read();
    // }
    // frameRate = Serial.read();
    // Serial.println("\nEnter desired timelapse length in seconds: ");
    // while(Serial.available() == 0)
    // {
    // //timeLapseLength = Serial.read();
    // }
    // timeLapseLength = Serial.read();

    totalFrames = frameRate * timeLapseLength;
    seconds = shootTime * 3600;
    maxExposureLength = seconds / totalFrames;
}

/****************************************************
 * This function moves the slider to a zero point and
 * then counts steps till it reaches the other end
 * of the slider.
 * 
 * No parameters
 * 
 * Returns total number of steps with a buffer of 20
 * steps applied.
 ***************************************************/

int Slider::calibrateSlider()
{
    while(digitalRead(switch1) != 0 || digitalRead(switch2) != 0)) //Moves carriage to one end of slider.
    {
    sled.step(-1)
    }
    if(digitalRead(switch1) == 0 || digitalRead(switch2) == 0)
    {
    stepper.step(1);
    }
    totalSteps += 1;
    while(digitalRead(switch1) != 0 || digitalRead(switch2) != 0)
    {
    stepper.step(1);
    totalSteps += 1;
    }

    stepper.step(-10);
    return totalSteps - 20;
}