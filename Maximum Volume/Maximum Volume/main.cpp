//
//  main.cpp
//  Maximum Volume
//
//  Created by Hemant Jadon on 31/07/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxVol(vector<int> arr, int MAX, int currentVol = 0, int idx = 0) {
    if (currentVol > MAX) {
        return -1;
    }
    
    int maxReachVolume = 0;
    
    for (int i = idx; i < arr.size(); i++) {
        int a = maxVol(arr, MAX, currentVol + arr[i], idx + 1);
        int b = maxVol(arr, MAX, currentVol - arr[i], idx + 1);
        
        if (a != -1) {
            maxReachVolume = max(maxReachVolume, a);
        }
        if (b != -1) {
            maxReachVolume = max(maxReachVolume, b);
        }
    }
    
    return maxReachVolume;
}

int main(int argc, const char * argv[]) {
    int MAX = 7;
    vector<int> arr = {2, 3, 3};
    cout << maxVol(arr, MAX);
}
