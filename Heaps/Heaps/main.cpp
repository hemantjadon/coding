//
//  main.cpp
//  Heaps
//
//  Created by Hemant Jadon on 25/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Heap{
private:
    long size;
    const bool heap_type;
    vector<int> heap;
    
public:
    Heap(bool heap_type=false):heap_type(heap_type),size(0)
    {}
    
    void formHeap(int arr[],int n){
        for (int i=0; i<n; i++) {
            this->insert(arr[i]);
        }
    }
    
    void formHeap(vector<int> vct){
        vector<int>::iterator it;
        
        for (it=vct.begin(); it < vct.end(); it++) {
            this->insert((*it));
        }
    }
    
    long getSize() const{
        return this->size;
    }
    
    bool isMinHeap(){
        return !heap_type;
    }
    
    void printHeap(){
        vector<int>::iterator it;
        
        for (it=heap.begin(); it < heap.end(); it++) {
            cout << (*it) << " ";
        }
        cout << endl;
    }
    
    void insert(int num){
        heap.push_back(num);
        
        long i=heap.size()-1;
        
        while (i > 0) {
            long parent = (i-1)/2;
            
            if (isMinHeap()) {
                if (heap[i] < heap[parent]) {
                    __swap(heap[i], heap[parent]);
                }
                i=parent;
            }
            
            else {
                if (heap[i] > heap[parent]) {
                    __swap(heap[i], heap[parent]);
                }
                i=parent;
            }
        }
        this->size++;
    }
    
    int getMostPrior(){
        return heap[0];
    }
    
    int extractMostPrior(){
        int most_prior = heap[0];
        
        long i=0;
        
        long final_idx=-1;
        
        while (1) {
            long idx1 = -1;
            long idx2 = -1;
            
            // Detecting Childrens
            if (2*i+1 >= heap.size()) {
                final_idx = i;
                break;
            }
            
            if (2*i+2 >= heap.size()) {
                idx1 = 2*i+1;
            }
            else {
                idx1 = 2*i+1;
                idx2 = 2*i+2;
            }
            
            if (isMinHeap()) {
                if (idx2 == -1) {
                    __swap(heap[i], heap[idx1]);
                    i = idx1;
                }
                else {
                    if (heap[idx1] < heap[idx2]) {
                        __swap(heap[i], heap[idx1]);
                        i = idx1;
                    }
                    else {
                        __swap(heap[i], heap[idx2]);
                        i = idx2;
                    }
                }
            }
            else {
                if (idx2 == -1) {
                    __swap(heap[i], heap[idx1]);
                    i = idx1;
                }
                else {
                    if (heap[idx1] > heap[idx2]) {
                        __swap(heap[i], heap[idx1]);
                        i = idx1;
                    }
                    else {
                        __swap(heap[i], heap[idx2]);
                        i = idx2;
                    }
                }
            }
        }
        
        //  Removing Last Element
        vector<int>::iterator it;
        
        for (it=heap.begin()+final_idx; it<heap.end(); it++) {
            __swap((*it), (*(it+1)));
        }
        
        heap.erase(it-1);
        
        this->size--;
        return most_prior;
    }
    
private:
    // Auxilary Functions
    void __swap(int &a, int&b){
        int temp = a;
        a = b;
        b = temp;
    }
};



int main(int argc, const char * argv[]) {
    Heap h;
    int arr[] = {2,3,4,1};
    int n = sizeof(arr)/sizeof(int);
    h.formHeap(arr, n);
    h.printHeap();
}
