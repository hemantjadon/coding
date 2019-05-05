//
//  main.cpp
//  Combinations
//
//  Created by Hemant Jadon on 05/08/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    
    vector<bool> selected;
    
    for (int i = 0; i < n; i++) {
        selected.push_back(false);
    }
    
    function<void (vector<bool>, int, int)> recur
    = [&] (vector<bool> selected, int start, int k) -> void {
        vector<int> combination;
        
        if (k == 0) {
            for (int i = 0; i < n; i++) {
                if (selected[i])  {
                    combination.push_back(i + 1);
                }
            }
            ans.push_back(combination);
            return;
        }
        
        if (start == n) {
            return;
        }
        
        recur(selected, start + 1, k);
        selected[start] = true;
        recur(selected, start + 1, k - 1);
    };
    
    recur(selected, 0, k);
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> res = combine(2, 2);
    
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ", ";
        }
        cout << "]" << endl;
    }
}
