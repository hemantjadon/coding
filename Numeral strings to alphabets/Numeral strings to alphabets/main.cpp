//
//  main.cpp
//  Numeral strings to alphabets
//
//  Created by Hemant Jadon on 18/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

char convert(int n){
    if(n <= 26 && n >= 1){
        return char(n+97-1);
    }
    else {
        return '\0';
    }
}

int numeral_strings_to_alphabets(string str,int index=0,string output=""){
    int num=0;
    
    if (index == str.length()) {
        cout << output<<endl;
        return num+1;
    }
    
    for (int diff=0; diff+index<str.length(); diff++) {
        string origData = output;
        
        string toConvert = "";
        for (int i=index; i<=index+diff; i++) {
            toConvert+=str[i];
        }
        
        char converted = convert(stoi(toConvert));
        
        if (converted == '\0') {
            continue;
        }
        
        output += converted;
        num += numeral_strings_to_alphabets(str,index+diff+1,output);
        output = origData;
    }
    
    return num;
}

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    numeral_strings_to_alphabets(str);
}
