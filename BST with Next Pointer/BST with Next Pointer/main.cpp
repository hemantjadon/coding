//
//  main.cpp
//  BST with Next Pointer
//
//  Created by Hemant Jadon on 20/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
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
    
    /**
     * Next Points to InOrder Successor
     */
    void JoinInOrderNext(Node* root){
        if (root == NULL) {
            return;
        }
        
        Node* RST_leftmost = root->getRight();
        Node* LST_rightmost = root->getLeft();
        
        if (RST_leftmost) {
            while (RST_leftmost->getLeft() != NULL) {
                RST_leftmost = RST_leftmost->getLeft();
            }
            root->setNext(RST_leftmost);
        }
        
        if (LST_rightmost) {
            while (LST_rightmost->getRight() != NULL) {
                LST_rightmost = LST_rightmost->getRight();
            }
            LST_rightmost->setNext(root);
        }
        
        JoinInOrderNext(root->getLeft());
        JoinInOrderNext(root->getRight());
    }
    
    void JoinInOrderNext_UsingReverseInorder(Node* root, Node** prev){
        if (root == NULL) {
            return;
        }
        
        JoinInOrderNext_UsingReverseInorder(root->getRight(),prev);
        
        root->setNext(*(prev));
        *(prev) = root;
        
        JoinInOrderNext_UsingReverseInorder(root->getLeft(),prev);
        
    }
    
    
    
    /**
     * Next Points to LevelOrder Successor
     */
    void JoinLevelOrderNext(Node* root){
        if (root == NULL) {
            return;
        }
        
        queue<pair<Node*, int>> queue;
        
        pair<Node*, int> joint(root,1);
        queue.push(joint);
        
        Node* prev = NULL;
        int prev_level = 0;
        
        while (!queue.empty()) {
            pair<Node*, int> ref = queue.front();
            queue.pop();
            
            if (ref.second == prev_level) {
                prev->setNext(ref.first);
                prev = ref.first;
            }
            else {
                if (prev) {
                    prev->setNext(NULL);
                }
                prev = ref.first;
                prev_level = ref.second;
            }
            
            if (ref.first->getLeft()) {
                pair<Node*, int> joint(ref.first->getLeft(),ref.second+1);
                queue.push(joint);
            }
            if (ref.first->getRight()) {
                pair<Node*, int> joint(ref.first->getRight(),ref.second+1);
                queue.push(joint);
            }
        }
    }
    
    void JoinLevelOrderNext_CompleteBinaryTree(Node* root){
        if (root == NULL) {
            return;
        }
        
        if (root == this->getRoot()) {
            root->setNext(NULL);
        }
        root->getLeft()->setNext(root->getRight());
        if (root->getNext()) {
            root->getRight()->setNext(root->getNext()->getLeft());
        }
        else {
            root->getRight()->setNext(NULL);
        }
        
        JoinLevelOrderNext_CompleteBinaryTree(root->getLeft());
        JoinLevelOrderNext_CompleteBinaryTree(root->getRight());
    }
    
    void JoinLevelOrderNext_ConstantSpace_Recursive(Node* root){
        if (root == NULL) {
            return;
        }
        
        if (root == this->getRoot()) {
            root->setNext(NULL);
        }
        
        if (root->getLeft()) {
            root->getLeft()->setNext(this->getNextNode(root, root->getLeft()));
        }
        if (root->getRight()) {
            root->getLeft()->setNext(this->getNextNode(root, root->getLeft()));
        }
        
        JoinLevelOrderNext_ConstantSpace_Recursive(root->getLeft());
        JoinLevelOrderNext_ConstantSpace_Recursive(root->getRight());
    }
    
private:
    Node* getNextNode(Node* root,Node* forNode){
        if (root == NULL) {
            return NULL;
        }
        
        while (root) {
            if (root->getLeft()) {
                if (root->getLeft() != forNode) {
                    return root->getLeft();
                }
            }
            if (root->getRight()) {
                if (root->getRight() != forNode) {
                    return root->getRight();
                }
            }
            root = root->getNext();
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    BinarySearchTree tree;
    tree.CreateBST();
    tree.JoinLevelOrderNext_ConstantSpace_Recursive(tree.getRoot());
    tree.InOrderTraversal(tree.getRoot());
    cout << endl;
}
