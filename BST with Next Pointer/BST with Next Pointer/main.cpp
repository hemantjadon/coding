//
//  main.cpp
//  BST with Next Pointer
//
//  Created by Hemant Jadon on 20/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Node{
private:
    int data;
    Node* left;
    Node* right;
    Node* next;
    
public:
    //  Constructor
    Node(int data=0,Node* left=NULL,Node* right=NULL,Node*next=NULL):
    data(data),left(left),right(right),next(NULL)
    {}
    
    
    //  Setters
    
    void setData(int data){
        this->data = data;
    }
    
    void setLeft(Node* left){
        this->left = left;
    }
    
    void setRight(Node* right){
        this->right = right;
    }
    
    void setNext(Node* next){
        this->next = next;
    }
    
    //  Getters
    
    int getData() const {
        return this->data;
    }
    
    Node* getLeft() const {
        return this->left;
    }
    
    Node* getRight() const {
        return this->right;
    }
    
    Node* getNext() const {
        return next;
    }
};

class BinaryTree{
private:
    Node* root;
    
public:
    //  Constructor
    BinaryTree(Node* root=NULL):root(NULL)
    {}
    
    
    //  Setters
    
    void setRoot(Node* root){
        this->root = root;
    }
    
    
    //  Getters
    
    Node* getRoot() const {
        return this->root;
    }
    
    
    //  Creators
    
    void CreateTree(){
        vector<vector<Node*>> matrix;
        
        int value = 0;
        bool flag = false;
        int i=0;
        do {
            flag = false;
            vector<Node*> level;
            for (int j=0; j<pow(2,i); j++) {
                cin >> value;
                if (value != -1) {
                    flag = true;
                    Node* temp = new Node(value);
                    level.push_back(temp);
                }
                else{
                    level.push_back(NULL);
                }
            }
            matrix.push_back(level);
            i++;
        } while (flag);
        
        for (int x=0; x<matrix.size(); x++) {
            for (int y=0; y<matrix[x].size(); y++) {
                if (matrix[x][y] == NULL) {
                    continue;
                }
                matrix[x][y]->setLeft(matrix[x+1][2*y]);
                matrix[x][y]->setRight(matrix[x+1][2*y+1]);
            }
        }
        this->setRoot(matrix[0][0]);
    }
    
    
    //  Traversals
    
    void InOrderTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        InOrderTraversal(root->getLeft());
        cout << root->getData() << " ";
        InOrderTraversal(root->getRight());
    }
    
    void PreOrderTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        cout << root->getData() << " ";
        PreOrderTraversal(root->getLeft());
        PreOrderTraversal(root->getRight());
    }
    
    void PostOrderTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        PostOrderTraversal(root->getLeft());
        PostOrderTraversal(root->getRight());
        cout << root->getData() << " ";
    }
};

class BinarySearchTree : public BinaryTree{
public:
    void CreateBST(){
        int n;
        cin >> n;
        
        while (n != -1) {
            Node* temp = new Node(n);
            
            if (this->getRoot() == NULL) {
                this->setRoot(temp);
            }
            
            else {
                Node* root_1 = this->getRoot();
                
                while (1) {
                    if (n > root_1 -> getData()) {
                        if (root_1->getRight() == NULL) {
                            root_1->setRight(temp);
                            break;
                        }
                        else {
                            root_1 = root_1->getRight();
                        }
                    }
                    else {
                        if (root_1 -> getLeft() == NULL) {
                            root_1->setLeft(temp);
                            break;
                        }
                        else {
                            root_1 = root_1->getLeft();
                        }
                    }
                }
            }
            
            cin >> n;
        }
    }
    
    void insert(Node* root,int value){
        Node* temp = new Node(value);
        
        if (root == NULL) {
            this->setRoot(temp);
        }
        
        else {
            Node* root_1 = this->getRoot();
            
            while (1) {
                if (value > root_1 -> getData()) {
                    if (root_1->getRight() == NULL) {
                        root_1->setRight(temp);
                        break;
                    }
                    else {
                        root_1 = root_1->getRight();
                    }
                }
                else {
                    if (root_1 -> getLeft() == NULL) {
                        root_1->setLeft(temp);
                        break;
                    }
                    else {
                        root_1 = root_1->getLeft();
                    }
                }
            }
        }
    }
    
    void JoinNext(){
        Node* root = this->getRoot();
        
        if (root == NULL) {
            return;
        }
        
        while (root != NULL) {
            if (root->getLeft() == NULL) {
                if (root->getNext() == NULL) {
                    root->setNext(root->getRight());
                }
                root = root->getRight();
            }
            else {
                Node* predecessor = root->getLeft();
                while (predecessor->getRight() != NULL && predecessor->getRight() !=root) {
                    predecessor = predecessor->getRight();
                }
                
                if (predecessor->getRight() == NULL) {
                    predecessor->setNext(root);
                    predecessor->setRight(root);
                    root = root->getLeft();
                }
                else {
                    predecessor->setRight(NULL);
                    if (root->getNext() == NULL) {
                        root->setNext(root->getRight());
                    }
                    root = root->getRight();
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    BinarySearchTree tree;
    tree.CreateBST();
    tree.JoinNext();
    tree.InOrderTraversal(tree.getRoot());
    cout << endl;
}
