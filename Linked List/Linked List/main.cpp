//
//  main.cpp
//  Linked List
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
    Node(int data=0, Node* next=NULL, Node* prev=NULL){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    
    // Getters
    int getData() const { return this->data; }
    
    Node* getPrev() const { return this->prev; }
    
    Node* getNext() const { return this->next; }
    
    
    // Setters
    void setData(int data){ this->data = data; }
    
    void setPrev(Node* prev){ this->prev = prev; }
    
    void setNext(Node* next){ this->next = next; }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    LinkedList(Node* head=NULL, Node* tail=NULL){
        this->head = head;
        this->tail = tail;
    }
    
    // Getters
    Node* getHead() const {
        return this->head;
    }
    
    Node* getTail() const {
        return this->tail;
    }
    
    
    // Setters
    void setHead(Node* head){
        this->head = head;
    }
    
    void setTail(Node* tail){
        this->tail = tail;
    }
    
    void createLL(){
        int n;
        cin >> n;
        while (n!=-1) {
            Node* temp = new Node(n);
            if (head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->setNext(temp);
                temp->setPrev(tail);
                tail = temp;
            }
            cin >> n;
        }
    }
    
    void printLL(){
        Node* head_1 = this->getHead();
        
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
                    
                    this->setTail(a); // Resetting tail
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
                    
                    this->setTail(a); // Resetting tail
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
                    
                    this->setHead(b); // Resetting tail
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
                    
                    this->setHead(b); // Resetting head
                }
            }
            
            else {
                if (a->getNext() == b) {
                    b->setNext(a);
                    a->setPrev(b);
                    
                    a->setNext(NULL);
                    b->setPrev(NULL);
                    
                    this->setHead(b); // Resetting head
                    this->setTail(a); // Resetting tail
                }
                
                else {
                    a->getNext()->setPrev(b);
                    b->getPrev()->setNext(a);
                    
                    a->setPrev(b->getPrev());
                    b->setNext(a->getNext());
                    
                    a->setNext(NULL);
                    b->setPrev(NULL);
                    
                    this->setHead(b); // Resetting head
                    this->setTail(a); // Resetting tail
                }
            }
        }
    }
    
    void reverse(Node* start,Node* end){
        while ((start->getNext() != end) && (start != end)) {
            this->swapNodes(start, end);
            
            Node* temp = start;
            start = end;
            end = temp;
            
            this->printLL();
            start = start->getNext();
            end = end->getPrev();
            
        }
        
        if (start->getNext() == end) {
            this->swapNodes(start, end);
            
            Node* temp = start;
            start = end;
            end = temp;
        }
    }
    
    Node* popHeadNode(){
        Node* head_1 = this->getHead();
        
        if (head_1 == NULL) {
            return NULL;
        }
        else if (this->getHead()->getNext() == NULL) {
            this->setHead(NULL);
            this->setTail(NULL);
        }
        else {
            this->setHead(this->getHead()->getNext());
            this->getHead()->setPrev(NULL);
            head_1->setNext(NULL);
        }
        return head_1;
    }
    
    Node* popTailNode(){
        Node* tail_1 = this->getTail();
        
        if (tail_1 == NULL) {
            return NULL;
        }
        else if (this->getTail()->getPrev() == NULL) {
            this->setHead(NULL);
            this->setTail(NULL);
        }
        else {
            this->setTail(this->getTail()->getNext());
            this->getTail()->setNext(NULL);
            tail_1->setPrev(NULL);
        }
        return tail_1;
    }
    
    void insert_Node_After(Node* after, Node* ins){
        if (after == NULL || ins == NULL) {
            return;
        }
        else {
            if (after->getNext() == NULL) {
                ins->setPrev(after);
                after->setNext(ins);
                
                this->setTail(ins);
            }
            else {
                after->getNext()->setPrev(ins);
                ins->setNext(after->getNext());
                
                ins->setPrev(after);
                after->setNext(ins);
            }
        }
    }
    
    void insert_LL_After(Node* after, LinkedList a){
        if (after == NULL || a.getHead() == NULL) {
            return;
        }
        else{
            if (after->getNext() == NULL) {
                after->setNext(a.getHead());
                a.getHead()->setPrev(after);
                
                this->setTail(a.getTail());
            }
            else {
                after->getNext()->setPrev(a.getTail());
                a.getTail()->setNext(after->getNext());
                
                after->setNext(a.getHead());
                a.getHead()->setPrev(after);
            }
        }
    }
    
    void insert_Node_Before(Node* before, Node* ins){
        if (before == NULL || ins == NULL) {
            return;
        }
        else {
            if (before->getPrev() == NULL) {
                ins->setNext(before);
                before->setPrev(ins);
                
                this->setHead(ins);
            }
            else {
                before->getPrev()->setNext(ins);
                ins->setPrev(before->getPrev());
                
                ins->setNext(before);
                before->setPrev(ins);
                
            }
        }
    }
    
    void insert_LL_Before(Node* before, LinkedList a){
        if (before == NULL || a.getTail() == NULL) {
            return;
        }
        else {
            if (before->getPrev() == NULL) {
                a.getTail()->setNext(before);
                before->setPrev(a.getTail());
                
                this->setHead(a.getHead());
            }
            else {
                before->getPrev()->setNext(a.getHead());
                a.getHead()->setPrev(before->getPrev());
                
                before->setPrev(a.getTail());
                a.getTail()->setNext(before);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    LinkedList list;
    list.createLL();
    list.printLL();
}
