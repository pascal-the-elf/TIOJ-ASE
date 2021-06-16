#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e6 + 10;

/*
Inclusion-Exclusion principle:
consider a prime p: There are N/(i*i) primes to subtract
p1 + p2 + p3 + ... + pn - (p1 and p2) - (p1 and p3) ...
so if there is a number that has more than one as its exponent just ignore it
if there are an even number of primes sub; else add
that's just the mu function! so it's sum (N/(t * t)) * mu(t)
*/

int mu[maxN];
bool isPrime[maxN];
vector<int> primes;

void init(){
    fill(isPrime, isPrime + maxN, true);
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]){
            primes.push_back(i);
            mu[i] = 1;
        }
        for(int p : primes){
            if(i * p >= maxN) break;
            isPrime[i * p] = false;
            if(!(i % p)){
                mu[i * p] = 0;
            } else {
                mu[i * p] = -mu[i];
            }
        }
    }
}

int main(){
    init();
    long long int N, ans = 0;
    cin >> N;
    for(long long int i = 1; i*i <= N; i++){
        ans += (N/(i * i)) * mu[i];
    }
    cout << ans << endl;
}
