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

void Substrings(string str, int i=0, int j=0){
    if (i > str.length() || j > str.length()) {
        return;
    }
    
    for (int k=i; k<=j; k++) {
        cout << str[k];
    }
    cout << endl;

    if (j >= str.length()-1) {
        Substrings(str,i+1,i+1);
    }
    else {
        Substrings(str,i,j+1);
    }

}

void Substrings_2(string str,int i=0 ,int j=0, int diff=0){
    if (j >= str.length() || diff >= str.length()) {
        return;
    }
    for (int k=i; k<=j; k++) {
        cout << str[k];
    }
    cout << endl;
    
    if (j>= str.length()-1) {
        diff++;
        i=0;
        Substrings_2(str,i,i+diff,diff);
    }
    else{
        Substrings_2(str,i+1,j+1,diff);
    }
}

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    Substrings_2(str);
}
