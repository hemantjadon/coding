//
//  main.cpp
//  Selection Sort
//
//  Created by Hemant Jadon on 22/05/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    
    
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}
