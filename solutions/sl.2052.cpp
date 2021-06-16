#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 2260, W = 52;

string s;
int D, frq[W], frac[maxN][maxN], rk = 0, to[maxN], pf[maxN][maxN];
bool isPrime[maxN];
vector<int> primes;

/*
Fucking modulus might not be prime
*/


inline int exp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int r = exp(b, e/2);
    r = r * r % D;
    if(e % 2) r = r * b % D;
    return r;
}

inline void init(){
    fill(isPrime + 1, isPrime + maxN, true);
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes){
            if(i * p >= maxN) break;
            isPrime[i * p] = false;
            if(!(i % p)) break;
        }
    }
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]){
            pf[i][i] = 1;
            continue;
        }
        int n = i;
        for(int p : primes){
            if(p * p > n) break;
            while(!(n % p)){
                pf[i][p]++;
                n /= p;
            }
        }
        if(n > 1) pf[i][n]++;
    }
    frac[2][2]++;
    for(int i = 3; i < maxN; i++){
        for(int p : primes) frac[i][p] = frac[i - 1][p] + pf[i][p];
    }
    for(int c = 'a'; c <= 'z'; c++) to[c] = c - 'a' + 26;
    for(int c = 'A'; c <= 'Z'; c++) to[c] = c - 'A';
}

struct Num{
    int factorization[maxN];
    void reset(){
        fill(factorization, factorization + maxN, 0);
    }
    void mult(int t){ //multiply by t!
        for(int p : primes){
            factorization[p] += frac[t][p];
        }
    }
    void div(int t){ //div by t!
        for(int p : primes){
            factorization[p] -= frac[t][p];
        }
    }
    int getVal(){
        int r = 1;
        for(int p : primes){
            r = r * exp(p, factorization[p]) % D;
        }
        return r;
    }
} num;


signed main(){
    cin >> D >> s;
    init(); //assume D is prime
    for(char c : s) frq[to[c]]++;
    for(int i = 0; i < s.length(); i++){
        for(int c = 0; c < to[s[i]]; c++){
            if(frq[c]){ //gogogo
                frq[c]--;
                num.reset();
                num.mult(s.length() - i - 1);
                for(int cc = 0; cc < W; cc++) num.div(frq[cc]);
                rk = (rk + num.getVal()) % D;
                frq[c]++;
            }
        }
        frq[to[s[i]]]--;
    }
    cout << rk << endl;
}
