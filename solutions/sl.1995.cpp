#pragma gcc optimize ("Ofast")
#include <cstdio>
using namespace std;

const int maxLog = 23, maxN = 2500001, maxQ = 1000001;

int N, M, queries[maxQ][2], st[maxN], k, _lv;

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


inline void solve(){
    int l, q, i;
    for(l = 1; l < maxLog; l++){
        for(q = 0; q < M; q++){
            if(queries[q][1] != -1 && (1 << (l - 1)) <= queries[q][1] - queries[q][0] && queries[q][1] - queries[q][0] < (1 << (l))){
                queries[q][0] = st[queries[q][0]] > st[queries[q][1] - (1 << (l - 1))] ? st[queries[q][0]] : st[queries[q][1] - (1 << (l - 1))];
                queries[q][1] = -1;
            }
        }
        for(i = 0; i <= N - (1 << l); i++){
            st[i] = st[i] > st[i + (1 << (l - 1))] ? st[i] : st[i + (1 << (l - 1))];
        }
    }
}

int main(){
    Read(N);
    Read(M);
    for(int i = 0; i < M; i++){
        Read(queries[i][0]);
        Read(queries[i][1]);
        queries[i][0]--;
        k = queries[i][1] - queries[i][0];
        _lv = 0;
        for(; (1 << _lv) <= k; _lv++);
    } //0-based [,)
    for(int i = 0; i < N; i++){
        Read(st[i]);
    }
    solve();
    for(int i = 0; i < M; i++){
        printf("%d\n", queries[i][0]);
    }
}
