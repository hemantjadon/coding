//
//  main.cpp
//  Combination Sum
//
//  Created by Hemant Jadon on 05/08/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> combinationSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    set<vector<int>> ansSet;
    sort(A.begin(), A.end());
    
    function<void (int, int, vector<int>)> recur
    = [&] (int sum, int current, vector<int> set) {
        if (sum > B || current == A.size()) {
            return;
        }
        
        if (sum == B) {
            ansSet.insert(set);
            return;
        }
        
        recur(sum, current + 1, set);
        set.push_back(A[current]);
        recur(sum + A[current], current + 1, set);
        recur(sum + A[current], current, set);
    };
    
    recur(0, 0, vector<int> ());
    
    for (auto it = ansSet.begin(); it != ansSet.end(); it++) {
        ans.push_back(*it);
    }
    
    return ans;
}

vector<vector<int>> combinationSum2(vector<int> &A, int B) {
    vector<vector<int>> ans;
    set<vector<int>> ansSet;
    sort(A.begin(), A.end());
    
    function<void (int, int, vector<int>)> recur
    = [&] (int sum, int current, vector<int> set) {
        if (sum > B || current == A.size()) {
            if (sum == B) {
                ansSet.insert(set);
                return;
            }
            
            return;
        }
        
        if (sum == B) {
            ansSet.insert(set);
            return;
        }
        
        recur(sum, current + 1, set);
        set.push_back(A[current]);
        recur(sum + A[current], current + 1, set);
    };
    
    recur(0, 0, vector<int> ());
    
    for (auto it = ansSet.begin(); it != ansSet.end(); it++) {
        ans.push_back(*it);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> vct = {8, 10, 6, 11, 1, 16, 8};
    
    vector<vector<int>> res = combinationSum2(vct, 28);
    
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ", ";
        }
        cout << "]" << endl;
    }
}
