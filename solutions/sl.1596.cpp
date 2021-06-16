#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;

const int maxN = 1e5 + 10;

int dsu[maxN], has[maxN], ans, N, M, u, v, w, k, x;

struct Edge{
	int u, v, w;
	Edge(){}
	Edge(int u, int v, int w): u(u), v(v), w(w){}
	const bool operator<(const Edge &e) const {
		return e.w < w;
	}
} edges[maxN];

void Find(int x){
	if(x == dsu[x]) return;
	Find(dsu[x]);
	has[x] |= has[dsu[x]];
	dsu[x] = dsu[dsu[x]];
}

inline bool Merge(int a, int b){ //returns canMerge
	Find(a);
	Find(b);
	if(dsu[a] == dsu[b]) return true;
	if(has[dsu[a]] && has[dsu[b]]) return false;
	has[dsu[a]] |= has[dsu[b]];
	dsu[dsu[b]] = dsu[a];
	return true;
}

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

signed main(){
	Read(N);
	Read(M);
	iota(dsu, dsu + N + 1, 0);
	for(int i = 0; i < M; i++){
		Read(u);
		Read(v);
		Read(w);
		edges[i] = Edge(u, v, w);
	}
	Read(k);
	while(k--){
		Read(x);
		has[x] = true;
	}
	sort(edges, edges + M);
	for(int i = 0; i < M; i++){
		if(!Merge(edges[i].u, edges[i].v)) ans += edges[i].w;	
	}
	printf("%lld\n", ans);
}

