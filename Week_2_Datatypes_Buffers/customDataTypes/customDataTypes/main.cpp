//
//  main.cpp
//  datatypes
//
//  Created by Pete Dowsett on 13/10/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//

#include <iostream>
#include "audioType.h"

int main() {
    sample_t test = 2.f;
    std::cout << typeid(test).name() << std::endl;
}
