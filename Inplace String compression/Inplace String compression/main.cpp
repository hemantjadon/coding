//
//  main.cpp
//  Inplace String compression
//
//  Created by Hemant Jadon on 29/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

string split_at_index(string &str,int idx){

    string tail;
    
    for (int i=idx+1; i<str.length(); i++) {
        tail+=str[i];
    }
    
    str.erase(str.begin()+idx+1,str.end());
    
    return tail;
}

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    
    long orig_length = str.length();
    
    int i=0;
    int j=1;
    
    int count=1;
    
    while (j<str.length()) {
        if (str[i] == str[j]) {
            count++;
            j++;
        }
        else {
            string tail = split_at_index(str, i);
            j = j - int(str.length());
            str += to_string(count);
            string tail2 = split_at_index(tail, j-1);
            j = j - int(tail.length());
            str += tail2;
            i=j;
            j=i+1;
            count=1;
        }
    }
    string tail = split_at_index(str, i);
    str += to_string(count);
    
    cout << str << endl;
}
