#include <cstdio>
#include <vector>
#include <numeric>
using namespace std;

const int maxN = 2.5e5 + 10; //problem says 1e6 but that will MLE; 5e5 is required

vector<int> adj[maxN];

int N, M, u, v, K, Q, fat[maxN], dep[maxN], dsu[maxN];

void Flat(int x);
inline void Merge(int a, int b);

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


void dfs(int p, int u){
    dep[u] = dep[p] + 1;
    fat[u] = p;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(u, v);
    }
}

int main(){
    Read(N);
    Read(M);
    Read(K);
    Read(Q);
    iota(dsu, dsu + N + 1, 0);
    for(int i = 0; i < M; i++){
        Read(u);
        Read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    while(K--){
        Read(u);
        Read(v);
        Flat(u);
        Flat(v);
        u = dsu[u];
        v = dsu[v];
        if(dep[u] < dep[v]) swap(u, v);
        while(u != v){
            Merge(u, fat[u]);
            Merge(v, fat[v]);
            Flat(u);
            Flat(v);
            u = dsu[u];
            v = dsu[v];
        }
    }
    while(Q--){
        Read(u);
        Read(v);
        Flat(u);
        Flat(v);
        if(dsu[u] == dsu[v]) printf("1\n");
        else printf("0\n");
    }
}

void Flat(int x){
    if(x == dsu[x]) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

inline void Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dep[dsu[a]] > dep[dsu[b]]) swap(a, b);
    dsu[dsu[b]] = dsu[a];
    Flat(a);
    Flat(b);
    return;
}
