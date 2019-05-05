//
//  main.cpp
//  Maximum Sum Subarray
//
//  Created by Hemant Jadon on 31/07/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * We keep track of current maximum and maximum
 * The current maximum is the max of either the element or
 * the element added to the current maximum.
 * What happens here is, current max is allowed to decrease here,
 * with an optimistic approach that a larger element will come
 * later and increase the current max more than the maximum
 * The maximum is th max of all intermediate current max states.
 */
int kadaneAlgorithm(vector<int> arr) {
    int maxmim = INT_MIN;
    int curr_max = arr.size() ? arr[0] : -1;
    
    for (int i = 0; i < arr.size(); i++) {
        curr_max = max(arr[i], arr[i] + curr_max);
        maxmim = max(maxmim, curr_max);
    }
    
    return maxmim;
}

int main(int argc, const char * argv[]) {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    
    cout << kadaneAlgorithm(arr) << endl;
}
