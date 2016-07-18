//
//  main.cpp
//  Count Anagrams from set
//
//  Created by Hemant Jadon on 18/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    vector<pair<string,int>> vct;
    
    string str;
    getline(cin,str);
    
    while (!str.empty()) {
        pair<string, int> sub(str,0);
        vct.push_back(sub);
        getline(cin, str);
    }
    
    vector<pair<string, int>> aux_vct;
    
    for (int i=0; i<vct.size(); i++) {
        string str = vct[i].first;
        sort(str.begin(),str.end());
        pair<string, int> joint (str,i);
        aux_vct.push_back(joint);
    }
    
    sort(aux_vct.begin(), aux_vct.end());
    
    vector<pair<string, vector<int>>> aux_vct_2;
    
    for (int i=0; i<aux_vct.size(); i++) {
        if (aux_vct_2.size() && aux_vct_2.back().first == aux_vct[i].first) {
            aux_vct_2.back().second.push_back(aux_vct[i].second);
        }
        else{
            vector<int> sub;
            sub.push_back(aux_vct[i].second);
            pair<string, vector<int>> joint(aux_vct[i].first,sub);
            aux_vct_2.push_back(joint);
        }
    }
    
    for (int i=0; i<aux_vct_2.size(); i++) {
        for (int j=0; j<aux_vct_2[i].second.size(); j++) {
            int size = aux_vct_2[i].second.size();
            vct[aux_vct_2[i].second[j]].second = size;
        }
    }
    
    for (int i=0; i<vct.size(); i++) {
        cout << vct[i].first << " "<< vct[i].second << endl;
    }
}
