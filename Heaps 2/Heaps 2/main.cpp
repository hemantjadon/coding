//
//  main.cpp
//  Heaps 2
//
//  Created by Hemant Jadon on 31/07/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

namespace Heap {
    enum HeapType {
        MIN_HEAP,
        MAX_HEAP
    };
    
    class Heap {
    private:
        vector<int> heap;
        HeapType heap_type;
        
        void heapify(long i) {
            long l = 2*i + 1;
            long r = 2*i + 2;
            
            // Index not in heap
            if (i > this->heap.size() - 1) {
                return;
            }
            
            // i is without any children
            if (l > this->heap.size() - 1) {
                return;
            }
            
            if (this->heap_type == HeapType::MIN_HEAP) {
                long smallest = i;
                
                if (this->heap[l] < this->heap[smallest]) {
                    smallest = l;
                }
                
                if (this->heap[r] <= this->heap.size() -1 && this->heap[r] < this->heap[smallest]) {
                    smallest = r;
                }
                
                if (smallest != i) {
                    swap(this->heap[smallest], this->heap[i]);
                    heapify(smallest);
                }
            }
            else {
                long largest = i;
                
                if (this->heap[l] > this->heap[largest]) {
                    largest = l;
                }
                
                if (this->heap[r] <= this->heap.size() -1 && this->heap[r] > this->heap[largest]) {
                    largest = r;
                }
                
                if (largest != i) {
                    swap(this->heap[largest], this->heap[i]);
                    heapify(largest);
                }
            }
        }
        
    public:
        Heap (HeapType heap_type = HeapType::MIN_HEAP): heap_type(heap_type) {}
        
        vector<int> getHeapVector() {
            return this->heap;
        }
        
        void buildHeap(int arr[], int n) {
            vector<int> vct;
            
            for (int i = 0; i < n; i++) {
                vct.push_back(arr[i]);
            }
            this->buildHeap(vct);
        }
        
        void buildHeap(vector<int> vct) {
            for (int i = 0; i < vct.size(); i++) {
                this->heap.push_back(vct[i]);
            }
            
            long firstNonLeafIdx = (this->heap.size() - 1) / 2;
            
            for (long i = firstNonLeafIdx; i >= 0; i--) {
                this->heapify(i);
            }
            
            /**
             * Build heap takes order n time.
             * As for the level one nodes the work done is constant c
             * For level 2 nodes the work done is 2c
             * For level log(n) nodes work done is log(n)c
             * But the number of nodes also decrease as the level increases
             * number of nodes at level 1 = n/2
             * Number of nodes at level 2 = n/4
             * Number of nodes at level n = 1 (root node)
             * Thus total work is
             * c*n/2 + 2*c*n/4 + 3*c*n/8 + ...... + k*c*n/2^k
             * c*n/2(1 + 2/2 + 3/4 + 4/8 + 5/16 + ..... + (k+1)/2^k)
             * The whole thing in bracket is a constant (Convergent series)
             * Thus the complexity is O(n)
             */
        }
        
        void insert(int n) {
            this->heap.push_back(n);
            
            long child = (this->heap.size() - 1);
            
            while (child) {
                long parent = (child - 1) / 2;
                
                if(heap_type == HeapType::MIN_HEAP) {
                    if (heap[parent] > heap[child]) {
                        swap(heap[parent], heap[child]);
                    }
                }
                else {
                    if (heap[parent] < heap[child]) {
                        swap(heap[parent], heap[child]);
                    }
                }
                child = parent;
            }
        }
        
        int getMostPrior() {
            if (heap.size()) {
                return heap[1];
            }
            else {
                if (heap_type == HeapType::MIN_HEAP) {
                    return INT_MIN;
                }
                else {
                    return INT_MAX;
                }
            }
        }
        
        int extractMostPrior() {
            int mostPrior = getMostPrior();
            
            if (heap.size()) {
                if (heap_type == HeapType::MIN_HEAP) {
                    heap[0] = INT_MAX;
                    heapify(0);
                }
                else {
                    heap[0] = INT_MIN;
                    heapify(0);
                }
                heap.pop_back();
            }
            
            return  mostPrior;
        }
        
        void printHeap() {
            for (int i = 0; i < this->heap.size(); i++) {
                cout << this->heap[i];
            }
            cout << endl;
        }
    };
    
    void heapify(vector<int> &heapVct, long i, HeapType heap_type, long n = INT_MAX) {
        long l = 2*i + 1;
        long r = 2*i + 2;
        
        if (n == INT_MAX) {
            n = heapVct.size();
        }
        
        // Index not in heap
        if (i > n - 1) {
            return;
        }
        
        // i is without any children
        if (l > n - 1) {
            return;
        }
        
        if (heap_type == HeapType::MIN_HEAP) {
            long smallest = i;
            
            if (heapVct[l] < heapVct[smallest]) {
                smallest = l;
            }
            
            if (heapVct[r] <= n-1 && heapVct[r] < heapVct[smallest]) {
                smallest = r;
            }
            
            if (smallest != i) {
                int temp = heapVct[smallest];
                heapVct[smallest] = heapVct[i];
                heapVct[i] = temp;
                heapify(heapVct, smallest, heap_type, n);
            }
        }
        else {
            long largest = i;
            
            if (heapVct[l] > heapVct[largest]) {
                largest = l;
            }
            
            if (heapVct[r] <= n-1 && heapVct[r] > heapVct[largest]) {
                largest = r;
            }
            
            if (largest != i) {
                int temp = heapVct[largest];
                heapVct[largest] = heapVct[i];
                heapVct[i] = temp;
                heapify(heapVct, largest, heap_type, n);
            }
        }
        
        return;
    }
    
    void heapSort(vector<int> &arr) {
        long firstNonLeafElement = (arr.size() - 1) / 2;
        
        for (long i = firstNonLeafElement; i >= 0; i--) {
            heapify(arr, i, HeapType::MAX_HEAP);
        }
        
        for (long i = arr.size() - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, 0, HeapType::MAX_HEAP,  i - 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> arr = {5, 1, 3, 2, 4};
    Heap::heapSort(arr);
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
    }
    cout << endl;
}
