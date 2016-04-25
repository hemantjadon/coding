//
//  main.cpp
//  Level Order Traversal
//
//  Created by Hemant Jadon on 22/04/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
private:
	int data;
	Node* left;
	Node* right;
	
public:
	Node(int d=0,Node* l=NULL, Node* r=NULL):data(d),left(l),right(r)
	{}
	
	void setData(int d){
		data = d;
	}
	
	void setLeft(Node* l){
		left = l;
	}
	
	void setRight(Node* r){
		right = r;
	}
	
	int getData() const {
		return data;
	}
	
	Node* getLeft() const {
		return left;
	}
	
	Node* getRight() const {
		return right;
	}
};

class Tree{
private:
	Node* root;
	
public:
	Tree():root(NULL)
	{}
	
	Node* getRoot() const {
		return root;
	}
	
	void createTree();
	void InOrderTraversal(Node* root);
};

void Tree::createTree(){
	int n;
	cin >> n;
	while (n!=-1) {
		Node* root1 = this->root;
		Node* temp = new Node;
		temp->setData(n);
		if (root1 == NULL) {
			root1 = temp;
			this->root = temp;
		}
		else{
			while (1) {
				if (n > root1->getData()) {
					if (root1->getRight()) {
						root1 = root1->getRight();
					}
					else{
						root1->setRight(temp);
						break;
					}
				}
				else {
					if (root1->getLeft()) {
						root1 = root1->getLeft();
					}
					else{
						root1->setLeft(temp);
						break;
					}
				}
			}
		}
		cin >> n;
	}
}

void Tree::InOrderTraversal(Node *root){
	if (root==NULL) {
		return;
	}
	InOrderTraversal(root->getLeft());
	cout << root->getData();
	InOrderTraversal(root->getRight());
}

int main(int argc, const char * argv[]) {
//	Tree t ;
//	t.createTree();
//	t.InOrderTraversal(t.getRoot());
	int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cout << arr[j][i];
		}
		cout << endl;
	}
}
