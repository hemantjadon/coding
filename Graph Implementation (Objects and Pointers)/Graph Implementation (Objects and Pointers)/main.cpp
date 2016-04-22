//
//  main.cpp
//  Graph Implementation (Objects and Pointers)
//
//  Created by Hemant Jadon on 03/04/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Node{
private:
    int data;
    vector<Node*> adj;
    
public:
    //Constructor
    Node():data(0),adj(NULL)
    {};
    
    //Setters
    void setData(int data){
		this->data = data;
    }
	
	//Getters
	int getData()const{
		return this->data;
	}
    
};

int main(int argc, const char * argv[]) {
    
}
