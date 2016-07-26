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


// heap_type : false => Min Heap
// heap_type : true => Max Heap
namespace Heap {
    class Heap{
    private:
        long size;
        const bool heap_type;
        vector<int> heap;
        
    public:
        Heap(bool heap_type=false):heap_type(heap_type),size(0)
        {}
        
        bool isMinHeap(){
            return !heap_type;
        }
        
        vector<int> getHeapVector(){
            return this->heap;
        }
        
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
        
        void rebuild(int i=0){
            int l = 2*i+1;
            int r = 2*i+2;
            
            if (heap_type == false) {
                //  Min Heap
                int smallest = i;
                
                if (l < heap.size() && heap[l] < heap[smallest]) {
                    smallest = l;
                }
                
                if (r < heap.size() && heap[r] < heap[smallest]) {
                    smallest = r;
                }
                
                if (smallest != i) {
                    swap(heap[i], heap[smallest]);
                    rebuild(smallest);
                }
            }
            else {
                //  Max Heap
                int largest = i;
                
                if (l < heap.size() && heap[l] > heap[largest]) {
                    largest = l;
                }
                
                if (r < heap.size() && heap[r] > heap[largest]) {
                    largest = r;
                }
                
                if (largest != i) {
                    swap(heap[i], heap[largest]);
                    rebuild(largest);
                }
            }
        }
        
        void changeValue(int i,int new_val){
            heap[i]=new_val;
            this->rebuild(i);
        }
        
        long getSize() const{
            return this->size;
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
                        swap(heap[i], heap[parent]);
                    }
                    i=parent;
                }
                
                else {
                    if (heap[i] > heap[parent]) {
                        swap(heap[i], heap[parent]);
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
                        swap(heap[i], heap[idx1]);
                        i = idx1;
                    }
                    else {
                        if (heap[idx1] < heap[idx2]) {
                            swap(heap[i], heap[idx1]);
                            i = idx1;
                        }
                        else {
                            swap(heap[i], heap[idx2]);
                            i = idx2;
                        }
                    }
                }
                else {
                    if (idx2 == -1) {
                        swap(heap[i], heap[idx1]);
                        i = idx1;
                    }
                    else {
                        if (heap[idx1] > heap[idx2]) {
                            swap(heap[i], heap[idx1]);
                            i = idx1;
                        }
                        else {
                            swap(heap[i], heap[idx2]);
                            i = idx2;
                        }
                    }
                }
            }
            
            //  Removing Last Element
            vector<int>::iterator it;
            
            for (it=heap.begin()+final_idx; it<heap.end(); it++) {
                swap((*it), (*(it+1)));
            }
            
            heap.erase(it-1);
            
            this->size--;
            return most_prior;
        }
    };
    
    void heapify(int arr[],int i,int n,bool heap_type=false){
        int l = 2*i+1;
        int r = 2*i+2;
        
        if (heap_type == false) {
            //  Min Heap
            int smallest = i;
            
            if (l < n && arr[l] < arr[smallest]) {
                smallest = l;
            }
            
            if (r < n && arr[r] < arr[smallest]) {
                smallest = r;
            }
            
            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                heapify(arr, smallest, n, heap_type);
            }
        }
        else {
            //  Max Heap
            int largest = i;
            
            if (l < n && arr[l] > arr[largest]) {
                largest = l;
            }
            
            if (r < n && arr[r] > arr[largest]) {
                largest = r;
            }
            
            if (largest != i) {
                swap(arr[i], arr[largest]);
                heapify(arr, largest, n, heap_type);
            }
        }
    }
    
    void heapSort(int arr[],int n){
        //  Starting the heaping process with parent of last element.
        for (int i=n/2-1; i>=0; i--) {
            heapify(arr, i, n, true);
        }
        
        for (int i=n-1; i>=0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, 0, i-1, true);
        }
    }
    
    vector<int> getKLargest(int arr[],int n,int k){
        /**
         *  The time complexiety of this function is O(n+klog(k))
         *  The time complexiety for building heap O(n)
         *  Then extracting k elements from it O(klog(k))
         */
        
        vector<int> vct;
        Heap h(true);
        h.formHeap(arr, n);
        for (int i=0; i<k; i++) {
            vct.push_back(h.extractMostPrior());
        }
        return vct;
    }
    
    vector<int> getKLargest_using_MinHeap(int arr[],int n,int k,bool order_sorted=true){
        /**
         *  The time complexiety of this function if sorted is required => O(k+n*log(k))
         *  The time complexiety for building heap O(k)
         *  Then changing the most prior atmost (n-k) times O((n-k)*log(k))
         *  Then extracting the k elements from heap one-by-onr O(k*log(k))
         *  So in total O(k + (n-k)*log(k) + k*log(k))
         *
         *  If Sorting is not required then => O(k+(n-k)*log(k))
         *  The time complexiety for building heap O(k)
         *  Then changing the most prior atmost (n-k) times O((n-k)*log(k))
         *  Then iterating over the heap to get the most prior elements O(k)
         *  So in total O(k + (n-k)*log(k))
         */
        
        vector<int> vct;
        
        Heap h;
        h.formHeap(arr, k);
        h.printHeap();
        for (int i=k; i<n; i++) {
            if (arr[i] > h.getMostPrior()) {
                h.changeValue(0, arr[i]);
            }
        }
        
        if (order_sorted) {
            while (h.getSize()) {
                vct.push_back(h.extractMostPrior());
            }
        }
        
        else {
            vector<int> heap_vct = h.getHeapVector();
            vector<int>::iterator it;
            for (it=heap_vct.begin(); it<heap_vct.end(); it++) {
                vct.push_back((*it));
            }
        }
        
        return vct;
    }
    
    void sort_almost_sorted(int arr[],int n,int k){
        Heap h;
        h.formHeap(arr, k);
        for (int i=k,j=0; i<n ; i++,j++) {
            arr[j] = h.extractMostPrior();
            h.insert(arr[i]);
        }
        int i=k;
        while (h.getSize()) {
            arr[i]=h.extractMostPrior();
            i++;
        }
    }
    
    bool isArrayMinHeap(int arr[],int n){
        bool is_heap = true;
        
        for (int i=0; i<n/2-1; i++) {
            int l = 2*i+1;
            int r = 2*i+2;
            
            if (l < n && arr[i] > arr[l]) {
                is_heap = false;
                break;
            }
            
            if (r < n && arr[i] > arr[r]) {
                is_heap = false;
                break;
            }
        }
        
        return is_heap;
    }
    
    bool isArrayMaxHeap(int arr[],int n){
        bool is_heap = true;
        
        for (int i=0; i<n/2-1; i++) {
            int l = 2*i+1;
            int r = 2*i+2;
            
            if (l < n && arr[i] < arr[l]) {
                is_heap = false;
                break;
            }
            
            if (r < n && arr[i] < arr[r]) {
                is_heap = false;
                break;
            }
        }
        
        return is_heap;
    }
}

int ropeJoinProblem(int arr[],int n){
    Heap::Heap h;
    h.formHeap(arr, n);
    
    int result = 0;
    
    while (h.getSize() > 1) {
        int min = h.extractMostPrior();
        int sec_min = h.extractMostPrior();

        result += (min + sec_min);
        h.insert(min+sec_min);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int arr[] = {4, 3, 2, 6};
    int n = sizeof(arr)/sizeof(int);
    cout << ropeJoinProblem(arr, n) << endl;
}
