#include <iostream>
//#include "lib1416.h"
using namespace std;

int N;

int Initialize(){
    int t;
    cin >> t;
    return t;
}

int Take_Stone(int a){
    int t;
    cin >> t;
    return t;
}

int main(){
	N = Initialize();
	cout << "1" << endl;
	int take = Take_Stone(1), oriTake;
	N -= 1;
    while(N){
        N -= take;
        if(!N) return 0;
        cout << take << endl;
        take = Take_Stone(take);
        N -= take;
    }
}
