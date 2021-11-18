/*
  ==============================================================================

    HardClipper.h
    Created: 18 Nov 2021 5:12:59pm
    Author:  Pete Dowsett

  ==============================================================================
*/

#pragma once

float hardClipper(float input, float threshold)
{
    if (input >= threshold)
        return threshold;
    
    else if (input <= -threshold)
        return -threshold;
    else
        return input;
}
