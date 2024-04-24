#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
        unsigned long long aValue[k.length()];
        unsigned long long wValue[5] = {0, 0, 0, 0, 0};
        unsigned long long result = 0;
        

        int counter = 0;
        int wIndex = 4;
        int stringIndex = k.length() - 1;

        for (int i = 0; i < k.length(); i++) 
        {
            aValue[i] = letterDigitToNumber(k[i]);
        }

        while (stringIndex >= 0) {
            if (counter < 6) {
                result += pow(36, counter) * aValue[stringIndex];
                stringIndex--;
                counter++;
            }

            else {
                wValue[wIndex] = result;
                result = 0; 
                wIndex--;
                if (stringIndex >= 0) {
                    counter = 0;
                }
            }
        }

        if (stringIndex != 0) {
            wValue[wIndex] = result;
        }

        return rValues[0] * wValue[0] + rValues[1] * wValue[1] + rValues[2] * wValue[2] + rValues[3] * wValue[3] + rValues[4] * wValue[4];
    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
        char c = tolower(letter);
        
        switch (c)
        {
            case 'a': return 0;
            case 'b': return 1;
            case 'c': return 2;
            case 'd': return 3;
            case 'e': return 4;
            case 'f': return 5;
            case 'g': return 6;
            case 'h': return 7;
            case 'i': return 8;
            case 'j': return 9;
            case 'k': return 10;
            case 'l': return 11;
            case 'm': return 12;
            case 'n': return 13;
            case 'o': return 14;
            case 'p': return 15;
            case 'q': return 16;
            case 'r': return 17;
            case 's': return 18;
            case 't': return 19;
            case 'u': return 20;
            case 'v': return 21;
            case 'w': return 22;
            case 'x': return 23;
            case 'y': return 24;
            case 'z': return 25;
            case '0': return 26;
            case '1': return 27;
            case '2': return 28;
            case '3': return 29;
            case '4': return 30;
            case '5': return 31;
            case '6': return 32;
            case '7': return 33;
            case '8': return 34;
            case '9': return 35;
            default: return -1;
        }
    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
