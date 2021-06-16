#pragma GCC optimize ("O3")
#include "lib1168.h"
#include <map>
#define F first
#define S second
using namespace std;

map<int, short> mp;

void pop_big(){
    if(!(--mp.rbegin()->S)){
        mp.erase(--mp.end());
    }
}


void pop_small(){
    if(!(--mp.begin()->S)){
        mp.erase(mp.begin());
    }
}

void push(int s){
    mp[s]++;
}

int big(){
    return mp.rbegin()->F;
}
int small(){
    return mp.begin()->F;
}
