#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e5 + 10;
int N, M, k, x, bit[maxN], cnt = 1, l[maxN], r[maxN], adj[maxN], pt[maxN], m = 0, deg[maxN];


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


inline void mod(int p){
    for(; p < maxN; p += (p & -p)) bit[p] ^= 1;
}

inline int que(int p){
    int r = 0;
    for(; p; p -= (p & -p)) r ^= bit[p];
    return r;
}

void dfs(int x = 0){
    l[x] = cnt++;
    for(int i = 0; i < deg[x]; i++){
        dfs(adj[i + pt[x]]);
    }
    r[x] = cnt;
}



int main(){
    Read(N);
    Read(M);
    for(int i = 0; i < N; i++){
        Read(deg[i]);
        pt[i] = m;
        while(k--){
            Read(x);
            x--;
            adj[m++] = x;
        }
    }
    dfs();
    while(M--){
        Read(k);
        Read(x);
        x--;
        if(k == 0){ //mod
            mod(l[x]);
            mod(r[x]);
        } else { //que
            cout << que(l[x]) << '\n';
        }
    }
}
