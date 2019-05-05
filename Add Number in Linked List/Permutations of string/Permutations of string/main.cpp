//
//  main.cpp
//  Permutations of string
//
//  Created by Hemant Jadon on 03/08/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int permuatations(string str, int start = 0) {
    int num = 0;
    
    if (start == str.length() - 1) {
        cout << str << endl;
        return 1;
    }
    
    for (int i = start; i < str.length(); i++) {
        swap(str[start], str[i]);
        num += permuatations(str, start + 1);
        swap(str[start], str[i]);
    }
    return num;
}

void nextPermutation(string str) {
    long i = str.length() - 2;
    for (; i >= 0; i--) {
        if (str[i] < str[i+1]) {
            break;
        }
    }
    
    if (i == -1) {
        cout << -1 << endl;
    }
    
    long ceiling = i + 1;
    
    for (long j = i; j < str.length(); j++) {
        if (str[i] < str[j]) {
            if (str[j] < str[ceiling]) {
                ceiling = j;
            }
        }
    }
    
    swap(str[i], str[ceiling]);
    sort(str.begin() + i + 1, str.end());
    
    cout << str;
}



void lexicographicPermutations(string str) {
    sort(str.begin(), str.end());
    
}

vector<vector<int> > permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    
    vector<vector<int>> v;
    
    v.push_back(A);
    
    function<vector<int> (vector<int>)> nextPermutation
    = [] (vector<int> A) -> vector<int> {
        long idx = A.size() - 2;
        for (; idx >=0; idx--) {
            if (A[idx] < A[idx + 1]) {
                break;
            }
        }
        
        if (idx == -1) {
            return vector<int>();
        }
        
        long ceiling = idx + 1;
        
        for (long j = ceiling; j < A.size(); j++) {
            if (A[idx] < A[j]) {
                if (A[j] < A[ceiling]) {
                    ceiling = j;
                }
            }
        }
        
        swap(A[ceiling], A[idx]);
        sort(A.begin() + idx + 1, A.end());
        return A;
    };
    
    vector<int> next = nextPermutation(A);
    
    v.push_back(A);
    
    while (next.size()) {
        v.push_back(next);
        next = nextPermutation(next);
    }
    
    return v;
}


int main(int argc, const char * argv[]) {
    string s = "13452";
    vector<int> v = {1, 2, 3};
}
