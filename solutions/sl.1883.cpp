#include <iostream>
using namespace std;

const int maxN = 1e3 + 10;

int T, W, B, N, M, a[maxN], d[maxN];

inline char readchar();
inline void const Read(int &p);

inline bool check(int i, int j){
    if((B + d[i] - 1) / d[i] * (M + a[i]) < W) return true;
    if(((B / d[i] + 1) * M + a[j] + B / d[i] * a[i]) < W && (B % d[i] - d[j]) <= 0) return true;
    return false;
}

inline void solve(){
    Read(W), Read(B), Read(N);
    for(int i = 0; i < N; i++){
        Read(a[i]);
        Read(d[i]);
    }
    Read(M);
    bool can = false;
    for(int i = 0; i < N && !can; i++){
        for(int j = 0; j < N && !can; j++){
            //if(i == j) continue;
            can |= check(i, j);
        }
    }
    if(can) cout << "Yes\n";
    else cout << "No\n";
}


int main(){
    Read(T);
    while(T--){
        solve();
    }
}

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
