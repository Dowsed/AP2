//
//  main.cpp
//  audioBufferExamples
//
//  Created by Pete Dowsett on 13/10/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//

#include <iostream>
#include <vector>
#define BUFFERSIZE 5
#define DYNAMICALLY_ALLOCATED 1

float processAudioPointer(float* buffer, int bufferSize)
{
    float sum = 0;
    for (int i = 0; i < bufferSize; ++i)
    {
        std::cout << "buffer [" << i << "] value: " << buffer[i] << "\n";
        sum += buffer[i];
        std::cout << "Current sum: " << sum << "\n";
    }
    return sum;
};

float processAudioReference(std::vector<float>& buffer)
{
    float sum = 0;
    for (int i = 0; i < buffer.size(); ++i)
    {
        std::cout << "buffer [" << i << "] value: " << buffer[i] << "\n";
        sum += buffer[i];
        std::cout << "Current sum: " << sum << "\n";
    }
    return sum;
};

void pointerExample()
{
    #if DYNAMICALLY_ALLOCATED
         float audioSamples[BUFFERSIZE] {0.0, 0.1, 0.2, 0.3, 0.4};
         float* audioSamplePtr = audioSamples;
    #else
        float* audioSamplePtr = new float[5] {0.0, 0.1, 0.2, 0.3, 0.4};
    #endif
        float processOutput = processAudioPointer(audioSamplePtr, BUFFERSIZE);
    std::cout << "summed output with pointer: " << processOutput << "\n";
}

void referenceExample()
{
    std::vector<float> buffer {0.0, 0.1, 0.2, 0.3, 0.4};
    float processOutput = processAudioReference(buffer);
    std::cout << "summed output with reference: " << processOutput << "\n";
}

int main() {
    pointerExample();
    referenceExample();
    // process method with reference
    
    return 0;
}
