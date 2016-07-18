//
//  main.cpp
//  Maximum Continuous Subarray
//
//  Created by Hemant Jadon on 18/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int arr []={-2, -3, 4, -1, -2, 5, 1, -3};
    int n = sizeof(arr) / sizeof(int);
    
    int max_last_index = 0;
    
    int curr_sum=arr[0];
    
    for (int i=0; i<n; i++) {
        if (arr[i] > 0) {
            if (curr_sum > 0) {
                if (max_last_index == i-1) {
                    curr_sum += arr[i];
                    max_last_index = i;
                }
                else {
                    curr_sum = arr[i];
                    max_last_index = i;
                }
            }
            else {
                curr_sum = arr[i];
                max_last_index = i;
            }
        }
        else{
            if (arr[i] > curr_sum) {
                curr_sum = arr[i];
                max_last_index = i;
            }
        }
    }
    cout << curr_sum << endl;
}
