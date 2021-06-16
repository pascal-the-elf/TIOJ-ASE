#include <iostream>
#define int long long int
using namespace std;

int Q, P, X, K;

int exp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    if(e == 1) return b;
    int r = exp(b, e/2);
    r = r * r % P;
    if(e % 2) r = r * b % P;
    return r;
}

int f(int X, int k){
    return (((k % 2 ? 1 : -1) + P) * ((P == 2)*3 - X + P) % P) * exp(X, K - 1) % P;
}

//F(P, X, K) = -F(P, X, K - 1) * x
//F(P, X, 1) = P*(P + 1)/2 - X
//everything has to be mod P

signed main(){
    cin >> Q >> P;
    while(Q--){
        cin >> X >> K;
        cout << f(X, K) << endl;
    }
}
