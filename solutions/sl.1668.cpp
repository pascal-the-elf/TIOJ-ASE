#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxC = (1 << 16) + 226, maxL = 2e5 + 226;

bool isPrime[maxC];
vector<int> primes;

inline void initPrime(){
    fill(isPrime, isPrime + maxC, true);
    for(int i = 2; i < maxC; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes){
            if(i * p >= maxC) break;
            isPrime[i * p] = false;
            if(!(i % p)) break;
        }
    }
}
int T, l, r;
bool isP[maxL];

signed main(){
    ericxiao;
    initPrime();
    cin >> T;
    while(T--){
        cin >> l >> r;
        fill(isP, isP + (r - l + 1), true);
        for(int p : primes){
            if(p * p > r) break;
            for(int k = max(2 * p, ((l + p - 1) / p) * p); k <= r; k += p){
                isP[k - l] = false;
            }
        }
        int res = 0;
        for(int i = 0; i < (r - l + 1); i++) res += isP[i];
        cout << res << endl;
    }
}
