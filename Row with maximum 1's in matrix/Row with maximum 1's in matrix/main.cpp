//
//  main.cpp
//  Row with maximum 1's in matrix
//
//  Created by Hemant Jadon on 28/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#define R 3
#define C 3
using namespace std;

int binary_search_first_index_of_1(int arr[],int low,int high){
    int index=-1;
    if (low > high) {
        return index;
    }
    
    int mid = low + (high-low)/2;
    
    if (arr[mid] == 1) {
        if (arr[mid-1] == 0 || mid == 0) {
            return mid;
        }
        else {
            return binary_search_first_index_of_1(arr, low, mid-1);
        }
    }
    else {
        return binary_search_first_index_of_1(arr, mid+1, high);
    }
}

int main(int argc, const char * argv[]) {
    int mat[R][C] = {
                        {0,0,1},
                        {0,1,1},
                        {1,1,1}
                    };
    
    int max_size = 0;
    int index_with_max_size = -1;
    int row_with_max_size=-1;
    
    for (int i=0; i<R; i++) {
        int idx = binary_search_first_index_of_1(mat[i], 0, C-1);
        if (idx != -1) {
            if (C-idx > max_size) {
                max_size = C-idx;
                index_with_max_size = idx;
                row_with_max_size = i;
            }
        }
    }
    
    cout << max_size << " " << index_with_max_size << " " << row_with_max_size << " " << endl;
}
