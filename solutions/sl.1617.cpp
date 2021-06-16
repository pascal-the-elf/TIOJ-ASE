#include <iostream>
#include <algorithm>
#include <vector>
#include "lib1617.h"
using namespace std;

int N = 5;
/*
vector<int> ans = {1, 3, 2, 5, 4};

void Report(int x){ cout << "ANS = " << x << endl; }
int Med3(int a, int b , int c){
    if(ans[a] <= )
}

int Get_Box(){return N;}
*/

int main(){
    N = Get_Box();
    if(N == 1) Report(1);
    vector<int> v;
    v.resize(N);
    for(int i = 1; i <= N; i++) v[i-1] = i;
    int a = 1, b = 2, res;
    for(int i = 3; i <= N; i++){
        res = Med3(a, b, i);
        if(res == a) a = i;
        if(res == b) b = i;
    }
    nth_element(v.begin(), v.begin() + v.size()/2, v.end(), [=](int x, int y){ //assume a is either max or min works
        if(a == x) return false;
        if(a == y) return true;
        int res = Med3(a, x, y);
        return (res == x) ? false : true;
    });
    Report(v[v.size()/2]);
}
