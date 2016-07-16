//
//  main.cpp
//  Pemutations of string
//
//  Created by Hemant Jadon on 10/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void Permutations(string str,int i,int j){
    if (i > j) {
        cout << str << endl;
        return;
    }
    
    Permutations(str,i+1,j);
    char ch = str[j];
    str[j]=str[i];
    str[i]=ch;
    Permutations(str, i, j);
    ch = str[j];
    str[j]=str[i];
    str[i]=ch;
}

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    Permutations(str,0,str.length()-1);
}
