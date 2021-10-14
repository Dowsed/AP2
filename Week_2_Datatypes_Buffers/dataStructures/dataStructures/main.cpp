//
//  main.cpp
//  dataStructures
//
//  Created by Pete Dowsett on 13/10/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//
#include <array>
#include <vector>
#include <iostream>

int main() {
    float myFloat = 13;
    float staticArray[] = {0, 1, 2, 3, 4, 5, 6, 7};
    float* floatPtr = staticArray;
    std::array<float, 8> modernArray = {0, 42, 2, 33, 94, 5, 6, 7};
    int some_length = 8;
    float* dynamicArray = new float[some_length]{0, 1, 2, 3, 4, 5, 6, 7};

    const size_t LEN = 100;
    std::vector<float> floatVector(LEN);
    floatVector.resize(30);

    std::cout << "sizeof(myFloat) " << sizeof(myFloat) << "\n"; // 4 bytes 32bit IEEE-753
    std::cout << "sizeof(staticArray) " << sizeof(staticArray) << "\n"; // 4 * 8 = 32 bytes (whole block known at compile time)
    std::cout << "sizeof(floatPtr) " << sizeof(floatPtr) << "\n"; // 8 bytes pointer only
    std::cout << "sizeof(modernArray) " << sizeof(modernArray) << "\n"; // 4 * 8 = 32 bytes (same as static C-array)
    std::cout << "sizeof(dynamicArray) " << sizeof(dynamicArray) << "\n"; // 8 bytes (pointer only, unknown size at compile time)
    std::cout << "sizeof(floatVector) " << sizeof(floatVector) << "\n"; // 24 bytes of bookkeeping regardless of content
    std::cout << std::endl;

    std::cout << "myFloat " << myFloat << std::endl;
    std::cout << "&myFloat " << &myFloat << std::endl;
//    std::cout << "*myFloat" << *myFloat << std::endl; // compiler error
    std::cout << "staticArray " << staticArray << std::endl;
    std::cout << "&staticArray " << &staticArray << std::endl;
    std::cout << "*staticArray " << *staticArray << std::endl; // first element of array
    std::cout << "floatPtr " << floatPtr << std::endl; // equal to staticArray by definition
    std::cout << "&floatPtr " << &floatPtr << std::endl;
    std::cout << "*floatPtr " << *floatPtr << std::endl; // first element of array
    std::cout << "dynamicArray " << dynamicArray << std::endl; // pointer to first element
    std::cout << "&dynamicArray " << &dynamicArray << std::endl; // address of pointer, storable as pointer to pointer
    std::cout << "*dynamicArray " << *dynamicArray << std::endl; // first element of array
    return 0;
}
