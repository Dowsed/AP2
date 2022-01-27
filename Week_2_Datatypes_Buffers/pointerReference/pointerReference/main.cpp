//
//  main.cpp
//  pointerReference
//
//  Created by Pete Dowsett on 14/10/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//

#include <iostream>
#include <vector>


void playsound(float* buffer, int bufferSize)
{
    for (int i = 0; i < bufferSize; ++i)
    {
        std::cout << "The value at float pointer buffer [" << i << "] is: " << buffer[i] << std::endl;
    }
}

void playsound(std::vector<float>& buffer)
{
    int size = buffer.size();
    
    for (int i = 0; i < size; ++i)
    {
        std::cout << "The value at vector buffer2 [" << i << "] is: " << buffer[i] << std::endl;
    }
}

void playsound(float& value)
{
    std::cout << "The Value is: " << value << "\n";
}

int main()
{
    // block based with float pointer
    const int bufferSize = 4;
    float buffer[bufferSize] {0.5f, 0.2f, -0.45f, -0.01f};
    float* pointer = new float[bufferSize] {0.5f, 0.2f, -0.45f, -0.01f};
    playsound(pointer, bufferSize);
    
    // block based with vector reference
    std::vector<float> bufferVec = {0.3f, -0.1f, 0.15f, -0.06f};
    playsound(bufferVec);
    
    // sample-by-sample
    int size = bufferVec.size();
    for (int i = 0; i < size; ++ i)
    {
        playsound(bufferVec[i]);
    }
    
    //    std::cout << "Size of buffer: " << sizeof(buffer) << "\n";
    //    std::cout << "Size of float pointer: " << sizeof(pointer) << "\n";
    delete pointer;
    return 0;
}
