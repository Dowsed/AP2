//
//  main.cpp
//  doublePointer
//
//  Created by Pete Dowsett on 21/10/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//

#include <iostream>

int main() {
    std::string A[4] = {"A0", "A1", "A2", "A3"};
    std::string B[4] = {"B0", "B1", "B2", "B3"};
    std::string C[4] = {"C0", "C1", "C2", "C3"};
    std::string* buffer[3] = {A, B, C};
    std::string** ptr = buffer;
    
    const int channelRequired = 2;
    const int frameRequired = 3;
    
    std::cout << "Index: " << ptr[channelRequired][frameRequired] << std::endl;
    
    return 0;
}
