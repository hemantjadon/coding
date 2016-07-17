//
//  main.cpp
//  Reverse Individual Words
//
//  Created by Hemant Jadon on 17/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string reverse(string str){
    for (int i=0,j=str.length()-1; i<j; i++,j--) {
        char ch = str[j];
        str[j] = str[i];
        str[i] = ch;
    }
    return str;
}

vector<string> split(string str,char ch=' '){
    vector<string> vct;
    string word = "";
    
    for (int i=0; i<=str.length(); i++) {
        if (str[i] == ch || str[i] == '\0') {
            vct.push_back(word);
            word = "";
        }
        else{
            word += str[i];
        }
    }
    return vct;
}

string join(vector<string> vct,char ch=' '){
    string str;
    
    for (int i=0; i<vct.size(); i++) {
        str += vct[i];
        str += ch;
    }
    str.pop_back();
    return str;
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin,str);
    
    vector<string> vct = split(str,' ');
    
    for (int i=0; i<vct.size(); i++) {
        vct[i] = reverse(vct[i]);
    }
    
    cout << reverse(join(vct,' '));
}
