//
//  main.cpp
//  AMAZON 3
//
//  Created by Hemant Jadon on 01/08/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <stdio.h>

void foo(int n,int sum){
    int k=0,j=0;
    if (n == 0) {
        return;
    }
    
    k = n%10;
    j = n/10;
    foo(j,sum);
    printf("%d",k);
}

int main(){
    int x=4,y,z;
    y = --x;
    z = x--;
    printf("%d,%d,%d\n",x,y,z);
}