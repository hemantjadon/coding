//
//  main.cpp
//  Merge K Sorted LL
//
//  Created by Hemant Jadon on 13/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#define N 3
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

LinkedList merge_2_lists(LinkedList a, LinkedList b){
    if (a.getHead() == NULL && b.getHead() == NULL) {
        return a; // Return any of a or b.
    }
    if (b.getHead() == NULL) {
        return a;
    }
    else if (a.getHead() == NULL){
        return b;
    }
    
    else {
        Node* ins_after = a.getHead(); // Node in a after which we have to insert.
        
        while (b.getHead()) {
            if (ins_after->getNext() == NULL) {
                if (ins_after->getData() > b.getHead()->getData()) {
                    Node* ins = b.popHeadNode();
                    a.insert_Node_Before(ins_after, ins);
                    continue;
                }
                a.insert_LL_After(ins_after, b);
                b.setHead(NULL);
                b.setTail(NULL);
                
            }
            else {
                while (ins_after) {
                    if (b.getHead()->getData() > ins_after->getData()) {
                        ins_after = ins_after->getNext();
                    }
                    else {
                        break;
                    }
                }
                
                if (ins_after == NULL) {
                    ins_after = a.getTail();
                }
                else {
                    Node* ins = b.popHeadNode();
                    if (ins_after->getData() > ins->getData()) {
                        a.insert_Node_Before(ins_after, ins);
                    }
                    else {
                        a.insert_Node_After(ins_after, ins);
                    }
                }
            }
        }
    }
    return a;
}

LinkedList merge_k_lists(LinkedList arr[N],int lastIndex){
    while (lastIndex > 0) {
        int i = 0;
        int j = lastIndex;
        
        while (i<j) {
            arr[i] = merge_2_lists(arr[i], arr[j]);
            i++;
            j--;
        }
        lastIndex /=2;
    }
    return arr[0];
}

int main(int argc, const char * argv[]) {
    LinkedList arr[N];
    
    for (int i=0; i<N; i++) {
        arr[i].createLL();
    }
    
    LinkedList c = merge_k_lists(arr, N-1);
    c.printLL();
}
