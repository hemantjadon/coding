//
//  main.cpp
//  Substrings
//
//  Created by Hemant Jadon on 16/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void Substrings(string str, int i=0, int j=0, int diff=0){
    if (j == str.length()) {
        return;
    }
    
    for (int k = i; k<=j; k++) {
        cout << str[k];
    }
    cout << endl;
    
    Substrings(str,i+1,j+1,diff);
    diff++;
    i=0;
    Substrings(str,i,i+diff,diff);
}

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    Substrings(str);
}
