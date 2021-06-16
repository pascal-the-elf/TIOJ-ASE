#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e7 +  10;

inline char readchar() {
    static const size_t bufsize = 65536;
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

int T, N, K, L, vals[maxN], ladd, radd, ans = (int)1e18, _a, lft[maxN], rgt[maxN];


inline void solve(){
    Read(N);
    Read(K);
    Read(L);
    ladd = radd = 0;
    ans = 1e18;
    for(int i = 0; i <= N + 10; i++) lft[i] = rgt[i] = 0;
    for(int i = 1; i <= N; i++){
        Read(vals[i]);
    }
    for(int i = 1; i <= N; i++){
        lft[i] =  vals[i] + min(vals[i], L - vals[i]);
        if(i - K >= 1) lft[i] += lft[i - K];
    }
    for(int i = N; i >= 1; i--){
        rgt[i] = (L - vals[i]) + min(vals[i], L - vals[i]);
        if(i + K <= N) rgt[i] += rgt[i + K];
    }
    for(int i = 0; i <= N; i++) ans = min(ans, lft[i] + rgt[i + 1]);
    cout << ans << '\n';
}

signed main(){
    Read(T);
    while(T--){
        solve();
    }

}
