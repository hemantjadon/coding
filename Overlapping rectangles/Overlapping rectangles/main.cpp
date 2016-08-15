//
//  main.cpp
//  Overlapping rectangles
//
//  Created by Hemant Jadon on 13/08/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool isPointInside(vector<pair<int,int>> rect, pair<int, int> point){
    return ((point.second <= rect[0].second) &&
            (point.second >= rect[2].second) &&
            (point.first >= rect[3].first) &&
            (point.first <= rect[1].first));
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    
    for (int i=0; i<t; i++) {
        int x11,y11,x12,y12,x21,y21,x22,y22;
        cin >> x11 >> y11 >> x12 >> y12;
        cin >> x21 >> y21 >> x22 >> y22;
        
        vector<pair<int, int>> rect1;
        rect1.push_back(make_pair(x11, y11));
        rect1.push_back(make_pair(x12, y11));
        rect1.push_back(make_pair(x12, y12));
        rect1.push_back(make_pair(x11, y12));
        
        vector<pair<int, int>> rect2;
        rect2.push_back(make_pair(x21, y21));
        rect2.push_back(make_pair(x22, y21));
        rect2.push_back(make_pair(x22, y22));
        rect2.push_back(make_pair(x21, y22));
        
        for (int i=0; i < rect2.size(); i++) {
            if(isPointInside(rect1, rect2[i])) {
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }
}
