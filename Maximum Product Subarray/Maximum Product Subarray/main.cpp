//
//  main.cpp
//  Maximum Product Subarray
//
//  Created by Hemant Jadon on 31/07/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int productKadaneAlgorithm(vector<int> arr) {
    int maximum = arr[0];
    int prevMaxProduct = arr[0];
    int prevMinProduct = arr[0];
    
    for (int i = 0; i < arr.size(); i++) {
        int currentMaxProduct = max(arr[i], max(arr[i]*prevMaxProduct, arr[i]*prevMinProduct));
        int currentMinProduct = min(arr[i], min(arr[i]*prevMaxProduct, arr[i]*prevMinProduct));
        
        maximum = max(maximum, currentMaxProduct);
        
        prevMaxProduct = currentMaxProduct;
        prevMinProduct = currentMinProduct;
    }

    return maximum;
}

int main(int argc, const char * argv[]) {
    vector<int> arr = {-2, -3, 0, -2, -40};
    
    cout << productKadaneAlgorithm(arr) << endl;
}
