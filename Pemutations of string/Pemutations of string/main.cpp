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


/**
 * The Data String here is the key.
 * The characters are added to this string in repetetive fashion.
 * ie. initially the string is empty then in each iterations a character
 * is added to the 'data' string cycling through the whole string.
 * When the index reaches the length of string then it is printed.
 * For : str= "ab" : Recursion stack will be :
 *
 *                         data=""   (index=0)
                          /       \
                         /         \
                        /           \
                  data="a"          data="b"  (index = 1)
                 /       \          /      \
                /         \        /        \
         data="aa"     data="ab"  /          \
                                 /            \
                             data="ba"       data="bb"   (index=2)
 */
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


/**
 * The basic code is quite same to the simple permutation.
 * We just do not swap if the characters are same and continuethe loop.
 */
int Permutations_without_Duplicates(string str,int i=0){
    int num=0;
    if (i == str.length()) {
        cout << str << endl;
        return num+1;
    }
    
    num += Permutations_without_Duplicates(str,i+1);
    
    for (int j=i; j<str.length(); j++) {
        
        if (str[i] == str[j]) {
            continue;
        }
        
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        
        num += Permutations_without_Duplicates(str,i+1);
        
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
    return num;
}


int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    cout << "---" << endl;
    cout << Permutations(str) << endl;
}
