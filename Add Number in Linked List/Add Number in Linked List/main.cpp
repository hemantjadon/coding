//
//  main.cpp
//  Add Number in Linked List
//
//  Created by Hemant Jadon on 13/07/16.
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
            
            if (this->head == NULL) {
                this->setHead(temp);
                this->setTail(temp);
            }
            
            else {
                this->getTail()->setNext(temp);
                temp->setPrev(this->getTail());
                this->setTail(temp);
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
};

class LL : public LinkedList{
public:
    LL addLL(LL a,LL b){
        LL c; // Empty LL.
        
        //  If both LL are Empty; return Empty LL.
        if (!a.getTail() && !b.getTail()) {
            return c;
        }
        
        // If a is Empty; return b.
        else if (!a.getTail() && b.getTail()){
            return b;
        }
        
        // If b is Empty; return a.
        else if (a.getTail() && !b.getTail()) {
            return a;
        }
        
        // If none of them is Empty; Add them and store in LL c.
        else {
            Node* tail_a = a.getTail();
            Node* tail_b = b.getTail();
            Node* tail_c = c.getTail();
            
            int carry = 0;
            
            // While the both lists are NOT NULL
            while (tail_a && tail_b) {
                int sum = carry + tail_a->getData() + tail_b->getData();
                
                int to_be_saved = sum % 10;
                carry = sum / 10;
                
                Node* temp = new Node(to_be_saved);
                
                if (c.getTail() == NULL) {
                    c.setTail(temp);
                    c.setHead(temp);
                    tail_c = temp;
                }
                else {
                    c.getHead()->setPrev(temp);
                    temp->setNext(c.getHead());
                    c.setHead(temp);
                }
                
                tail_a = tail_a->getPrev();
                tail_b = tail_b->getPrev();
            }
            
            while (tail_a) {
                int sum = carry + tail_a->getData();
                
                int to_be_saved = sum % 10;
                carry = sum / 10;
                
                Node* temp = new Node(to_be_saved);
                
                if (c.getTail() == NULL) {
                    c.setTail(temp);
                    c.setHead(temp);
                    tail_c = temp;
                }
                else {
                    c.getHead()->setPrev(temp);
                    temp->setNext(c.getHead());
                    c.setHead(temp);
                }
                
                tail_a = tail_a->getPrev();
            }
            
            while (tail_b){
                int sum = carry + tail_b->getData();
                
                int to_be_saved = sum % 10;
                carry = sum / 10;
                
                Node* temp = new Node(to_be_saved);
                
                if (c.getTail() == NULL) {
                    c.setTail(temp);
                    c.setHead(temp);
                    tail_c = temp;
                }
                else {
                    c.getHead()->setPrev(temp);
                    temp->setNext(c.getHead());
                    c.setHead(temp);
                }
                
                tail_b = tail_b->getPrev();
            }
            
            while (carry) {
                int to_be_saved = carry % 10;
                carry /= 10;
                
                Node* temp = new Node(to_be_saved);
                
                if (c.getTail() == NULL) {
                    c.setTail(temp);
                    c.setHead(temp);
                    tail_c = temp;
                }
                else {
                    c.getHead()->setPrev(temp);
                    temp->setNext(c.getHead());
                    c.setHead(temp);
                }
            }
        }
        return c;
    }
};

int main(int argc, const char * argv[]) {
    LL a,b;
    cout << "Enter First LL"<<endl;
    a.createLL();
    cout << "Enter Second LL"<<endl;
    b.createLL();
    
    LL c = a.addLL(a, b);
    cout << "Sum of LL's : " << endl;
    c.printLL();
}
