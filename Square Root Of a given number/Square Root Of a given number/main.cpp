//
//  main.cpp
//  Square Root Of a given number
//
//  Created by Hemant Jadon on 13/08/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int comparisions=0;

long double sqrt(long double num,long double start,long double end){
    comparisions++;
    long double mid = (start + end)/2;
    
    if (mid*mid <= num+0.001 && mid*mid > num-0.001) {
        return mid;
    }
    else if (mid*mid > num){
        return sqrt(num, start, mid);
    }
    else {
        return sqrt(num, mid, end);
    }
}

int main(int argc, const char * argv[]) {
    long double number = 5.15123E15;
    cout << sqrt(number,0,number) << endl;
    cout << comparisions << endl;
}
