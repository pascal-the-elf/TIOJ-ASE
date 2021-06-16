#include <cstdio>
#include <vector>
#include <bitset>
#define N 10000000
using namespace std;
//By S
bitset<N+5> isPrime;
vector <int> primes;
int ans[N + 5];

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

void getPrimes(){
    for(int i = 0; i < N + 5; i++){
        isPrime[i] = i % 2;
    }
    isPrime[2] = true;
    isPrime[1] = false;
    primes.push_back(2);
    ans[1] = 0;
    ans[2] = 1;
    for(int i = 3; i < N + 5; i++){
        ans[i] = ans[i-1];
        if(isPrime[i]){
            primes.push_back(i);
            ans[i]++;
        }
        int l = primes.size();
        for(int j = 0; j < l && primes[j] * i < N; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
        //printf("%d primes <= than %d\n", ans[i], i);
    }
}

int n, m;

int main(){
    getPrimes();
    Read(n);
    for(int i = 0; i < n; i++){
        Read(m);
        printf("%d\n", ans[m]);
    }
}
