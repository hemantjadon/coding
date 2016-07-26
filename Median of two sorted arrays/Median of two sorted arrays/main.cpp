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
        return (max(arr1[low1], arr2[low2])+min(arr1[high1], arr2[high2]))/2;
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

int median_of_two_sorted_arrays_different(int A[],int B[],int low1,int high1,int low2,int high2){
    
    int medianA_idx = low1 + (high1-low1)/2;
    int medianB_idx = low2 + (high2-low2)/2;
    
    int medianA = A[medianA_idx];
    int medianB = B[medianB_idx];
    
    //  Both arrays have 0 size.
    if (low1 > high1 && low2 > high2) {
        return -1;
    }
    
    //  First array has 0 size
    if (low1 > high1) {
        return medianB;
    }
    
    //  Second array has 0 size
    if (low2 > high2) {
        return medianA;
    }
    
    //  Both arrays have 1 size.
    if (high1-low1 == 0 && high2-low2 == 0) {
        return max(medianA,medianB);
    }
    
    //  First array of 1 size
    if (high1-low1 == 0) {
        if (A[0] == medianB) {
            return medianB;
        }
        else if(A[0] > medianB){
            if ((high2-low2+1)%2) {
                //  Even elements in B
                return B[medianB_idx+1];
            }
            else {
                //  Odd elements in B
                return medianB;
            }
        }
        else {
            if ((high2-low2+1)%2) {
                //  Even elements in B
                return medianB;
            }
            else {
                //  Odd elements in B
                return B[medianB_idx-1];
            }
        }
    }
    
    //  Second array of size 1.
    if (high2-low2 == 0) {
        if (B[0] == medianA) {
            return medianA;
        }
        else if(B[0] > medianA){
            if ((high2-low2+1)%2) {
                //  Even elements in B
                return B[medianA_idx+1];
            }
            else {
                //  Odd elements in B
                return medianA;
            }
        }
        else {
            if ((high1-low1+1)%2) {
                //  Even elements in B
                return medianA;
            }
            else {
                //  Odd elements in B
                return B[medianA_idx-1];
            }
        }
    }
    
    // Both Arrays of size 2.
    if (high1-low1 == 1 && high2-low2 == 1) {
        return (max(A[low1],B[low2]) + min(A[high1],B[high2]))/2;
    }
    
    //  First array has size 2.
    if (high1-low1 == 1) {
        if ((high2-low2+1)%2 == 0) {
            //  Even elements in B
            int medianB_idx1 = medianB_idx;
            int medianB_idx2 = medianB_idx+1;
            int medianB1 = medianB;
            int medianB2 = B[medianB_idx1];
            
            if (A[low1] <= medianB1 && A[high1] >= medianB2) {
                return (medianB1 + medianB2)/2;
            }
            else if (A[high1] < medianB1){
                if (A[high1] > B[medianB_idx1-1]) {
                    return (medianB1 + B[medianB_idx1-1])/2;
                }
                else {
                    return (A[high1] + medianB1)/2;
                }
            }
            else if (A[low1] > medianB2){
                if (A[low1] > B[medianB_idx2+1]) {
                    return (medianB2 + B[medianB_idx2+1])/2;
                }
                else {
                    return (A[low1] + medianB2)/2;
                }
            }
            else if (A[low1] == medianB1 && A[high1] == medianB2){
                return (medianB1+medianB2)/2;
            }
            else if (A[high1] == medianB1){
                return medianB1;
            }
            else if (A[low1] == medianB2){
                return medianB2;
            }
        }
        else {
            //  Odd elements in B
            if (A[high1] == medianB || A[low1] == medianB) {
                return medianB;
            }
            else if (A[high1] < medianB) {
                if (A[high1] < B[medianB_idx-1]) {
                    return B[medianB_idx-1];
                }
                else {
                    return A[high1];
                }
            }
            else if(A[low1] > medianB){
                if (A[low1] > B[medianB_idx+1]) {
                    return B[medianB_idx+1];
                }
                else {
                    return A[low1];
                }
            }
            else {
                return medianB;
            }
        }
    }
    
    if (medianA > medianB) {
        return median_of_two_sorted_arrays_different(A, B, low1, medianA_idx, medianB_idx, high2);
    }
    else {
        return median_of_two_sorted_arrays_different(A, B, medianA_idx, high1, low2, medianB_idx);
    }
}

int main(int argc, const char * argv[]) {
    int arr1[] = {1,3};
    int arr2[] = {2,4,6,8};
    
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    cout << median_of_two_sorted_arrays_different(arr1, arr2, 0, n1-1, 0, n2-1) << endl;
}
