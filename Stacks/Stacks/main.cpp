//
//  main.cpp
//  Stacks
//
//  Created by Hemant Jadon on 25/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

bool areParenthesisBalanced(string str){
    stack<char> s;
    
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
        }
        if (str[i] == ')') {
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
            else {
                return false;
            }
        }
    }
    if (s.empty()) {
        return true;
    }
    else {
        return false;
    }
}

void insertAt_Bottom(stack<char> &s,char ch){
    if (s.empty()) {
        s.push(ch);
        return;
    }
    
    char lastchar = s.top();
    s.pop();
    insertAt_Bottom(s,ch);
    s.push(lastchar);
}

void reverseStack_Recursive(stack<char> &s){
    if(s.empty()){
        return;
    }
    
    char lastchar = s.top();
    cout << lastchar << endl;
    s.pop();
    reverseStack_Recursive(s);
    insertAt_Bottom(s,lastchar);
}

void insertAt_SortedPosition(stack<int> &s, int num){
    if (s.empty()) {
        s.push(num);
        return;
    }
    if (s.top() < num) {
        s.push(num);
        return;
    }
    
    int lastnum = s.top();
    s.pop();
    insertAt_SortedPosition(s, num);
    s.push(lastnum);
}

void sortStack_Recursive(stack<int> &s){
    if (s.empty()) {
        return;
    }
    
    int lastnum = s.top();
    s.pop();
    sortStack_Recursive(s);
    insertAt_SortedPosition(s, lastnum);
}

void stockSpan(int stock[],int n){
    stack<pair<int,int>> st;
    int span[n];
    
    for (int i=0; i<n; i++) {
        int sp = 0;
        pair<int, int> last;
        
        while (!st.empty() && st.top().first < stock[i]) {
            last = st.top();
            sp+=st.top().second;
            st.pop();
        }
        
        span[i] = sp + 1;
        
        pair<int, int> joint(stock[i],span[i]);
        st.push(joint);
    }
    
    for (int i=0; i<n; i++) {
        cout << span[i] << " ";
    }
}

void longestValidParenthesisString(string str){
    stack<pair<char, int>> st;
    
    int result = 0;
    int res_last_index = -1;
    
    int curr_value=0;
    int curr_index = -1;
    
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '(') {
            pair<char, int> joint('(',i);
            st.push(joint);
            curr_index = i;
        }
        else if (str[i] == ')') {
            if (!st.empty()) {
                pair<char, int> last = st.top();
                st.pop();
                
                if (curr_index == -1) {
                    curr_value = 2;
                    curr_index = i;
                }
                else if (curr_index+1 == i){
                    curr_index = i;
                    curr_value += 2;
                }
                else if(curr_index < last.second && curr_index > i) {
                    curr_index = i;
                    curr_value += 2;
                }
                else {
                    curr_value = 2;
                    curr_index = i;
                }
                
                if (curr_value > result) {
                    result = curr_value;
                    res_last_index = i;
                }
            }
        }
    }
    if (curr_value > result) {
        result = curr_value;
        res_last_index = curr_index;
    }
    cout << result << endl;
}

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    longestValidParenthesisString(str);
}
