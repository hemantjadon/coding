//
//  main.cpp
//  postfix to infix
//
//  Created by Hemant Jadon on 02/03/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char a){
    if (a == '(' || a == ')' || a == '+' || a == '-' || a == '*' || a == '/') {
        return true;
    }
    else{
        return false;
    }
}


int main(int argc, const char * argv[]) {
    char postfix[100];
    cin.getline(postfix, 100);
    
    stack<string> aux;
    
    int i=0;
    while (postfix[i] != '\0') {
        if (isOperator(postfix[i])) {
            
            string b = aux.top();
            aux.pop();
            
            string a = aux.top();
            aux.pop();
            
            string oper(1,postfix[i]);
            
            string openingBrace(1,'(');
            
            string closingBrace(1,')');
            
            string final;
            final = openingBrace + a + oper + b + closingBrace;
            
            aux.push(final);
        }
        else{
            string temp(1,postfix[i]);
            aux.push(temp);
        }
        i++;
    }
    cout << aux.top() << endl;
}
