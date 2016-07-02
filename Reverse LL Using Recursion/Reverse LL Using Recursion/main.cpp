//
//  main.cpp
//  Reverse LL Using Recursion
//
//  Created by Hemant Jadon on 02/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next;
    Node* prev;
    
public:
    // Constructor
    Node(int data=0, Node* left=NULL, Node* right=NULL){
        this->data = data;
        this->next = left;
        this->prev = right;
    }
    
    // Getters
    int getData() const { return this->data; }
    
    Node* getPrev() const { return this->next; }
    
    Node* getNext() const { return this->prev; }
    
    
    // Setters
    void setData(int data){ this->data = data; }
    
    void setPrev(Node* left){ this->next = left; }
    
    void setNext(Node* right){ this->prev = right; }
};


class LinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    // Constructor
    LinkedList(Node* head=NULL, Node* tail=NULL){
        this->head = head;
        this->tail = tail;
    }
    
    // Getters
    Node* getHead() const { return this->head; }
    
    Node* getTail() const { return this->tail; }
    
    // Setters
    void setHead(Node* head){ this->head = head; }
    
    void setTail(Node* tail){ this->tail = tail; }
    
    
    void createLL(){
        int n;
        cin >> n;
        while (n!=-1) {
            Node* temp = new Node(n);
            
            if (this->head == NULL) {
                this->head = temp;
                this->tail = temp;
            }
            
            else {
                this->tail->setNext(temp);
                temp->setPrev(this->tail);
                this->tail = temp;
            }
            cin >> n;
        }
    }
    
    void printLL(){
        Node* head_1 = this->head;
        
        while (head_1) {
            cout << head_1->getData() << "<->";
            head_1 = head_1->getNext();
        }
        cout << endl;
    }
    
    void swapNodes(Node* a, Node* b){
        if (!a || !b) {
            cout << "Cant swap with NULL" << endl;
            return;
        }
        
        if (a == b) {
            return;
        }
        
        if (a->getPrev() != NULL) {
            if (b->getNext() != NULL) {
                if (a->getNext() == b) {
                    a->getPrev()->setNext(b);
                    b->getNext()->setPrev(a);
                    
                    b->setPrev(a->getPrev());
                    a->setNext(b->getNext());
                    
                    a->setPrev(b);
                    b->setNext(a);
                }
                
                else {
                    a->getPrev()->setNext(b);
                    b->getNext()->setPrev(a);
                    
                    a->getNext()->setPrev(b);
                    b->getPrev()->setNext(a);
                    
                    Node* tempa1 = a->getNext();
                    Node* tempa2 = b->getPrev();
                    
                    a->setNext(b->getNext());
                    b->setNext(tempa1);
                    b->setPrev(a->getPrev());
                    a->setPrev(tempa2);
                }
            }
            
            else {
                if (a->getNext() == b) {
                    a->getPrev()->setNext(b);
                    
                    b->setPrev(a->getPrev());
                    
                    b->setNext(a);
                    a->setPrev(b);
                    
                    a->setNext(NULL);
                    
                    this->tail = a; // Resetting tail
                }
                
                else {
                    a->getPrev()->setNext(b);
                    b->getPrev()->setNext(a);
                    
                    a->getNext()->setPrev(b);
                    b->setNext(a->getNext());
                    
                    Node* temp = a->getPrev();
                    a->setPrev(b->getPrev());
                    b->setPrev(temp);
                    
                    a->setNext(NULL);
                    
                    this->tail = a; // Resetting tail
                }
            }
        }
        
        else {
            if (b->getNext() != NULL) {
                if (a->getNext() == b) {
                    b->getNext()->setPrev(a);
                    a->setNext(b->getNext());
                    
                    a->setPrev(b);
                    b->setNext(a);
                    
                    b->setPrev(NULL);
                    
                    this->head = b; // Resetting tail
                }
                
                else {
                    b->getNext()->setPrev(a);
                    b->getPrev()->setNext(a);
                    
                    a->getNext()->setPrev(b);
                    
                    Node* temp = a->getNext();
                    
                    a->setNext(b->getNext());
                    a->setPrev(b->getPrev());
                    b->setNext(temp);
                    b->setPrev(NULL);
                    
                    this->head = b; // Resetting head
                }
            }
            
            else {
                if (a->getNext() == b) {
                    b->setNext(a);
                    a->setPrev(b);
                    
                    a->setNext(NULL);
                    b->setPrev(NULL);
                    
                    this->head = b; // Resetting head
                    this->tail = a; // Resetting tail
                }
                
                else {
                    a->getNext()->setPrev(b);
                    b->getPrev()->setNext(a);
                    
                    a->setPrev(b->getPrev());
                    b->setNext(a->getNext());
                    
                    a->setNext(NULL);
                    b->setPrev(NULL);
                    
                    this->head = b; // Resetting head
                    this->tail = a; // Resetting tail
                }
            }
        }
    }
};


class LL : public LinkedList{
    
public:
    Node* recrusive_reverse(Node* head){
        // Base Case
        if (head == NULL) {
            return this->getHead();
        }
        
        Node* head_1 = recrusive_reverse(head->getNext());
        swapNodes(head_1, head);
        
        Node* temp = head_1;
        head_1 = head;
        head = temp;
        
        return head_1->getNext();
    }
};

int main(int argc, const char * argv[]) {
    LL list;
    
    list.createLL();
    list.printLL();
    list.recrusive_reverse(list.getHead());
    list.printLL();
}
