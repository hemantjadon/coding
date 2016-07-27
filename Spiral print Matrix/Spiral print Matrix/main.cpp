//
//  main.cpp
//  Spiral print Matrix
//
//  Created by Hemant Jadon on 27/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//


#include <iostream>
#define M 3
#define N 3
using namespace std;


void spiralPrint(int mat[M][N]){
    int k=0;
    int l=0;
    int m=M-1;
    int n=N-1;
    
    while (k <= m && l <= n) {
        //  Print first of remaining rows.
        for (int i=l; i<=n; i++) {
            cout << mat[k][i] << " ";
        }
        k++;
        
        //  Print last of remaining columns
        for (int i=k; i<=m; i++) {
            cout << mat[i][n] << " ";
        }
        n--;
        
        //  Print last of remaining rows in reverse
        if (k < m) {
            for (int i=n; i>=l; i--) {
                cout << mat[m][i] << " ";
            }
            m--;
        }
        
        //  Print fist of remaining columns in reverse.
        if (l < n) {
            for (int i=m; i>=k; i--) {
                cout << mat[i][l] << " ";
            }
            l++;
        }
    }
}

int main(int argc, const char * argv[]) {
    int mat[M][N]={0};
    int k=1;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            mat[i][j]=k;
            k++;
        }
    }
    spiralPrint(mat);
}
