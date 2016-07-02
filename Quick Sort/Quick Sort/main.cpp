//
//  main.cpp
//  Quick Sort
//
//  Created by Hemant Jadon on 22/05/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int partition(int arr[],int start,int end,int pivot){
    int i = start;
    int j = pivot-1;
    while (i<=j) {
        while (arr[i] <= arr[pivot]) {
            i++;
            if (i>j) {
                return pivot;
            }
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        pivot--;
        j--;
    }
    return pivot;
}

void quicksort(int arr[],int start,int end){
    if (start>end) {
        return;
    }
    int pivot = end;
    partition(arr,start,end,pivot);
    quicksort(arr, start, pivot-1);
    quicksort(arr,pivot+1, end);
}

int main(int argc, const char * argv[]) {
    int n=0;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    quicksort(arr, 0, n-1);
    
    for (int i=0; i<n; i++) {
        cout << arr[i]<<" ";
    }
}
