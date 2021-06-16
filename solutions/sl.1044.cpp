#include <iostream>
#include "lib1044.h"
using namespace std;
/*

int main(){
    int L, U, M;
    cin >> U;
    L = 1;
    M = (L + U)/2;
    while(U - L > 1){
        cout << "M = " << M;
        bool res;
        cin >>res;
        if(!res){
            L = M;
        } else {
            U = M;
        }
        M = (L + U)/2;
    }
    cout << M + 1 << endl;
}
*/

int main(){
    int L = 1, U = Initialize(), M = (L + U)/2;
    bool res;
    while(U - L > 1){
        res = Guess(M);
        if(!res){
            L = M;
        } else {
            U = M;
        }
        M = (L + U)/2;
    }
    if(Guess(M))
        Report(M);
    Report(M + 1);
}

