#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7, maxN = 1e6 + 26;

int fact[maxN], T, N;

inline int mpow(int b, int e){
    int r = 1, c = b;
    for(int i = 0; i < 60; i++){
        if((e >> i) & 1){
            r = r * c % MOD;
        }
        c = c * c % MOD;
    }
    return r;
}

inline int inv(int x){
    return mpow(x, MOD - 2);
}

signed main(){
    fact[0] = 1;
    for(int i = 1; i <= maxN; i++){
        fact[i] = i * fact[i - 1] % MOD;
    }
    cin >> T;
    while(T--){
        cin >> N;
        N /= 2;
        cout << (fact[2 * N] * inv(fact[N]) % MOD) * inv(fact[N + 1]) % MOD << endl;
    }
}
