//
//  main.cpp
//  trees
//
//  Created by Hemant Jadon on 25/07/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <vector>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;
    
public:
    Node(int data = 0, Node* left = NULL, Node* right = NULL):
        data(data), left(left), right(right) { }
    
    int const getData() {
        return this->data;
    }
    
    Node* const getLeft() {
        return this->left;
    }
    
    Node* const getRight() {
        return this->right;
    }
    
    void setData(int data) {
        this->data = data;
    }
    
    void setLeft(Node* left) {
        this->left = left;
    }
    
    void setRight(Node* right) {
        this->right = right;
    }
};

class Tree {
private:
    Node* root;
    
public:
    Tree(Node* root = NULL): root(root) { }
    
    void setRoot(Node* root) {
        this->root = root;
    }
    
    Node* const getRoot() {
        return this->root;
    }
    
    void createTree() {
        int d;
        cin >> d;
        if (d == -1) {
            return;
        }
        this->root = new Node(d);
        
        queue<Node*> nodeQ;
        
        nodeQ.push(this->root);
        
        while (!nodeQ.empty()) {
            Node* parent = nodeQ.front();
            nodeQ.pop();
            
            cin >> d;
            
            if (d != -1) {
                Node* temp = new Node(d);
                parent->setLeft(temp);
                nodeQ.push(temp);
            }
            
            cin >> d;
            
            if (d != -1) {
                Node* temp = new Node(d);
                parent->setRight(temp);
                nodeQ.push(temp);
            }
        }
    }
    
    void const printInorder(Node* root) {
        if (root == NULL) {
            return;
        }
        
        printInorder(root->getLeft());
        cout << root->getData();
        printInorder(root->getRight());
    }
    
    void const printPreorder(Node* root) {
        if (root == NULL) {
            return;
        }
        
        cout << root->getData();
        printInorder(root->getLeft());
        printInorder(root->getRight());
    }
    
    void const printPostorder(Node* root) {
        if (root == NULL) {
            return;
        }
        
        printInorder(root->getLeft());
        printInorder(root->getRight());
        cout << root->getData();
    }
    
    void const printLevelOrder(Node* root) {
        queue<Node*> nodeQ;
        
        if (root) {
            nodeQ.push(root);
            
            while (!nodeQ.empty()) {
                Node* root = nodeQ.front();
                nodeQ.pop();
                cout << root->getData();
                if (root->getLeft()) {
                    nodeQ.push(root->getLeft());
                }
                if (root->getRight()) {
                    nodeQ.push(root->getRight());
                }
            }
        }
    }
    
    void const printVerticalOrder(Node* root) {
        map<int, vector<Node*>> m;
        
        std::function<void (Node*, int)> recur
            = [&](Node* root, int disp) -> void {
                if (root == NULL) {
                    return;
                }
                
                auto it = m.find(disp);
                if (it != m.end()) {
                    it->second.push_back(root);
                }
                else {
                    vector<Node*> v;
                    v.push_back(root);
                    m.insert(pair<int, vector<Node*>>(disp, v));
                }
                recur(root->getLeft(), disp + 1);
                recur(root->getRight(), disp - 1);
            };
        
        recur(root, 0);
        
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            for (auto jt = it->second.begin(); jt != it->second.end(); ++jt) {
                cout << (*jt)->getData();
            }
        }
    }
    
    void const topView(Node* root) {
        map<int, Node*> m;
        
        std::function<void (Node*, int)> recur
            = [&](Node* root, int disp) -> void {
                if (root == NULL) {
                    return;
                }
                
                auto it = m.find(disp);
                if (it == m.end()) {
                    m.insert(pair<int, Node*>(disp, root));
                }
                recur(root->getLeft(), disp + 1);
                recur(root->getRight(), disp - 1);
            };
        
        recur(root, 0);
        
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            cout << it->second->getData();
        }
    }
    
    void const leftView(Node* root) {
        map<int, Node*> m;
        
        std::function<void (Node*, int)> recur
            = [&](Node* root, int level) -> void {
                if (root == NULL) {
                    return;
                }
                
                auto it = m.find(level);
                if (it == m.end()) {
                    m.insert(pair<int, Node*>(level, root));
                }
                recur(root->getLeft(), level + 1);
                recur(root->getRight(), level + 1);
            };
        
        recur(root, 0);
        
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            cout << it->second->getData();
        }
    }
    
    void const rightView(Node* root) {
        map<int, Node*> m;
        
        std::function<void (Node*, int)> recur
            = [&](Node* root, int level) -> void {
                if (root == NULL) {
                    return;
                }
                
                m[level] = root;
                
                recur(root->getLeft(), level + 1);
                recur(root->getRight(), level + 1);
            };
        
        recur(root, 0);
        
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            cout << it->second->getData();
        }
    }
    
    void const bottomView(Node* root) {
        map<int, Node*> m;
        
        std::function<void (Node*, int)> recur
            = [&](Node* root, int disp) -> void {
                if (root == NULL) {
                    return;
                }
                
                m[disp] = root;
                
                recur(root->getLeft(), disp + 1);
                recur(root->getRight(), disp - 1);
            };
        
        recur(root, 0);
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            cout << it->second->getData();
        }
    }
    
    void const boundaryTraversal(Node* root) {
        std::function<void (Node*)> printLeftBoundary
            = [&](Node* root) -> void {
                if (root->getLeft() == NULL && root->getRight() == NULL) {
                    return;
                }
                
                cout << root->getData();
                if (root->getLeft()) {
                    printLeftBoundary(root->getLeft());
                }
                else if (root->getRight()) {
                    printLeftBoundary(root->getRight());
                }
            };
        
        std::function<void (Node*)> printLeafNodes
            = [&](Node* root) -> void {
                if (root == NULL) {
                    return;
                }
                
                printLeafNodes(root->getLeft());
                if (!root->getLeft() && !root->getRight()) {
                    cout << root->getData();
                }
                printLeafNodes(root->getRight());
            };
        
        std::function<void (Node*)> printRightBoundary
            = [&](Node* root) -> void {
                if (root->getLeft() == NULL && root->getRight() == NULL) {
                    return;
                }
                
                if (root->getRight()) {
                    printRightBoundary(root->getRight());
                }
                else if (root->getLeft()) {
                    printRightBoundary(root->getLeft());
                }
                cout << root->getData();
            };
        
        printLeftBoundary(root);
        printLeafNodes(root);
        printRightBoundary(root);
    }
    
    void const inorderWithoutRecursion(Node* root) {
        stack<Node*> s;
        
        std::function<void (Node*)> pushLeftSubTree
            = [&] (Node* root) {
                while (root) {
                    s.push(root);
                    root = root->getLeft();
                }
            };
        
        while (true) {
            pushLeftSubTree(root);
            
            if (!s.empty()) {
                root = s.top();
                s.pop();
                cout << root->getData();
                root = root->getRight();
            }
            else {
                break;
            }
        }
    }
    
    void const preorderWithoutRecursion(Node* root) {
        stack<Node*> s;
        
        std::function<void (Node*)> pushLeftSubTree
        = [&] (Node* root) {
            while (root) {
                cout << root->getData();
                s.push(root);
                root = root->getLeft();
            }
        };
        
        while (true) {
            pushLeftSubTree(root);
            
            if (!s.empty()) {
                root = s.top();
                s.pop();
                root = root->getRight();
            }
            else {
                break;
            }
        }
    }
    
    void const morrisTraversal(Node* root) {
        if (root == NULL) {
            return;
        }
        
        Node* current = root;
        
        while (current) {
            if (current->getLeft() == NULL) {
                cout << current->getData();
                current = current->getRight();
            }
            else {
                
                Node* pre = current->getLeft();
                
                while (pre->getRight() && pre->getRight() != current) {
                    pre = pre->getRight();
                }
                
                if (pre->getRight() == NULL) {
                    pre->setRight(current);
                    current = current->getLeft();
                }
                else {
                    pre->setRight(NULL);
                    cout << current->getData();
                    current = current->getRight();
                }
            }
        }
    }
    
    
};

int main(int argc, const char * argv[]) {
    Tree* tree = new Tree();
    
    tree->createTree();
    tree->morrisTraversal(tree->getRoot());
}
