//
//  main.cpp
//  prefix to infix
//
//  Created by Hemant Jadon on 02/03/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int strlen(char arr[]){
    int i=0;
    while (arr[i]!='\0') {
        i++;
    }
    return i;
}

void reverseString(char arr[]){
    int i=0;
    int j = strlen(arr)-1;
    
    while (i<j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
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
    char prefix[100];
    
    stack<string> aux;
    cin.getline(prefix, 100);
    
    reverseString(prefix);
    
    int i=0;
    while (prefix[i] != '\0') {
        if (isOperator(prefix[i])) {
            string a = aux.top();
            aux.pop();
            
            string b = aux.top();
            aux.pop();
            
            string oper(1,prefix[i]);
            
            string openingBrace(1,'(');
            
            string closingBrace(1,')');
            
            string final =  openingBrace + a + oper + b + closingBrace;
            
            aux.push(final);
        }
        else{
            string temp(1,prefix[i]);
            aux.push(temp);
        }
        i++;
    }
    cout << aux.top() << endl;
}
