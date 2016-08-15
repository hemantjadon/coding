//
//  main.cpp
//  Crazy pattern
//
//  Created by Hemant Jadon on 28/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    unsigned long n=53;
    unsigned long dup = n;
    
    unsigned long quotient=0;
    unsigned long remainder=n;
    
    string output="";
    
    do {
        int power = 0;
        dup = remainder;
        
        while (dup) {
            dup/=26;
            power++;
        }
        
        unsigned long divisor = pow(26,power-1);
        
        quotient = remainder/divisor;
        remainder = remainder % divisor;
        
        output+= char(97+quotient-1);
        
        if (remainder <= 26 && remainder > 0) {
            output+=char(97+remainder-1);
        }
    } while (remainder > 26);
    
    cout << output << endl;
}
