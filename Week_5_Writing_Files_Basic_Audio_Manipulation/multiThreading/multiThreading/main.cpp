//
//  main.cpp
//  multiThreading
//
//  Created by Pete Dowsett on 04/11/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//

#include <iostream>
#include <vector>
#include <thread>
#include <numeric>

void accumulateRange(int &sum, int start, int end)
{
    sum = 0;
    for (int i = start; i < end; ++i)
    {
        sum += i;
    }
}



int main(int argc, const char * argv[])
{
    const int numThreads = 2;
    const int numElements = 1000 * 1000 * 1000;
    const int step = numElements / numThreads;
    
    std::vector<int> partialSums(numThreads);
    
    std::thread t1(accumulateRange,std::ref(partialSums[0]), 0, step);
    std::thread t2(accumulateRange, std::ref(partialSums[1]), step, numThreads * step);
    
    t1.join();
    t2.join();
    
    int total = std::accumulate(partialSums.begin(), partialSums.end(), int(0));
    
    std::cout << "Total: " << total << std::endl;
    
    return 0;
}
