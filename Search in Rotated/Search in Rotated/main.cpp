//
//  main.cpp
//  Search in Rotated
//
//  Created by Hemant Jadon on 28/07/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

bool searchRotated(int arr[], int n, int k) {
    
    std::function<int (int[], int, int, int)> findPivot
    = [&] (int arr[], int n, int left, int right) -> int {
        if (left > right) {
            return -1;
        }
        
        int mid = (left + right)/2;
        
        if ((arr[mid] < arr[mid + 1]) && (arr[mid] < arr[mid - 1])) {
            return mid;
        }
        
        if (left == right) {
            return -1;
        }
        
        else {
            if (arr[left] > arr[mid]) {
                return findPivot(arr, n, mid, right);
            }
            else {
                return findPivot(arr, n, left, mid);
            }
        }
        return -1;
    };
    
    std::function<bool (int[], int, int, int)> binarySearch
    = [&] (int arr[], int k, int left, int right) -> bool {
        if (left > right) {
            return false;
        }
        
        int mid = (left + right)/2;
        
        if (arr[mid] == k) {
            return true;
        }
        
        if (left == right) {
            return false;
        }
        
        return (arr[mid] > k) ? binarySearch(arr, k, left, mid - 1)
                                : binarySearch(arr, k, mid + 1, right);
    };
    
    int pivot = findPivot(arr, n, 0, n-1);
    
    if (pivot == -1) {
        return binarySearch(arr, k, 0, n - 1);
    }
    else {
        if (k >= arr[0]) {
            return binarySearch(arr, k, 0, pivot - 1);
        }
        else {
            return binarySearch(arr, k, pivot, n-1);
        }
    }
}

int main(int argc, const char * argv[]) {
    int arr[8] = {6,7,8,1,2,3,4,5};
    
    cout << searchRotated(arr, 8, 4);
}
