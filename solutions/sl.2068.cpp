#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = (2345678 + 226) * 5;
bool isPrime[maxN];
vector<int> primes;

inline void getPrime(){
    fill(isPrime, isPrime + maxN, true);

    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes){
            if(p * i >= maxN) break;
            isPrime[p * i] = false;
            if(!(p % i)) break;
        }
    }
}

int N;
bool visited[maxN];

int main(){
    getPrime();
    reverse(primes.begin(), primes.end());
    scanf("%d", &N);
    int cnt = 0;
    for(int p : primes){
        if(p <= 4 * N - cnt && 4 * N - p - cnt > cnt){
            //cout << "p = " << p << ", cnt = " << cnt << ", to: " << 4 * N - p - cnt << endl;
            for(; !visited[cnt] && !visited[4 * N - p - cnt]; cnt++){
                visited[cnt] = visited[4 * N - p - cnt] = true;
                printf("%d %d\n", cnt, 4 * N  - p - cnt);
            }
            while(visited[cnt]) cnt++;
        }
    }
}
