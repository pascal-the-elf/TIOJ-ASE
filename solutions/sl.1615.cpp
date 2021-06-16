#include <iostream>
#include <vector>
#define LL long long
#define N 4000000
#define pb push_back
using namespace std;

LL int a, b, primepre[N + 5];
bool isPrime[N + 5];
vector <LL int> primes;

void getPrime(){
    for(int i = 0 ; i <= N; i++){
        isPrime[i] = (i % 2);
        primepre[i] = 0;
    }
    isPrime[2] = true;
    isPrime[1] = false;
    primepre[2] = 1;
    primes.pb(2);
    for(LL int i = 3; i <= N; i++){
        if(isPrime[i]){
            primes.pb(i);
            primepre[i]++;
        }
        int l = primes.size();
        for(LL int j = 0; j < l && primes[j] * i < N; j++){
            isPrime[ primes[j] * i ] = false;
            if(!(i % primes[j])) break;
        }
        primepre[i] += primepre[i-1];
    }
}

int findNoPrimeFactors(LL int K){
    if(K == 1 || K <= b) return 0;
    int res = 0, l = primes.size();
    for(int i = 0; primes[i] * primes[i] <= K ; i++){
        if(!(K % primes[i])){
            while(!(K % primes[i]))
                K /= primes[i];
            if(primes[i] <= b){
                return findNoPrimeFactors(K);
            }
            return 1 + findNoPrimeFactors(K);
        }
    }
    return !(K <= b);
}


int main(){
    getPrime();
    while(cin >> a >> b){
        if(a < b) swap(a, b);
        unsigned LL int rem = 1;
        for(LL int i = b + 1; i <= a; i++)
            rem *= i;
        rem++;
        //printf("there are %d primes under %d\n", primepre[b], b);
        printf("%lld\n", primepre[b] + findNoPrimeFactors(rem));
    }
}
