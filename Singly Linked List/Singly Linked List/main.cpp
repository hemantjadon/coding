//
//  main.cpp
//  Singly Linked List
//
//  Created by Hemant Jadon on 14/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    
public:
    // Constructor
    Node(int data=0,Node* next=NULL):data(data),next(next)
    {}
    
    // Destructor
    ~Node(){
        this->data = 0;
        this->next = NULL;
    }
    
    // Copy Constructor
    Node(const Node &obj){
        this->data = obj.data;
        this->next = obj.next;
    }
    
    // Getters
    int getData() const {
        return this->data;
    }
    
    Node* getNext() const {
        return this->next;
    }
    
    //Setters
    void setData(int data){
        this->data = data;
    }
    
    void setNext(Node* next){
        this->next = next;
    }
    
    Node* operator++() {
        return this->getNext();
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;
public:
    // Constructor
    LinkedList(Node* head=NULL,Node* tail=NULL,int length=0):head(head),tail(tail),length(0)
    {}
    
    // Destructor
    ~LinkedList(){
        Node* head_1 = this->head;
        while (head_1) {
            Node* befNode = head_1;
            head_1 = head_1->getNext();
            delete befNode;
        }
        this->head = NULL;
        this->tail = NULL;
        this->length = 0;
    }
    
    // Copy Constructor
    LinkedList(const LinkedList &obj){
        this->head = obj.head;
        this->tail = obj.tail;
        this->length = obj.length;
    }
    
    // Getters
    Node* getHead() const {
        return this->head;
    }
    
    Node* getTail() const {
        return this->tail;
    }
    
    int getLength() const {
        return this->length;
    }
    
    // Setters
    void setHead(Node* head){
        this->head = head;
    }
    
    void setTail(Node* tail){
        this->tail = tail;
    }
    
    void incrementLength(){ this->length++;}
    
    void decrementLength(){ this->length--; }
    
    void createLL(){
        int n;
        cin >> n;
        
        while (n!=-1) {
            Node* temp = new Node(n);
            
            if (this->getHead() == NULL) {
                this->setHead(temp);
                this->setTail(temp);
            }
            else {
                this->getTail()->setNext(temp);
                this->setTail(temp);
            }
            this->incrementLength();
            cin >> n;
        }
    }
    
    void printLL(){
        Node* head_1 = this->getHead();
        
        while (head_1) {
            cout << head_1->getData() << "->";
            head_1 = head_1 -> getNext();
        }
        cout << endl;
    }
    
    Node* getPreviousNode(Node* ref){
        Node* head_1 = this->getHead();
        
        while (head_1) {
            if (head_1->getNext() == ref) {
                break;
            }
            else {
                head_1 = head_1->getNext();
            }
        }
//        if (head_1 == this->getHead()) {
//            return  NULL;
//        }
        return head_1;
    }
    
    Node* getNodeAtKth(int k){
        Node* head_1 = this->getHead();

        while (k>1 && head_1) {
            head_1 = head_1->getNext();
            k--;
        }
        
        return head_1;
    }
    
    Node* findNode(int el){
        Node* head_1 = this->getHead();
        
        while (head_1 && head_1->getData() != el) {
            head_1 = head_1->getNext();
        }
        
        return head_1;
    }
    
    void insertAtHead(Node* ins){
        if (this->getHead()) {
            ins->setNext(this->getHead());
            this->setHead(ins);
        }
        else {
            this->setHead(ins);
            this->setTail(ins);
        }
        this->incrementLength();
    }
    
    
    
    void insertAtTail(Node* ins){
        if (this -> getHead()) {
            this->getTail()->setNext(ins);
            this->setTail(ins);
        }
        else {
            this->setHead(ins);
            this->setTail(ins);
        }
        this->incrementLength();
    }
    
    void insertAtKth(Node* ins, int k){
        Node* head_1 = this->getHead();
        
        if (head_1 == NULL ) { return; }
        
        while (k>1 && head_1) {
            head_1 = head_1->getNext();
        }
        
        if (head_1 == NULL) { return; }
        
        if (head_1 == this->getTail()) {
            this->insertAtTail(ins);
        }
        
        else {
            ins->setNext(head_1->getNext());
            head_1->setNext(ins);
        }
        
        this->incrementLength();
    }
    
    void insert_Node_AfterNode(Node* after, Node* ins){
        if (after == NULL || ins == NULL) {
            return;
        }
        
        if (after == this->getTail()) {
            this->insertAtTail(ins);
        }
        
        else {
            ins->setNext(after->getNext());
            after->setNext(ins);
        }
        this->incrementLength();
    }
    
    void insert_Node_BeforeNode(Node* before, Node* ins){
        if (before == NULL || before == NULL) {
            return;
        }
        
        if (before == this->getHead()) {
            this->insertAtHead(ins);
        }
        
        else {
            Node* befNode = this->getPreviousNode(before);
            
            if (befNode == NULL) {
                return;
            }
            
            this->insert_Node_AfterNode(befNode, ins);
        }
        this->incrementLength();
    }
    
    void deleteAtHead(){
        Node* head_1 = this->getHead();
        if (head_1 == NULL) {
            return;
        }
        this->setHead(this->getHead());
        
        delete head_1;
        this->decrementLength();
    }
    
    void deleteAtTail(){
        Node* tail_1 = this->getTail();
        if (tail_1 == NULL) {
            return;
        }
        
        this->setTail(this->getPreviousNode(this->getTail()));
        this->getTail()->setNext(NULL);
        
        delete tail_1;
        this->decrementLength();
    }
    
    void deleteNode(Node* ref){
        if (this->getHead() == NULL || ref == NULL) {
            return;
        }
        else if (this->getHead() == ref){
            if (this->getHead() == this->getTail()) {
                this->setHead(NULL);
                this->setTail(NULL);
                delete ref;
            }
            else {
                this->setHead(ref->getNext());
                delete ref;
            }
        }
        
        else if (this->getTail() == ref) {
            Node* befNode = this->getPreviousNode(ref);
            this->setTail(befNode);
            befNode->setNext(NULL);
            
            delete ref;
        }
        else {
            Node* befNode = this->getPreviousNode(ref);
            befNode->setNext(ref->getNext());
            
            delete ref;
        }
        this->decrementLength();
    }
    
    void deletePartOfLL(Node* a,Node* b){
        if (a == NULL && b == NULL) {
            return;
        }
        else if (a == NULL){
            b->setNext(NULL);
            this->setTail(this->getPreviousNode(this->getTail()));
            this->getTail()->setNext(NULL);
        }
        else if (b == NULL){
            a->setNext(NULL);
            this->setTail(this->getPreviousNode(this->getTail()));
            this->getTail()->setNext(NULL);
        }
        else if(a == this->getHead()){
            if (b == this->getTail()) {
                delete this;
            }
            else {
                this->setHead(b->getNext());
                while (a != b && a != NULL) {
                    Node* head_1 = a;
                    a = a->getNext();
                    delete head_1;
                    this->decrementLength();
                }
                
                if (a == b) {
                    delete a;
                    this->decrementLength();
                }
            }
        }
        else if (b == this->getHead()){
            if (a == this->getTail()) {
                delete this;
            }
            else {
                this->setHead(a->getNext());
                while (a != b && b != NULL) {
                    Node* head_1 = b;
                    b = b->getNext();
                    delete head_1;\
                    this->decrementLength();
                }
                if (a == b) {
                    delete b;
                    this->decrementLength();
                }
            }
        }
        
        else if (b == this->getTail()){
            Node* a_befNode = this->getPreviousNode(a);
            this->setTail(a_befNode);
            a_befNode->setNext(NULL);
            
            while (a != NULL) {
                a_befNode = a;
                a = a->getNext();
                delete a_befNode;
                this->decrementLength();
            }
        }
        else if (b == this->getTail()) {
            Node* b_befNode = this->getPreviousNode(b);
            this->setTail(b_befNode);
            b_befNode->setNext(NULL);

            while (b != NULL) {
                b_befNode = b;
                b = b->getNext();
                delete b_befNode;
                this->decrementLength();
            }
        }
        else {
            Node* a_1 = a;
            
            while (a_1 != b && a_1 != NULL) {
                a_1 = a_1->getNext();
            }
            
            if (a_1 == b) {
                Node* a_befNode = this->getPreviousNode(a);
                a_befNode->setNext(b->getNext());
                
                while (a != b) {
                    a_befNode = a;
                    a = a->getNext();
                    delete a_befNode;
                    this->decrementLength();
                }
                if (a == b) {
                    delete a;
                    this->decrementLength();
                }
            }
            else {
                Node* b_befNode = this->getPreviousNode(b);
                b_befNode->setNext(a->getNext());
                
                while (b != a) {
                    b_befNode = b;
                    b = b->getNext();
                    delete b_befNode;
                    this->decrementLength();
                }
                
                if (a == b) {
                    delete b;
                    this->decrementLength();
                }
            }
        }
    }
    
    void deleteAtKth(int k){
        this->deleteNode(this->getNodeAtKth(k));
        
        // Length decrements in deleteNode() Function automatically.
    }
    
    Node* findMid(){
        Node* fast_ptr = this->getHead();
        Node* slow_ptr = this->getHead();
        
        while (fast_ptr && fast_ptr->getNext()) {
            fast_ptr = fast_ptr->getNext()->getNext();
            slow_ptr = slow_ptr->getNext();
        }
        
        return slow_ptr;
    }
    
    Node* findKthFromEnd(int k){
        if (this->getHead() == NULL) {
            return NULL;
        }
        
        Node* primary_ref = this->getHead();
        Node* secondary_ref = this->getHead();
        
        while (k>1 && secondary_ref) {
            secondary_ref = secondary_ref->getNext();
            k--;
        }
        
        if (secondary_ref == NULL) {
            return NULL;
        }
        else {
            while (secondary_ref->getNext() != NULL) {
                secondary_ref = secondary_ref->getNext();
                primary_ref = primary_ref->getNext();
            }
        }
        
        return primary_ref;
    }
    
    // Assuming both nodes a & b are either NULL or present in LL.
    void swapNodes(Node* a,Node* b){
        if (a == NULL || b == NULL || a == b) {
            return;
        }
        
        Node* a_befNode = this->getPreviousNode(a);
        Node* b_befNode = this->getPreviousNode(b);
        Node* a_nexNode = a->getNext();
        Node* b_nexNode = b->getNext();
        
        if (this->getHead() == a || this->getHead() == b) {
            if (this->getHead() == a) {
                if (this->getTail() == b) {
                    if (a->getNext() == b) {
                        b->setNext(a);
                        a->setNext(NULL);
                        
                        this->setHead(b);
                        this->setTail(a);
                    }
                    else {
                        b_befNode->setNext(a);
                        b->setNext(a_nexNode);
                        a->setNext(NULL);
                        
                        this->setHead(b);
                        this->setTail(a);
                    }
                }
                else {
                    if (a->getNext() == b){
                        a->setNext(b_nexNode);
                        b->setNext(a);
                        
                        this->setHead(b);
                    }
                    else {
                        b_befNode->setNext(a);
                        a->setNext(b_nexNode);
                        b->setNext(a_nexNode);
                        
                        this->setHead(b);
                    }
                }
            }
            else if (this->getHead() == b) {
                if (this->getTail() == a) {
                    if (b->getNext() == a) {
                        a->setNext(b);
                        b->setNext(NULL);
                        
                        this->setHead(a);
                        this->setTail(b);
                    }
                    else {
                        a_befNode->setNext(b);
                        a->setNext(b_nexNode);
                        b->setNext(NULL);
                        
                        this->setHead(a);
                        this->setTail(b);
                    }
                }
                else {
                    if (b->getNext() == a) {
                        b->setNext(a_nexNode);
                        a->setNext(b);
                        
                        this->setHead(a);
                    }
                    else {
                        a_befNode->setNext(b);
                        b->setNext(a_nexNode);
                        a->setNext(b_nexNode);
                        
                        this->setHead(a);
                    }
                }
            }
        }
        
        else if (this->getTail() == a || this->getTail() == b) {
            if (this->getTail() == a) {
                if (b->getNext() == a) {
                    b_befNode->setNext(a);
                    a->setNext(b);
                    b->setNext(NULL);
                    
                    this->setTail(b);
                }
                
                else {
                    b_befNode->setNext(a);
                    a->setNext(b_nexNode);
                    a_befNode->setNext(b);
                    b->setNext(NULL);
                    
                    this->setTail(b);
                }
            }
            else if (this->getTail() == b) {
                if (a->getNext() == b) {
                    a_befNode->setNext(b);
                    b->setNext(a);
                    a->setNext(NULL);
                    
                    this->setTail(a);
                }
                else {
                    a_befNode->setNext(b);
                    b->setNext(a_nexNode);
                    b_befNode->setNext(a);
                    a->setNext(NULL);
                }
            }
        }
        
        else {
            if (a->getNext() == b) {
                a_befNode->setNext(b);
                b->setNext(a);
                a->setNext(b_nexNode);
            }
            else if(b->getNext() == a){
                b_befNode->setNext(a);
                a->setNext(b);
                b->setNext(a_nexNode);
            }
            else{
                a_befNode->setNext(b);
                b->setNext(a_nexNode);
                
                b_befNode->setNext(a);
                a->setNext(b_nexNode);
            }
        }
    }
    
    void reverseIterative(){
        Node* head_1 = this->getHead();
        Node* tail_1 = this->getTail();
        
        if (head_1 == NULL) {
            return;
        }
        
        Node* prev = NULL;
        Node* curr = this->getHead();
        Node* next = curr->getNext();
        
        while (next != NULL) {
            curr->setNext(prev);
            prev = curr;
            curr = next;
            next = next->getNext();
        }
        curr->setNext(prev);
        this->setHead(tail_1);
        this->setTail(head_1);
    }
    
    void reverseRecursive_type1(Node* head,Node* prev){
        if (head == NULL) {
            return;
        }
        
        if (head->getNext() == NULL) {
            head->setNext(prev);
            this->setHead(head);
            return;
        }
        
        if (prev == NULL) {
            reverseRecursive_type1(head->getNext(), head);
        }
        else {
            reverseRecursive_type1(head->getNext(), prev->getNext());
        }
        
        head->setNext(prev);
        
        if (prev == NULL) {
            this->setTail(head);
        }
    }
    
    void reverseRecursive_type2(Node* head){
        if (head == NULL) {
            return;
        }
        
        Node* first = head;
        Node* rest = head->getNext();
        
        if (rest == NULL) {
            this->setHead(first);
            return;
        }
        reverseRecursive_type2(rest);
        rest->setNext(first);
        first->setNext(NULL);
        this->setTail(first);
    }
    
    bool checkPalindrome_Recur(Node** left,Node* right){
        if (right == NULL) {
            return true;
        }
        bool isPal = checkPalindrome_Recur(left, right->getNext());
        
        if (!isPal) {
            return false;
        }
        
        bool isPal_1 = ((*left)->getData() == right->getData());
        
        (*left) = (*left)->getNext();
        
        return isPal_1;
    }
    bool checkPalindrome(Node* head){
        if (head == NULL) {
            return false;
        }
        return checkPalindrome_Recur(&head, head);
    }
    
    void removeDuplicates_sortedLL(){
        Node* ptr1 = this->getHead();
        Node* ptr2 = ptr1->getNext();
        
        while (ptr2) {
            if (ptr2->getData() == ptr1->getData()) {
                ptr1->setNext(ptr2->getNext());
                delete ptr2;
                ptr2 = ptr1->getNext();
                this->decrementLength();
            }
            else {
                ptr1 = ptr1->getNext();
                ptr2 = ptr2->getNext();
            }
            
            if (ptr2 == NULL) {
                this->setTail(ptr1);
            }
        }
    }
    
    LinkedList intersection_Iterative_Sorted(LinkedList b){
        LinkedList intersection;
        Node* head_a = this->getHead();
        Node* head_b = b.getHead();
        
        while (head_a && head_b) {
            if (head_a->getData() == head_b->getData()) {
                
                Node* temp = new Node(head_a->getData());
                
                if (intersection.getHead() == NULL) {
                    intersection.setHead(temp);
                    intersection.setTail(temp);
                }
                else {
                    intersection.getTail()->setNext(temp);
                    intersection.setTail(temp);
                }
                intersection.incrementLength();
                head_a = head_a->getNext();
                head_b = head_b->getNext();
            }
            else if (head_a->getData() > head_b->getData()) {
                head_b = head_b->getNext();
            }
            else {
                head_a = head_a->getNext();
            }
            
        }
        
        return intersection;
    }
    
    void skipMdeleteN(Node* head,int m, int n){
        Node* head_1 = head;
        int m_1 = m;
        int n_1 = n;
        
        while (m_1 > 0 && head_1 != NULL) {
            head_1 = head_1->getNext();
            m_1--;
        }
        
        if (head_1 == NULL) {
            return;
        }
        
        Node* tail_1 = head_1;
        
        while (n_1 > 1 && tail_1) {
            tail_1 = tail_1->getNext();
            n_1--;
        }
        
        Node* rest = NULL;
        
        if (tail_1) {
            rest = tail_1->getNext(); // For next calling.
        }
        
        this->deletePartOfLL(head_1, tail_1);
        
        if (rest == NULL) {
            return;
        }
        
        skipMdeleteN(rest, m, n);
    }
};

int main(int argc, const char * argv[]) {
    LinkedList list;
    list.createLL();
    list.printLL();
    list.skipMdeleteN(list.getHead(), 3, 2);
    list.printLL();
}
