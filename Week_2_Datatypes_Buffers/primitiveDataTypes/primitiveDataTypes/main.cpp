//
//  main.cpp
//  primitiveDataTypes
//
//  Created by Pete Dowsett on 13/10/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//

#include <array>
#include <vector>
#include <iostream>

int main()
{
    std::cout << "sizeof(char) " << sizeof(char) << "\n"; // 1 byte
    std::cout << "sizeof(short) " << sizeof(short) << "\n"; // 4 bytes
    std::cout << "sizeof(int) " << sizeof(int) << "\n"; // 4 bytes
    std::cout << "sizeof(unsigned int) " << sizeof(unsigned int) << "\n"; // 4 bytes
    std::cout << "sizeof(long) " << sizeof(int) << "\n"; // 4 bytes
    std::cout << "sizeof(unsigned long) " << sizeof(unsigned int) << "\n"; // 4 bytes

    std::cout << "sizeof(float) " << sizeof(float) << "\n"; // 4 bytes
    std::cout << "sizeof(double) " << sizeof(double) << "\n"; // 8 bytes
    std::cout << "sizeof(long double) " << sizeof(long double) << "\n"; // 16 bytes
    std::cout << "\n";

    std::cout << "sizeof(int16_t) " << sizeof(int16_t) << "\n"; // 2 bytes
    std::cout << "sizeof(uint16_t) " << sizeof(uint16_t) << "\n"; // 2 bytes
    std::cout << "sizeof(int32_t) " << sizeof(int32_t) << "\n"; // 4 bytes
    std::cout << "sizeof(uint32_t) " << sizeof(uint32_t) << "\n"; // 4 bytes
    std::cout << "\n";

    std::cout << "sizeof(size_t) " << sizeof(size_t) << "\n"; // 8 bytes (64-bit machine)
    std::cout << "sizeof(ptrdiff_t) " << sizeof(ptrdiff_t) << "\n"; // 8 bytes (64-bit machine)
    std::cout << "\n";

    return 0;
}
