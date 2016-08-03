//
//  main.cpp
//  Store Credit(APAC)
//
//  Created by Hemant Jadon on 02/08/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int x=0; x<n; x++) {
        int c;
        cin >> c;
        int i;
        cin >> i;
        vector<pair<int,int>> arr(i);
        for (int y=0; y<i; y++) {
            int p;
            cin >> p;
            pair<int, int> joint(p,y);
            arr[y]=joint;
        }
        sort(arr.begin(), arr.end(),[](pair<int,int> const& left, pair<int,int> const& right) {
            return left.first < right.first;
        });
        
        int a=0;
        int b=int(arr.size()-1);
        
        while (a < b) {
            int sum = arr[a].first + arr[b].first;
            if (sum == c) {
                if (arr[a].second > arr[b].second) {
                    cout << "Case #" << x+1 << ": " << arr[b].second+1 << " " << arr[a].second+1 << endl;
                }
                else {
                    cout << "Case #" << x+1 << ": " << arr[a].second+1 << " " << arr[b].second+1 << endl;
                }
                break;
            }
            
            if (sum > c) {
                b--;
            }
            else {
                a++;
            }
        }
    }
}
