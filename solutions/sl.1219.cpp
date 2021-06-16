#include <iostream>
#include <vector>
using namespace std;

const int maxN = 5e4 + 10;

vector<int> primes;
bool isPrime[maxN];
int mu[maxN], a, b, d, ans = 0;

inline void init(){
    fill(isPrime, isPrime + maxN, 1);
    mu[1] = 1;
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]){
            mu[i] = -1;
            primes.push_back(i);
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
    while(cin >> a >> b >> d){
        if(!a && !b && !d) return 0;
        a /= d;
        b /= d;
        if(a > b) swap(a, b);
        ans = 0;
        for(int i = 1; i <= a; i++) ans += mu[i] * (a / i) * (b / i);
        cout << ans << endl;
    }
}

