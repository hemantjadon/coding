//
//  main.cpp
//  String combinations
//
//  Created by Hemant Jadon on 27/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

void StringCombinations(string str,int low,int high,int len=1,string output=""){
    if (low > high) {
        cout << output << endl;
        return;
    }
    
    for (int k=low; k<low+len; k++) {
        output += str[k];
    }
    output += " ";
    
    StringCombinations(str,low+len,high,1,output);
    for (int k=0; k<=len; k++) {
        output.pop_back();
    }
    
    if (low + len <= high) {
        StringCombinations(str, low, high, len+1,output);
    }
}

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    
    StringCombinations(str,0,int(str.length()-1));
}
