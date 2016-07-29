//
//  main.cpp
//  Largest Number Swapping K adjecent
//
//  Created by Hemant Jadon on 29/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int arr[] = {4,5,7,8,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int k = 2;
    
    int swaps_till_now = 0;
    
    int i=0;
    int j=i+1;
    
    while (swaps_till_now < k && i < n) {
        int curr_max_idx=i;
        
        if (arr[j] > arr[curr_max_idx]) {
            swaps_till_now = j-i;
        }
        
        j++;
    }
}
