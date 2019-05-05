//
//  main.cpp
//  kth Next Permutation
//
//  Created by Hemant Jadon on 05/08/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

long fact(long n) {
    int a = 1;
    
    while (n) {
        a *= n;
        n--;
    }
    return a;
}

vector<int> nextKthPermutation(int n, int k) {
    k--;
    vector<int> ans;
    vector<int> factroidal;
    
    vector<int> vct;
    for (int i = 1; i <= n; i++) {
        vct.push_back(i);
    }
    
    int f = 1;
    
    while (k) {
        factroidal.push_back(k % f);
        k /= f;
        f++;
    }
    
    for (long i = factroidal.size(); i < vct.size(); i++) {
        factroidal.push_back(0);
    }
    
    reverse(factroidal.begin(), factroidal.end());
    
    for (int i=0; i < factroidal.size(); i++) {
        ans.push_back(vct[factroidal[i]]);
        vct.erase(vct.begin() + factroidal[i]);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    vector<int> res = nextKthPermutation(100, 1000);
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

}
