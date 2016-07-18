//
//  main.cpp
//  Postfix Expression Evaluation
//
//  Created by Hemant Jadon on 18/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

bool is_operator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return true;
    }
    else {
        return false;
    }
}

int evaluate(char lt,char rt,char op){
    
    int i_lt = int(lt-47-1);
    int i_rt = int(rt-47-1);
    switch (op) {
        case '+':
            return i_lt + i_rt;
        case '-':
            return i_lt - i_rt;
        case '*':
            return i_lt * i_rt;
        case '/':
            return i_lt / i_rt;
        default:
            return 0;
    }
}

int Eval_Postfix(string str){
    stack<char> stack;
    
    string::iterator it;
    
    for (it=str.begin(); it<str.end(); it++) {
        if (is_operator(*it)) {
            char rt = stack.top();
            stack.pop();
            char lt = stack.top();
            stack.pop();
            int eval = evaluate(lt,rt,(*it));
            stack.push(char(eval)+47+1);
        }
        else {
            stack.push(*it);
        }
    }
    
    return char(stack.top()-47-1);
}

int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    cout << Eval_Postfix(str);
}
