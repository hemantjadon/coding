//
//  main.cpp
//  Largest square of 1s
//
//  Created by Hemant Jadon on 03/08/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    int S[m][n];
    
    for (int i = 0; i < m; i++) {
        S[i][0] = arr[i][0];
    }
    
    for (int j = 0; j < n; j++) {
        S[0][j] = arr[0][j];
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[i][j]) {
                S[i][j] = max(S[i-1][j-1], max(S[i-1][j], S[i][j-1])) + 1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }
    
    int maximum = INT_MIN;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            maximum = max(maximum, S[i][j]);
        }
    }
    
    cout << maximum;
}
