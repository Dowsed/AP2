//
//  main.cpp
//  printLibraryTest
//
//  Created by Pete Dowsett on 28/10/2021.
//  Copyright © 2021 Pete Dowsett. All rights reserved.
//

#include <iostream>
#include "print.hpp"

int main(int argc, const char * argv[]) {
    std::string* message = new std::string {"Hello World!"};
    print(message);
    return 0;
}
