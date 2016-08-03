//
//  main.cpp
//  AMAZON 2
//
//  Created by Hemant Jadon on 01/08/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    string str;
    
    for (int i=0; i<n; i++) {
        cin >> str;
        
        while (1) {
            int x=0;
            int y=x+1;
            bool change = false;
            while (y<str.length()) {
                if (str[x] == 'a' && str[y] == 'b'){
                    str.erase(str.begin()+x,str.begin()+y+1);
                    change = true;
                }
                else {
                    x++;
                    y=x+1;
                }
            }
            if (change == false) {
                if (str.length() == 0) {
                    cout << "Good" << endl;
                }
                else {
                    cout << "Bad" << endl;
                }
                break;
            }
        }
    }
}
