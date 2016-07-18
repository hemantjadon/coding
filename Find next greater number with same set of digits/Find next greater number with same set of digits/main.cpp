//
//  main.cpp
//  Find next greater number with same set of digits
//
//  Created by Hemant Jadon on 18/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

void find_next(string str){
    unsigned long i = str.length()-1;
    while (i>=1) {
        if (str[i] < str[i+1]) {
            char ch = str[str.length()-1];
            str[str.length()-1] = str[i];
            str[i] = ch;
            string::iterator it;
            it = str.begin()+i+1;
            sort(it, str.end());
            cout << str << endl;
            break;
        }
        else {
            i--;
        }
    }
    if (i == 0) {
        cout << "Not Possible" << endl;
    }
}

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    
    
    find_next(str);
}
