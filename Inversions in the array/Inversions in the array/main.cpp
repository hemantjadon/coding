//
//  main.cpp
//  Inversions in the array
//
//  Created by Hemant Jadon on 28/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;


int merge_inversion_count(int arr[],int low1,int high1,int low2,int high2){
    int inversions=0;
    int numbers = (high1-low1)+1 + (high2-low2)+1;
    
    int i = low1;
    int j = low2;
    
    int aux_arr[numbers];
    int k=0;
    
    while ((i <= high1) && (j <= high2)) {
        if (arr[i] < arr[j]) {
            aux_arr[k] = arr[i];
            k++;
            i++;
        }
        else {
            aux_arr[k] = arr[j];
            inversions += high1-i+1;
            k++;
            j++;
        }
    }
    while (i <= high1) {
        aux_arr[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high2) {
        aux_arr[k] = arr[j];
        k++;
        j++;
    }
    
    int l = low1;
    
    for (int i=0; i<k; i++) {
        arr[l] = aux_arr[i];
        l++;
    }
    return inversions;
}

int mergesort_inversion_count(int arr[],int low,int high){
    int inversions=0;
    if (low >= high) {
        return inversions;
    }
    int mid = low + (high-low)/2;
    inversions += mergesort_inversion_count(arr, low, mid);
    inversions += mergesort_inversion_count(arr, mid+1, high);
    inversions += merge_inversion_count(arr, low, mid, mid+1, high);
    return inversions;
}

int main(int argc, const char * argv[]) {
    int arr[]={2,4,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << mergesort_inversion_count(arr, 0, n-1) << endl;
    
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}