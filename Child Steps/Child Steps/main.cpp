//
//  main.cpp
//  Child Steps
//
//  Created by Hemant Jadon on 31/07/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int numberOfWays(int n, int current = 0) {
    if (current >= n) {
        if (current == n){
            return 1;
        }
        else {
            return 0;
        }
    }
    
    int ways = 0;
    
    for (int i = 1; i <= 3; i++) {
        ways += numberOfWays(n, current + i);
    }
    
    return ways;
}

int numberOfWaysDP(int n) {
    int arr[n + 1];
    
    for (int i = 0; i < n + 1; i++) {
        arr[i] = -1;
    }
    
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    
    for (int i = 4; i < n + 1; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    
    return arr[n];
}

int main(int argc, const char * argv[]) {
    cout << numberOfWaysDP(5) << endl;
}
