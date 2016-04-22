//
//  main.cpp
//  AVL Tree
//
//  Created by Hemant Jadon on 08/03/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node* left;
    Node* right;
    int height;
    
public:
    //Constructors
    Node(int d=0,Node* l=NULL,Node* r=NULL,int h=1):data(d),left(l),right(r),height(h)
    {};
    
    //Getters
    int getData() const {
        return data;
    };
    
    Node* getLeft() const {
        return left;
    };
    
    Node* getRight() const {
        return right;
    };
    
    int getHeight() const {
        return height;
    };
    
    
    //Setters
    void setData(int d){
        data = d;
    };
    
    void setLeft(Node* l){
        left = l;
    };
    
    void setRight(Node* r){
        right = r;
    };
    void setHeight(int h){
        height = h;
    };
};

class AVLTree{
private:
    Node* root;
    
public:
    //Constructor
    AVLTree():root(NULL)
    {};
    
    //Setter
    void setRoot(Node* r){
        root = r;
    };
    
    //Getter
    Node* getRoot() const {
        return root;
    };
    
    //Functions
    
};

int main(int argc, const char * argv[]) {
    
}
