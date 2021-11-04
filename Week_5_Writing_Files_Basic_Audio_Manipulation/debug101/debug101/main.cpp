//
//  main.cpp
//  debug101
//
//  Created by Pete Dowsett on 04/11/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//

#include <iostream>
#include "Test.hpp"
#include <vector>
#include <thread>
#include <math.h>

#define SIZE 100

int square(int i)
{
    return pow(i,2);
}

int loop(int numLoops)
{
    int j;
    for (int i = 1; i < numLoops; ++i)
     {
         print(square(i));
         j = i;
     }
    return j;
}

int main() {
    
    //std::thread thread1(loop, 10);
    //std::vector<float> floats;
    int num = 10;
    loop(num);
    return 0;
}
