#include <iostream>
#include <string.h>
using namespace std;
// By S
string P, Q;

int main(){
    cin >> P >> Q;
    int lp = P.length(), lq = Q.length(), L= lp + lq + 1, fail[L];
    string S = P + '$' + Q;
    fail[0] = -1;
    for(int i = 1; i < L; i++){ //get failure function
        int q = fail[i-1];
        while(q > 0 && S[q+1] != S[i]){
            q = fail[q];
        }
        if(S[q+1] == S[i]) q++;
        fail[i] = q;
    }
    cout << fail[L-1] + 1 << endl;
}
