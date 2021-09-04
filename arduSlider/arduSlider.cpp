/* **************************************************************
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

#include "Arduino.h"
#include "arduSlider.h"

arduSlider::arduSlider()
{
    frameRate = 30;
    timeLapseLength = 30;
    shootTime = 1200;
}

int arduSlider::calculateStepTime()
{
    totalFrames = frameRate * timeLapseLength;

    seconds = shootTime * 3600;

    maxExposureLength = seconds / totalFrames;
}

// int arduSlider::calibrateSlider()
// {
//     while()
// }