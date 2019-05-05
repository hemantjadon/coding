//
//  main.cpp
//  Telephonic Keypad
//
//  Created by Hemant Jadon on 17/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

const string Mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void telephonic_keypad(int number[],int n,int curr_num=0,string output=""){
    if (output.length() == n) {
        cout << output << endl;
        return;
    }
    
    for (int i=0; i<Mapping[number[curr_num]].length(); i++) {
        output += Mapping[number[curr_num]][i];
        telephonic_keypad(number, n, curr_num+1, output);
        output.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    int number[] = {1,2};
    int n = sizeof(number)/sizeof(number[0]);
    telephonic_keypad(number, n);
}
