/***************************************************************
 * This library adds vital functions for automated control 
 * of the camera slider adding timelapse functionality.
 * 
 * Requried hardware is found in the fritzing sketch.
 * 
 * Written by Jacob Frommeyer.
 * 
 * Copywrite Jacob Frommeyer 2020
 * 
 * Log
 * 6/22/2020    Library created
 * 
 ***************************************************************/

#ifndef arduSlider_h
#define arduSlider_h

#include "Arduino.h"

class arduSlider
{
    public:
        arduSlider();
        int calculateStepTime();
        //int calibrateSlider();

        int frameRate;
        int timeLapseLength;
        int shootTime;
        int maxExposureLength;
        //int totalSteps;

    private:
        int totalFrames;
        int seconds;
};

#endif