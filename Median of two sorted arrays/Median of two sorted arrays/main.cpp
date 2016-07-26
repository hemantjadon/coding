//
//  main.cpp
//  Median of two sorted arrays
//
//  Created by Hemant Jadon on 26/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int median_of_two_sorted_arrays_equal(int arr1[],int arr2[],int n){
    int median=0;
    
    int increments = 0;
    
    int i=0;
    int j=0;
    
    while (i < n && j < n) {
        if (arr1[i] < arr2[j]) {
            median = arr1[i];
            i++;
        }
        else {
            median = arr2[j];
            j++;
        }
        
        increments++;
        if (increments == n) {
            break;
        }
    }
    
    return median;
}


int median_of_two_sorted_arrays_equal_better(int arr1[],int arr2[],int low1,int high1,int low2, int high2){
    if (high1-low1 == 1) {
        return min(max(arr1[low1], arr2[low2]),min(arr1[high1], arr2[high2]));
    }
    
    int m1_idx = low1 + (high1-low1)/2;
    int m2_idx = low2 + (high2-low2)/2;
    
    if (arr1[m1_idx] == arr2[m2_idx]) {
        return arr1[m1_idx];
    }
    
    else if (arr1[m1_idx] < arr2[m2_idx]) {
        return median_of_two_sorted_arrays_equal_better(arr1, arr2, m1_idx, high1, low2, m2_idx);
    }
    else {
        return median_of_two_sorted_arrays_equal_better(arr1, arr2, low1, m1_idx, m2_idx, high2);
    }
}


int main(int argc, const char * argv[]) {
    int arr1[] = {1,12,15,26,38};
    int arr2[] = {2,13,17,30,35};
    
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    cout << median_of_two_sorted_arrays_equal_better(arr1, arr2, 0, n1-1, 0, n2-1) << endl;
}
