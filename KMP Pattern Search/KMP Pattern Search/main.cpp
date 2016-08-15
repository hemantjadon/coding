//
//  main.cpp
//  KMP Pattern Search
//
//  Created by Hemant Jadon on 15/08/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> PrefixArray(string pattern){
    vector<int> pref_arr(pattern.length());
    
    int i=1;
    int j=0;
    
    pref_arr[0] = 0;
    
    while (i<pattern.length()) {
        if (pattern[i] == pattern[j]) {
            pref_arr[i] = j+1;
            i++;
            j++;
        }
        else {
            while (j >= 0) {
                if (pattern[j] == pattern[i]) {
                    pref_arr[i] = j+1;
                    break;
                }
                else {
                    if (j == 0) {
                        break;
                    }
                    j = pref_arr[j-1];
                }
            }
            i++;
        }
    }
    
    return pref_arr;
}

vector<int> KMP(string text,string pattern){
    // Making Prefix Array
    vector<int> pref_arr = PrefixArray(pattern);
    
    // Using Prefix array in pattern searching
    vector<int> indices;
    
    for (int i=0,j=0; i<text.size(); i++) {
        if (text[i] == pattern[j]) {
            j++;
            if (j == pattern.size()) {
                indices.push_back(i-int(pattern.size())+1);
                j=0;
            }
        }
        else {
            j = pref_arr[j];
        }
    }
    
    return indices;
}

int main(int argc, const char * argv[]) {
    string text;
    cin >> text;
    
    string pattern;
    cin >> pattern;
    
    vector<int> indices = KMP(text,pattern);
    for (int i=0; i<indices.size(); i++) {
        cout << indices[i] << " ";
    }
    cout << endl;
}
