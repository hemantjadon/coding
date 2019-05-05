//
//  main.cpp
//  Missionaries And Cannibals
//
//  Created by Hemant Jadon on 27/11/17.
//  Copyright © 2017 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;


struct status{
    int state;
    int boat;
    int m1,c1,m2,c2;
    string sol;
    
    bool operator == (status s1){
        bool flag;
        flag=(m1==s1.m1)&&(m2==s1.m2)&&(c1==s1.c1)&&(c2==s1.c2);
        return flag;
    }
};

void solve(status s){
    
    queue< status > q;
    status s1,s2,final;
    final.c1=final.m1=0;
    
    final.c2=final.m2=3;
    q.push(s);
    while(!q.empty()) {
        s1=q.front();q.pop();
        if(s1==final){
            cout<<s1.sol;
            return ;
        }
        else{
            s2=s1;
            if(s2.state!=1){
                s2.state=1;
                s2.sol+="1c ";
                if(s2.boat==1){
                    
                    s2.c1--;s2.c2++;
                    s2.boat=2;
                }
                else{
                    s2.c1++;s2.c2--;
                    s2.boat=1;
                }
                if(((s2.m1==0)||(s2.c1<=s2.m1))&&((s2.m2==0)||(s2.c2<=s2.m2))){
                    q.push(s2);
                }
            }
            s2=s1;
            if(s2.state!=2){
                s2.state=2;
                s2.sol+="1m ";
                if(s2.boat==1){
                    s2.m1--;s2.m2++;
                    s2.boat=2;
                }
                else{
                    s2.m1++;s2.m2--;
                    s2.boat=1;
                }
                if(((s2.m1==0)||(s2.c1<=s2.m1))&&((s2.m2==0)||(s2.c2<=s2.m2))){
                    q.push(s2);
                }
            }
            s2=s1;
            
            if(s2.state!=3){
                s2.state=3;
                s2.sol+="2c ";
                if(s2.boat==1){
                    s2.c1-=2;s2.c2+=2;
                    
                    s2.boat=2;
                }
                else{
                    s2.c1+=2;s2.c2-=2;
                    s2.boat=1;
                }
                if(((s2.m1==0)||(s2.c1<=s2.m1))&&((s2.m2==0)||(s2.c2<=s2.m2))){
                    q.push(s2);
                }
            }
            s2=s1;
            if(s2.state!=4){
                s2.state=4;
                s2.sol+="2m ";
                
                if(s2.boat==1){
                    s2.m1-=2;s2.m2+=2;
                    s2.boat=2;
                }
                else{
                    s2.m1+=2;s2.m2-=2;
                    s2.boat=1;
                }
                if(((s2.m1==0)||(s2.c1<=s2.m1))&&((s2.m2==0)||(s2.c2<=s2.m2))){
                    
                    q.push(s2);
                }
            }
            s2=s1;
            if(s2.state!=5){
                s2.state=5;
                s2.sol+="1c1m ";
                if(s2.boat==1){
                    s2.c1--;s2.c2++;
                    s2.m1--;s2.m2++;
                    s2.boat=2;
                }
                else{
                    s2.c1++;s2.c2--;
                    s2.m1++;s2.m2--;
                    s2.boat=1;
                }
                if(((s2.m1==0)||(s2.c1<=s2.m1))&&((s2.m2==0)||(s2.c2<=s2.m2))){
                    
                    q.push(s2);
                    
                }
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    status s;
    cout<<"the solution for missionary cannibal problem :\n";
    
    s.m1=3;s.m2=0;
    s.c1=3;s.c2=0;
    s.boat=1;s.state=0;
    s.sol="";
    
    solve(s);

    return 0;
}

