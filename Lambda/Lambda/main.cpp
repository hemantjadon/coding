//
//  main.cpp
//  Lambda
//
//  Created by Hemant Jadon on 02/08/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
using namespace std;

std::function<int (int)> adderX(int x) {
    cout << "x " << x << endl;
    std::function<int (int)> add
        = [&](int y) mutable -> int {
            cout << "x " << x << endl;
            cout << "y " << y << endl;
            return x + y;
        };
    
    return add;
}

int main(int argc, const char * argv[]) {
    
    std::function<int (int)> adder5 = adderX(5);
    adder5(7);
}
