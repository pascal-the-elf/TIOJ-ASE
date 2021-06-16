#pragma gcc optimize "Ofast"
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e6 + 10, maxLog = 21, MOD = 1000000007;


inline char readchar() {
    static const size_t bufsize = 1048576;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
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

int minF[maxN], l, r, cnt = 0, N, Q, ans[maxN], arr[maxN], bit[maxN];
//long long int pows[maxN][maxLog], invpow[maxN][maxLog];
bool isPrime[maxN];
vector<int> primes;
vector<pii> pf;

inline void factorize(int x){
    pf.clear();
    pii cur;
    while(x > 1){
        cur = {minF[x], 0};
        while(!(x % cur.F)){
            x /= cur.F;
            cur.S++;
        }
        pf.push_back(cur);
    }
}

struct Query{
    int l, r, id;
    Query(){}
    Query(int L, int R, int I) : l(L), r(R), id(I){}
    const bool operator<(const Query & q) const {
        return r < q.r;
    }
} queries[maxN];

struct Obj{
    int pos, val;
    Obj(){}
    Obj(int P, int V): pos(P), val(V){}
    const bool operator<=(const Obj & o) const {
        return val <= o.val;
    }
} co;

deque<Obj> dandiao[maxN];

int qpow(int b, int e){
    long long int r = 1, c = b;
    for(int i = 0; i < 31; i++){
        if((e >> i) & 1) r = r * c % MOD;
        c = c * c % MOD;
    }
    return r;
}

inline int inv(int x){
    return qpow(x, MOD - 2);
}

inline void initPrime(){
    fill(isPrime, isPrime + maxN, true);
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]){
            primes.push_back(i);
            minF[i] = i;
        }
        for(int p : primes){
            if(i * p >= maxN) break;
            isPrime[i * p] = false;
            minF[i * p] = p;
            if(!(i % p)) break;
        }
    }
    /*
    for(long long int p : primes){
        long long int invp = inv(p);
        pows[p][0] = 1;
        invpow[p][0] = 1;
        for(int i = 1; i < maxLog; i++){
            pows[p][i] = pows[p][i - 1] * p % MOD;
            invpow[p][i] = invpow[p][i - 1] * invp % MOD;
        }
    }
    */
    fill(bit, bit + maxN, 1);
}

void modify(int p, long long int x){
    for(; p < maxN; p += (p & -p)) bit[p] = bit[p] * x % MOD;
}

int query(int p){
    long long int r = 1;
    for(; p; p -= (p & -p)) r = bit[p] * r % MOD;
    return r;
}

void disp(){
    for(int i = 1; i <= N; i++) cout << query(i) << " \n"[i == N];
}

signed main(){
    initPrime();
    Read(N);
    Read(Q);
    for(int i = 1; i <= N; i++) Read(arr[i]);
    for(int i = 0; i < Q; i++){
        Read(l);
        Read(r);
        queries[i] = Query(l, r, i);
    }
    sort(queries, queries + Q);
    for(int r = 1; r <= N; r++){
        factorize(arr[r]);
        for(auto [p, e] : pf){
            //cout << "p = " << p << ", e = " << e << endl;
            co = Obj(r, e);
            int ch = 0;
            while(dandiao[p].size() && dandiao[p].back().val <= co.val){
                modify(dandiao[p].back().pos, inv(qpow(p, dandiao[p].back().val - ch)));
                ch = dandiao[p].back().val;
                dandiao[p].pop_back();
            }
            if(!dandiao[p].size()) modify(r, qpow(p, e));
            else{
                modify(dandiao[p].back().pos, inv(qpow(p, e - ch)));
                modify(r, qpow(p, e));
            }
            dandiao[p].push_back(co);
        }
        while(cnt < Q && queries[cnt].r == r){
            ans[queries[cnt].id] = query(r) * (inv(query(queries[cnt].l - 1)) * 1LL) % MOD;
            cnt++;
        }
        //disp();
    }
    for(int i = 0; i < Q; i++) cout << ans[i] << '\n';
}
