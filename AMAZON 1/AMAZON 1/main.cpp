//
//  main.cpp
//  AMAZON 1
//
//  Created by Hemant Jadon on 01/08/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

string compare(string str1,string str2){
    long len1 = str1.length();
    long len2 = str2.length();
    
    long i=0;
    
    while (i<len1 && i < len2) {
        if (str1[i] == str2[i]) {
            i++;
        }
        else if (str1[i] > str2[i]){
            return str2;
        }
        else {
            return str1;
        }
    }
    if (len1 < len2) {
        return str1;
    }
    else {
        return str2;
    }
}

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    
    string best_string = str;
    
    for (int i=0; i<str.length(); i++) {
        char first_char = str[0];
        
        str.erase(str.begin(),str.begin()+1);
        
        str += first_char;
        
        best_string = compare(str, best_string);
    }
    cout << best_string << endl;
}
