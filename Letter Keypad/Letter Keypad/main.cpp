//
//  main.cpp
//  Letter Keypad
//
//  Created by Hemant Jadon on 05/08/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> letterCombinations(string A) {
    string MAP[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    
    vector<int> digits;
    
    for (int i = 0; i < A.length(); i++) {
        digits.push_back(int(A[i]) - 48);
    }
    
    function<void (vector<int>, string, int)> recur
    = [&] (vector<int> digits, string str, int curr) {
        if (digits.size() == str.length()) {
            ans.push_back(str);
            return;
        }
        
        for (int i = 0; i < MAP[digits[curr]].length(); i++) {
            recur(digits, str + MAP[digits[curr]][i], curr + 1);
        }
    };
    
    recur(digits, "", 0);
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<string> s = letterCombinations("23");
    
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
}
