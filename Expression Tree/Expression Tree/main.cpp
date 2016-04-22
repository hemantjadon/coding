//
//  main.cpp
//  Expression Tree
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

class Node{
private:
    char value;
    Node* left;
    Node* right;
    
public:
    Node(){
        value = '\0';
        left = NULL;
        right = NULL;
    }
    
    void setValue(char a){
        value = a;
        
    }
    
    void setLeft(Node* l){
        left = l;
    }
    
    void setRight(Node* r){
        right = r;
    }
    
    char getValue(){
        return value;
    }
    
    Node* getLeft(){
        return left;
    }
    
    Node* getRight(){
        return right;
    }
};

void InorderTraversal(Node* root){
    if (root==NULL) {
        return;
    }
    InorderTraversal(root->getLeft());
    cout << root->getValue();
    InorderTraversal(root->getRight());
}

int main(int argc, const char * argv[]) {
    char postfix[100];
    stack<Node*> aux;
    cin.getline(postfix, 100);
    int i=0;
    while (postfix[i] != '\0') {
        Node*temp = new Node;
        temp->setValue(postfix[i]);
        
        if (isOperator(postfix[i])) {
            Node* right = aux.top();
            aux.pop();
            
            Node* left = aux.top();
            aux.pop();
            
            temp->setRight(right);
            temp->setLeft(left);
            aux.push(temp);
        }
        else{
            aux.push(temp);
        }
        i++;
    }
    Node* root = NULL;
    if (!aux.empty()) {
        root = aux.top();
        aux.pop();
    }
    
    InorderTraversal(root);
}
