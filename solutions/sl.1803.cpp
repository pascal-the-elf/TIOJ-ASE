#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;


/*
Approach:
The problem boils down to finding the number of ways to partition 1~N to
equal directed cycles, which have cycle length d, with d satisfying
d | n and d | k.

f(n, k) calculates this number for a fixed cycle length k:

n! rearranges the whole permutation, then (n/k)! will disregard all diffs of loops.
Inside each loop, the permutations are disregarded, thus dividing by k! for each loop,
that is, dividing by (k!)^(n/k). Now we have the number of ways to parition n numbers
into sizes of k each. Then for each group, we multiply by k! to permute, and because loops
are the same under cyclic shifts, we divide by k, to yield (k - 1)! for each loop, giving
[(k - 1)!]^(n / k). Multiplication of the above yields the number for fixed k, and we must
sum over all common divisors to get the answer.

*/

const int maxN = 1e6 + 10, MOD = 1e9 + 7;

int fact[maxN];

int modpow(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int r = modpow(b, e/2);
    r = r * r % MOD;
    if(e % 2) r = r * b % MOD;
    return r;
}

int modinv(int x){
    return modpow(x, MOD - 2);
}

int f(int n, int k){
    return ((fact[n] * modinv(fact[n / k]) % MOD) * modpow(fact[k - 1], n / k) % MOD) * modinv(modpow(fact[k], n / k)) % MOD;
}

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

signed main(){
    ericxiao;
    fact[0] = 1;
    for(int i = 1; i < maxN; i++) fact[i] = fact[i - 1] * i % MOD;
    int n, k;
    while(cin >> n >> k){
        int g = gcd(n, k), a = 0;
        for(int i = 2; i * i <= g; i++){
            if(!(g % i)){
                a = (a + f(n, i)) % MOD;
                if(i * i != g){
                    a = (a + f(n, g/i)) % MOD;
                }
            }
        }
        if(g > 1)
            a = (a + f(n, g)) % MOD;
        cout << a << endl;
    }
}
