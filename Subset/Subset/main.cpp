//
//  main.cpp
//  Subset
//
//  Created by Hemant Jadon on 05/08/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> subsets(vector<int> &A) {
    vector<vector<int>> ans;
    
    sort(A.begin(), A.end());
    
    function<void (vector<int>, vector<bool>, int)> recur
    = [&] (vector<int> vct, vector<bool> selected, int start) {
        if (start == vct.size()) {
            vector<int> subset;
            
            for (int i = 0; i < vct.size(); i++) {
                if (selected[i])  {
                    subset.push_back(vct[i]);
                }
            }
            
            ans.push_back(subset);
            
            return;
        }
        
        recur(A, selected, start + 1);
        selected[start] = true;
        recur(A, selected, start + 1);
    };
    
    vector<bool> sel;
    
    for (int i = 0; i < A.size(); i++) {
        sel.push_back(false);
    }
    
    recur(A, sel, 0);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}

vector<vector<int>> subsetsWithDup(vector<int> &A) {
    vector<vector<int>> ans;
    sort(A.begin(), A.end());

    set<vector<int>> ansSet;
    
    function<void (vector<int>, vector<bool>, int)> recur
    = [&] (vector<int> num, vector<bool> selected, int start) {
        if(start == A.size()) {
            vector<int> vct;
            
            for (int i = 0; i < A.size(); i++) {
                if(selected[i]) {
                    vct.push_back(A[i]);
                }
            }
            ansSet.insert(vct);
            
            return;
        }
        
        recur(A, selected, start + 1);
        selected[start] = true;
        recur(A, selected, start + 1);
    };
    
    vector<bool> selected;
    
    for (int i = 0; i < A.size(); i++) {
        selected.push_back(false);
    }
    
    recur(A, selected, 0);
    
    for (auto it = ansSet.begin(); it != ansSet.end(); it++) {
        ans.push_back(*it);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> vct = { 1, 2, 2 };
    
    vector<vector<int>> res = subsetsWithDup(vct);
    
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ", ";
        }
        cout << "]" << endl;
    }
}
