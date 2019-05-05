//
//  main.cpp
//  SAMSUNG - Burst the baloon
//
//  Created by Hemant Jadon on 04/08/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int getScore(int arr[], bool burst[], int n, int idx) {
    if (idx >= n || idx < 0 || burst[idx]) {
        return 0;
    }
    
    int a = -1;
    int b = -1;
    
    for (int i = idx + 1; i < n; i++) {
        if (!burst[i]) {
            a = arr[i];
            break;
        }
    }
    
    for (int i = 0; i < idx; i++) {
        if (!burst[i]) {
            b = arr[i];
        }
    }
    
    if (a == -1 && b == -1) {
        return arr[idx];
    }
    
    if (a == -1) {
        return b;
    }
    
    if (b == -1) {
        return a;
    }
    
    return a*b;
}

void nextPermuatation(int arr[], int n) {
    int idx = n - 2;
    for (; idx >= 0; idx--) {
        if (arr[idx] < arr[idx + 1]) {
            break;
        }
    }
    
    if (idx == -1) {
        int i = idx + 1;
        int j = n - 1;
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        return;
    }
    
    int ceiling = idx + 1;
    
    for (int i = ceiling; i < n; i++) {
        if (arr[idx] < arr[i]) {
            if (arr[i] < arr[ceiling]) {
                ceiling = i;
            }
        }
    }
    
    swap(arr[idx], arr[ceiling]);
    
    int i = idx + 1;
    int j = n - 1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

long long fact(int n) {
    long long a = 1;
    
    while (n) {
        a *= n;
        n--;
    }
    
    return a;
}

long long getAnswerForPermutation(int arr[], int perm[], int n) {
    bool burst[n];
    
    for (int i = 0; i < n; i++) {
        burst[i] = false;
    }
    
    long long score = 0;
    
    for (int i = 0; i < n; i++) {
        score += getScore(arr, burst, n, perm[i]);
        burst[perm[i]] = true;
    }
    
    return score;
}

long long getAnswer(int arr[], int n) {
    long long x = fact(n);
    
    int perm[n];
    
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    
    long long score = 0;
    
    for (long long i = 0; i < x; i++) {
        score = max(score, getAnswerForPermutation(arr, perm, n));
        nextPermuatation(perm, n);
    }
    
    return score;
}

int recur(int arr[], bool burst[], int n, int start = 0){
    bool ret = true;
    
    for (int i = 0; i < n; i++) {
        if (!burst[i]){
            ret = false;
        }
    }
    
    if (ret) {
        return 0;
    }
    
    int s1 = 0;
    int s2 = 0;
    
    int idx = start;
    
    for (; idx < n; idx++) {
        if(!burst[idx]) {
            break;
        }
    }
    
    s1 += getScore(arr, burst, n, idx);
    burst[idx] = true;
    s1 += recur(arr, burst, n, 0);
    burst[idx] = false;
    s2 += recur(arr, burst, n, idx + 1);
    s2 += getScore(arr, burst, n, idx);
    
    return max(s1, s2);
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    bool burst[n];
    
    for (int i = 0; i < n; i++) {
        burst[i] = false;
    }
    
    cout << recur(arr, burst, n) << endl;
}
