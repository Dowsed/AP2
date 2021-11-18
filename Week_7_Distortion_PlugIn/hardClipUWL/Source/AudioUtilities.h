/*
  ==============================================================================

    AudioUtilities.h
    Created: 18 Nov 2021 6:13:23pm
    Author:  Pete Dowsett

  ==============================================================================
*/

#pragma once

float parameterSmooth(float input, float previousInput, float alpha = 0.99)
{
    return (1 - alpha) * input + alpha * previousInput;
}
