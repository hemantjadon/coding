//
//  main.cpp
//  ADOBE 1
//
//  Created by Hemant Jadon on 28/07/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    string s = "CURD";
    
    for (int i = 0; i< s.length(); i++) {
        cout << int(s[i]) - int('A') + 1 << endl;
    }
}
