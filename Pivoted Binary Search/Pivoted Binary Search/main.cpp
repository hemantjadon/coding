//
//  main.cpp
//  Pivoted Binary Search
//
//  Created by Hemant Jadon on 18/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int binarySearch(int arr[],int low,int high,int el){
    if (low > high) {
        return -1;
    }
    
    int mid = (low + high)/2;
    
    if (el == arr[mid]) {
        return mid;
    }
    else if (el > arr[mid]){
        return binarySearch(arr, mid+1, high, el);
    }
    else {
        return binarySearch(arr, low, mid-1, el);
    }
}

int findPivot(int arr[],int low,int high){
    if (low > high) {
        return -1;
    }
    if (low == high) {
        return low;
    }
    
    int mid = (low+high)/2;
    if (arr[mid] > arr[mid+1]) {
        return mid;
    }
    if (arr[mid] < arr[mid-1]) {
        return mid-1;
    }
    if (arr[mid] > arr[low]) {
        mid = findPivot(arr, mid+1 , high);
    }
    else {
        mid = findPivot(arr, low, mid-1);
    }
    return mid;
}

int pivotedBinarySearch(int arr[],int n,int el){
    int pivot = findPivot(arr, 0, n-1);
    
    if (arr[pivot] == el) {
        return pivot;
    }
    
    if (arr[0] > el) {
        return binarySearch(arr, pivot+1, n-1, el);
    }
    
    else {
        return binarySearch(arr, 0, pivot, el);
    }
}

int main(int argc, const char * argv[]) {
    int arr[]={5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    
    cout << pivotedBinarySearch(arr,n,10);
}
