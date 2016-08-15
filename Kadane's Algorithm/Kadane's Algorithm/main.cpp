//
//  main.cpp
//  Kadane's Algorithm
//
//  Created by Hemant Jadon on 04/08/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int arr[]={-2, -3, 4, -1, -2, -2, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int max_till_now = arr[0];
    int curr_max = arr[0];
    for (int i=1; i<n; i++) {
        curr_max = max(arr[i],curr_max+arr[i]);
        max_till_now = max(max_till_now,curr_max);
    }
    
    cout << max_till_now << endl;
}
