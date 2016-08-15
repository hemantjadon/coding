//
//  main.cpp
//  Simple Regex
//
//  Created by Hemant Jadon on 15/08/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

bool startingRegEx(string str,string pattern){
    if (str.length() < pattern.length()-1) {
        return false;
    }
    
    bool flag=true;
    int i=0;
    int j=1;
    for (; j<pattern.length(); i++,j++) {
        if (str[i] != pattern[j]) {
            flag = false;
            break;
        }
    }
    
    return flag;
}

bool endingRegEx(string str,string pattern){
    if (str.length() < pattern.length()-1) {
        return false;
    }
    
    bool flag = true;
    
    int i = int(str.length())-1;
    int j = int(pattern.length())-2
    ;
    
    for (; j>=0; i--,j--) {
        if (str[i] != pattern[j]) {
            flag = false;
            break;
        }
    }
    
    return flag;
}

bool otherRegEx(string str,string pattern){
    if (str.length() < pattern.length()) {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    string main_str;
    cin >> main_str;
    
    string pattern;
    cin >> pattern;
    
    
    if (pattern[0] == '^') {
        cout << startingRegEx(main_str, pattern) << endl;
    }
    
    else if (pattern[pattern.length()-1] == '$'){
        cout << endingRegEx(main_str,pattern) << endl;
    }
    
    else {
        cout << otherRegEx(main_str,pattern) << endl;
    }
}
