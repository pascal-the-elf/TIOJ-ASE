#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 5e6 + 10;

vector<int> primes;
vector<pii> pf;
bool isPrime[maxN];
pii _p;
int oriN;

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


void init(){
    fill(isPrime, isPrime + maxN, true);
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes){
            if(i * p >= maxN) break;
            isPrime[i * p] = false;
            if(!(i % p)) break;
        }
    }
}

int Q, N;

bool can(int x){
    int pw, sum;
    for(pii p : pf){
        sum = 0;
        for(pw = 1; pw <= (x + p.F - 1) / p.F; pw *= p.F){
            sum += x / (pw * p.F);
        }
        if(sum < p.S) return false;
    }
    return true;
}

signed main(){
    init();
    Read(Q);
    while(Q--){
        Read(N);
        if(N < 0) N = -N;
        if(N <= 1){
            cout << 0 << endl;
            continue;
        }
        oriN = N;
        pf.clear();
        for(int p : primes){
            if(p * p > N) break;
            if(!(N % p)){
                _p = {p, 0};
                while(!(N % p)){
                    N /= p;
                    _p.S++;
                }
                pf.push_back(_p);
            }
        }

        if(N > 1) pf.push_back({N, 1});
        //cout << "pf of " << oriN << ": " << endl;
        //for(auto [p, e] : pf) cout << p << "^" << e << endl;
        int l = 1, r = oriN, m;
        while(l + 1 < r){
            m = (l + r) / 2;
            if(can(m)) r = m;
            else l = m;
        }
        cout << r << endl;
    }
}
