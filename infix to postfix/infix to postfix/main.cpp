//
//  main.cpp
//  infix to postfix
//
//  Created by Hemant Jadon on 01/03/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool checkPrecedence(char a,char b){
    if (a== '+') {
        if (b=='+' || b=='-' || b=='*' || b=='/') {
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (a== '-') {
        if (b=='+' || b=='-' || b=='*' || b=='/') {
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (a== '*') {
        if (b=='*' || b=='/') {
            return 0;
        }
        else{
            return 1;
        }
    }
    
    else if (a== '/') {
        if (b=='*' || b=='/') {
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (b=='('){
        return 1;
    }
    return 0;
}

bool isOperator(char a){
    if (a == '(' || a == ')' || a == '+' || a == '-' || a == '*' || a == '/') {
        return true;
    }
    else{
        return false;
    }
}

int main(int argc, const char * argv[]) {
    char infix[100];
    stack<char> op;
    queue<char> postfix;
    cin.getline(infix, 100);
    int i=0;
    while (infix[i] != '\0') {
        if (isOperator(infix[i])) {
            if (infix[i] == '(') {
                op.push('(');
            }
            else if (infix[i] == ')'){
                while (op.top() != '(') {
                    postfix.push(op.top());
                    op.pop();
                }
                op.pop();
            }
            else{
                if (!op.empty()) {
                    while (!checkPrecedence(infix[i], op.top())) {
                        postfix.push(op.top());
                        op.pop();
                        if(op.empty()){
                            break;
                        }
                    }
                    op.push(infix[i]);
                }
                else{
                    op.push(infix[i]);
                }
            }

        }
        else{
            postfix.push(infix[i]);
        }
        i++;
    }
    while (!op.empty()) {
        if (op.top() != '(') {
            postfix.push(op.top());
            op.pop();
        }
        else{
            op.pop();
            cout << "Parenthesis error !!" << endl;
            exit(101);
        }
    }
    while (!postfix.empty()) {
        cout << postfix.front();
        postfix.pop();
    }
}
