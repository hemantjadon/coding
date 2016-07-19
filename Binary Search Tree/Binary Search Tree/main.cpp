//
//  main.cpp
//  Binary Search Tree
//
//  Created by Hemant Jadon on 19/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Node{
private:
    int data;
    Node* left;
    Node* right;
    
public:
    //  Constructor
    Node(int data=0,Node* left=NULL,Node* right=NULL):data(data),left(left),right(right)
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
    
    void TopView(Node* root,Node* parent=NULL){
        if (root == NULL) {
            return;
        }
        
        if (parent == NULL) {
            TopView(root->getLeft(),root);
            cout << root->getData() << " ";
            TopView(root->getRight(),root);
        }
        else if (parent->getRight() == root){
            cout << root->getData() << " ";
            TopView(root->getRight(),root);
        }
        else if (parent->getLeft() == root){
            TopView(root->getLeft(),root);
            cout << root->getData() << " ";
        }
    }
    
    void LeftView(Node* root){
        if (root == NULL) {
            return;
        }
        
        queue<pair<Node*,int>> node_queue;
        pair<Node*, int> joint (root,1);
        node_queue.push(joint);
        
        int last_printed_level = 0;
        
        while (!node_queue.empty()) {
            Node* p = node_queue.front().first;
            int level = node_queue.front().second;
            node_queue.pop();
            
            if (level != last_printed_level) {
                cout << p->getData() << " ";
                last_printed_level = level;
            }
            
            if (p->getLeft()) {
                pair<Node*, int> joint(p->getLeft(),level+1);
                node_queue.push(joint);
            }
            if (p->getRight()) {
                pair<Node*, int> joint(p->getRight(),level+1);
                node_queue.push(joint);
            }
        }
    }
    
    void LevelOrderTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        queue<Node*> node_queue;
        node_queue.push(root);
        
        while (!node_queue.empty()) {
            Node* p = node_queue.front();
            node_queue.pop();
            
            cout << p->getData() << " ";
            if (p->getLeft()) {
                node_queue.push(p->getLeft());
            }
            if (p->getRight()) {
                node_queue.push(p->getRight());
            }
        }
    }
    
    // Construct Tree from traversals
    
    Node* Construct_from_PreOrder_and_InOrder(int preorder[],int inorder[],
                                             int low,int high,int* pre_index){
        if (low > high) {
            return NULL;
        }
        
        int in_index = __search(inorder, low, high, preorder[(*pre_index)]);
        if (in_index == -1) {
            return NULL;
        }
        (*pre_index)++;
        Node* left = Construct_from_PreOrder_and_InOrder(preorder, inorder, low, in_index-1, pre_index);
        Node* right = Construct_from_PreOrder_and_InOrder(preorder, inorder, in_index+1, high, pre_index);
        return new Node(inorder[in_index],left,right);
    }
    
    // Other Functions
    
    int size(Node* root){
        int s = 0;
        if (root == NULL) {
            return s;
        }
        s++;
        s += size(root->getLeft());
        s += size(root->getRight());
        return s;
    }
    
    Node* max(Node* root,Node* maxNode=NULL){
        if (root == NULL) {
            return maxNode;
        }
        
        if (maxNode) {
            if (maxNode->getData() < root->getData()) {
                maxNode = root;
            }
        }
        else {
            maxNode = root;
        }
        
        maxNode = max(root->getLeft(),maxNode);
        maxNode = max(root->getRight(),maxNode);
        
        return maxNode;
    }
    
    Node* min(Node* root,Node* minNode=NULL){
        if (root == NULL) {
            return minNode;
        }
        
        if (minNode) {
            if (minNode->getData() > root->getData()) {
                minNode = root;
            }
        }
        else {
            minNode = root;
        }
        
        minNode = min(root->getLeft(),minNode);
        minNode = min(root->getRight(),minNode);
        
        return minNode;
    }

    
    int height(Node* root){
        
        if (root == NULL) {
            return -1;
        }
        
        return __max(height(root->getLeft()), height(root->getRight()))+1;
    }
    
    void mirror(Node* root){
        if (root == NULL) {
            return;
        }
        
        Node* temp = root->getLeft();
        root->setLeft(root->getRight());
        root->setRight(temp);
        
        mirror(root->getLeft());
        mirror(root->getRight());
    }
    
    void levelSwap(Node* root,int level,int curr_level=1){
        if (root == NULL) {
            return;
        }
        
        if (level == curr_level) {
            Node* temp = root->getLeft();
            root->setLeft(root->getRight());
            root->setRight(temp);
            return;
        }
        
        levelSwap(root->getLeft(), level, curr_level+1);
        levelSwap(root->getRight(), level, curr_level+1);
    }
    
    
private:
    
    // Auxilary Functions
    int __max(int a,int b){
        if (a > b) {
            return a;
        }
        else {
            return b;
        }
    }
    
    int __search(int arr[],int low, int high,int el){
        for (int i=low; i<=high; i++) {
            if (arr[i] == el) {
                return i;
            }
        }
        return -1;
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
};

bool isIdentical(Node* root_1,Node* root_2){
    if (root_1 == NULL && root_2 == NULL) {
        return true;
    }
    
    if (root_1 == NULL || root_2 == NULL) {
        return false;
    }
    
    if (root_1 -> getData() != root_2->getData()) {
        return false;
    }
    
    bool a = isIdentical(root_1->getLeft(), root_2->getLeft());
    bool b = isIdentical(root_1->getRight(), root_2->getRight());
    
    if (a && b) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * Auxilary Tree : This tree derives from BST and is used for non conventional functions.
 * Eg. Traversals without recursion.
 */
class AuxilaryTree : public BinarySearchTree {
public:
    void InOrderTraversal_withoutRecursion(Node* root){
        if (root == NULL) {
            return;
        }
        stack<Node*> stack;
        
        while (root || !stack.empty()) {
            if (root) {
                stack.push(root);
                root = root->getLeft();
            }
            else {
                root = stack.top();
                stack.pop();
                cout << root->getData() << " ";
                root = root->getRight();
            }
        }
    }
    
    void PreOrderTraversal_withoutRecursion(Node* root){
        if (root == NULL) {
            return;
        }
        
        stack<Node*> stack;
        
        while (root || !stack.empty()) {
            if (root) {
                cout << root->getData() << " ";
                stack.push(root);
                root = root->getLeft();
            }
            else {
                root = stack.top();
                stack.pop();
                root = root->getRight();
            }
        }
    }
    
    /** 
     * In-order Traversal without recursion and without stack 
     * This algorithm uses property of Threaded Binary Tree
     * that each nodes right child is its In-order Successor.
     */
    void MorrisTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        while (root != NULL) {
            if (root->getLeft() == NULL) {
                cout << root->getData() << " ";
                root = root->getRight();
            }
            else {
                //  Finding In order Predecssor of root.
                //  Which is rightmost child of left subtree of root.
                
                Node* predecessor = root->getLeft();
                while (predecessor->getRight() != NULL && predecessor->getRight() != root) {
                    predecessor = predecessor->getRight();
                }
                
                if (predecessor -> getRight() == NULL) {
                    predecessor->setRight(root);
                    root = root->getLeft();
                }
                
                else {
                    predecessor->setRight(NULL);
                    cout << root->getData() << " ";
                    root = root->getRight();
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    BinaryTree tree;
    int preorder[] = {10,5,2,7,6,12,15,13};
    int inorder[] = {2,5,6,7,10,12,13,15};
    int pre_index=0;
    int n = sizeof(inorder)/sizeof(int);
    tree.setRoot(tree.Construct_from_PreOrder_and_InOrder(preorder, inorder, 0, n-1, &pre_index));
    tree.InOrderTraversal(tree.getRoot());
    cout << endl;
    tree.PreOrderTraversal(tree.getRoot());
    cout << endl;
    tree.PostOrderTraversal(tree.getRoot());
    cout << endl;
}

