#include <iostream>

#define NUM_CHANNELS 3
#define NUM_FRAMES 4

int main() {
    std::string buffer[NUM_CHANNELS * NUM_FRAMES] = {"A0", "A1", "A2", "A3", "B0", "B1", "B2", "B3", "C0", "C1", "C2", "C3"};
    const int frameRequired = 3;
    const int chanRequired = 0;
    std::cout << chanRequired * NUM_FRAMES + frameRequired << std::endl;
    std::cout << "Memory Address of A3: " << &buffer[chanRequired * NUM_FRAMES + frameRequired] << std::endl;
    
    return 0;
}
