//
//  main.cpp
//  XR2100PowerMeter
//
//  Created by Jonathan Adalin on 2016-11-20.
//  Copyright © 2016 Jonathan Adalin. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
}

// Function taken from XR2100 documentation
unsigned char CalcCRC8(unsigned char *data){
    
    unsigned char loopCounter;
    unsigned char crc8;
    unsigned char a;
    
    crc8 = 0;
    while (*data){
        a = *data++;
        for (loopCounter = 0; loopCounter < 8; loopCounter++, a >>= 1){
            if ((a ^ crc8) & 0x01){
                crc8 ^= 0x18;
                crc8 >>= 1;
                crc8 |= 0x80;
            }   else
                crc8 >>= 1;
        }
    }
    return crc8;
}
