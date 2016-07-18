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

const string Mapping[10] = {"","","abc","def","ghi","jkl","m no","pqrs","tuv","wxyz"};

void telephonic_keypad(int number[],int n,int curr_digit=0, string output=""){
    if (curr_digit == n) {
        cout << output << endl;
        return;
    }
    for (int i=0; i < Mapping[number[curr_digit]].length(); i++) {
        output += Mapping[number[curr_digit]][i];
        telephonic_keypad(number,n,curr_digit+1,output);
        output.pop_back();
    }
    
}

int main(int argc, const char * argv[]) {
    int number[] = {1,2};
    telephonic_keypad(number,2);
}
