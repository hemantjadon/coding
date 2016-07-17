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

int Permutations(string str,int i=0){
    int num = 0;
    if (i == str.length()-1) {
        cout << str << endl;;
        return num+1;
    }
    
    for (int k=i; k<str.length(); k++) {
        char ch = str[i];
        str[i] = str[k];
        str[k]=ch;
        
        num += Permutations(str,i+1);
        
        ch = str[i];
        str[i] = str[k];
        str[k]=ch;
    }
    return num;
}

int Permutations_with_Repetetion(string str,int index=0,string data=""){
    int num=0;
    
    if (index == str.length()) {
        cout << data << endl;
        return num+1;
    }
    
    for (int i=0; i<str.length(); i++) {
        string origData = data;
        data += str[i];
        num += Permutations_with_Repetetion(str,index+1,data);
        data=origData;
    }
    return num;
}


int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    cout << "---" << endl;
    cout << Permutations_with_Repetetion(str) << endl;
}
