#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e3 + 10, maxM = 5e5 + 10, maxLog = 20, INF = 1e17;
struct Edge{
	int u, v, w, id;
	Edge(){}
	Edge(int U, int V, int W, int I): u(U), v(V), w(W), id(I){};
	const bool operator<(const Edge &e) const {
		return w < e.w;
	}
} e, edges[maxM];

bool inMST[maxM];
vector<pii> adj[maxN];
int dsu[maxN], anc[maxN][maxLog], ancD[maxN][maxLog], dist[maxN];

inline char readchar() {
    static const size_t bufsize = 1048576;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return (p == end ? EOF : *p++);
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

int N, M, u, v, w, minwei, ans;

void Flat(int x){
	if(x == dsu[x]) return;
	Flat(dsu[x]);
	dsu[x] = dsu[dsu[x]];
}

bool Merge(int a, int b){
	Flat(a);
	Flat(b);
	if(dsu[a] == dsu[b]) return false;
	dsu[dsu[a]] = dsu[b];
	return true;
}

void dfs(int p, int u){
	dist[u] = dist[p] + 1;
	if(p != u){
		for(int i = 1; i < maxLog; i++){
			anc[u][i] = anc[anc[u][i - 1]][i - 1];
			ancD[u][i] = max(ancD[u][i - 1], ancD[anc[u][i - 1]][i - 1]);
		}
	} else {
		for(int i = 0; i < maxLog; i++){
			anc[u][i] = u;
			ancD[u][i] = -INF;
		}
	}
	for(auto [v, w] : adj[u]){
		if(v == p) continue;
		anc[v][0] = u;
		ancD[v][0] = w;
		dfs(u, v);
	}
}

int getMax(int a, int b){
	if(dist[a] < dist[b]) swap(a, b);	
	int res = -INF, k = dist[a] - dist[b];
	for(int i = 0; i < maxLog; i++){
		if(((k) >> i) & 1){
			res = max(res, ancD[a][i]);
			a = anc[a][i];
		}
	}
	for(int i = 0; i < maxLog; i++){
		if(anc[a][i] != anc[b][i]){
			res = max(res, ancD[a][i]);
			res = max(res, ancD[b][i]);
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	res = max(res, ancD[a][0]);
	res = max(res, ancD[b][0]);
	return res;
}

signed main(){
	Read(N);
	Read(M);
	for(int i = 0; i < M; i++){
		Read(u);
		Read(v);
		Read(w);
		edges[i] = Edge(u, v, w, i);
	}
	sort(edges, edges + M);
	iota(dsu, dsu + N + 1, 0);
	for(int i = 0; i < M; i++){
		e = edges[i];
		inMST[i] = Merge(e.u, e.v);	
		if(inMST[i]){
			minwei += e.w;
			adj[e.u].emplace_back(e.v, e.w);
			adj[e.v].emplace_back(e.u, e.w);
		}
	}
	Flat(1);
	for(int i = 2; i <= N; i++){
		Flat(i);
		if(dsu[i] != dsu[1]){
			printf("-1 -1\n");
			return 0;
		}
	}
	dfs(1, 1);
	ans = INF;
	for(int i = 0; i < M; i++){
		if(!inMST[i]){
			if(minwei - getMax(edges[i].u, edges[i].v) + edges[i].w > minwei){
				ans = min(ans, minwei - getMax(edges[i].u, edges[i].v) + edges[i].w);
			}
		}
	}
	printf("%lld %lld\n", minwei, (ans == INF ? -1 : ans));
}
