//
//  main.cpp
//  interleavedMemoryAddress
//
//  Created by Pete Dowsett on 21/10/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//

#include <iostream>

#define NUM_CHANNELS 3
#define NUM_FRAMES 4

int main() {
    std::string buffer[NUM_CHANNELS * NUM_FRAMES] = {"A0", "B0", "C0", "A1", "B1", "C1", "A2", "B2", "C2", "A3", "B3", "C3"};
    const int frameRequired = 3;
    const int chanRequired = 0;
    
    std::cout << "Memory Address of A3: " << &buffer[frameRequired * NUM_CHANNELS + chanRequired] << std::endl;
    
    return 0;
}
