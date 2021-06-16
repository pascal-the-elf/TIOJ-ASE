#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MOD = 1e4 + 7, maxN = 1e6 + 10;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

inline int inv(int x){
    int t = MOD - 2;
    int r = 1, b = x;
    while(t){
        if(t & 1) r = r * b % MOD;
        b = b * b % MOD;
        t >>= 1;
    }
    return r;
}

int T, a, b, fib[maxN];
//0 1 1 2 3 5 8
//0 1 2 3 4 5 6
//    1 2 3 4 5
int main(){
    cin >> T;
    fib[1] = fib[2] = 1;
    for(int i = 3; i < maxN; i++){
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    while(T--){
        ericxiao;
        cin >> a >> b;
        a++;
        b++;
        //cout << "gcd = " << gcd(a, b) << endl;
        cout << (fib[a] * fib[b] % MOD) * inv(fib[gcd(a, b)]) % MOD * 2 % MOD << endl;
    }
}
