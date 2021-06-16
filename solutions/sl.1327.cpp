#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 226;
vector<pii> hori[maxN], vert[maxN];
vector<int> lisX, lisY;

int T, N, x, y, xsz, ysz, dsu[maxN];
pii	points[maxN]; 

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

struct Edge{
	int u, v, w;
	Edge(int u, int v, int w): u(u), v(v), w(w){}
	const bool operator<(const Edge &e) const {
		return w < e.w;
	}
};
vector<Edge> edges;

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

inline void solve(){
	Read(N);
	iota(dsu, dsu + N, 0);
	vector<Edge>().swap(edges);
	vector<int>().swap(lisX);
	vector<int>().swap(lisY);
	for(int i = 0; i < N; i++){
		vector<pii>().swap(hori[i]);
		vector<pii>().swap(vert[i]);
		Read(points[i].F);
		Read(points[i].S);
		lisX.push_back(points[i].F);
		lisY.push_back(points[i].S);
	}
	sort(lisX.begin(), lisX.end());
	sort(lisY.begin(), lisY.end());
	xsz = unique(lisX.begin(), lisX.end()) - lisX.begin();
	ysz = unique(lisY.begin(), lisY.end()) - lisY.begin();
	for(int i = 0; i < N; i++){
		points[i].F = lower_bound(lisX.begin(), lisX.begin() + xsz, points[i].F) - lisX.begin();
		points[i].S = lower_bound(lisY.begin(), lisY.begin() + ysz, points[i].S) - lisY.begin();
		hori[points[i].S].emplace_back(points[i].F, i);
		vert[points[i].F].emplace_back(points[i].S, i);
	}
	for(int i = 0; i < xsz; i++) sort(vert[i].begin(), vert[i].end());
	for(int i = 0; i < ysz; i++) sort(hori[i].begin(), hori[i].end());
	int id;
	pii p;
	for(int i = 0; i < N; i++){
		p = {points[i].F, -1};
		id = lower_bound(hori[points[i].S].begin(), hori[points[i].S].end(), p) - hori[points[i].S].begin() - 1;	
		if(id >= 0){
			edges.emplace_back(i, hori[points[i].S][id].S, lisX[points[i].F] - lisX[hori[points[i].S][id].F]);
		}
		if(id + 2 < hori[points[i].S].size()){
			edges.emplace_back(i, hori[points[i].S][id + 2].S, lisX[hori[points[i].S][id + 2].F] - lisX[points[i].F]);	
		}
		p = {points[i].S, -1};
		id = lower_bound(vert[points[i].F].begin(), vert[points[i].F].end(), p) - vert[points[i].F].begin() - 1;
		if(id >= 0){
			edges.emplace_back(i, vert[points[i].F][id].S, lisY[points[i].S] - lisY[vert[points[i].F][id].F]); 
		}
		if(id + 2 < vert[points[i].F].size()){
			edges.emplace_back(i, vert[points[i].F][id + 2].S, lisY[vert[points[i].F][id + 2].F] - lisY[points[i].S]);	
		}
	}
	sort(edges.begin(), edges.end());
	int ans = 0;
	for(Edge e : edges){
		ans += Merge(e.u, e.v) * e.w;	
	}
	printf("%lld\n", ans);
}

signed main(){
	ericxiao;
	Read(T);
	while(T--){
		solve();
	}
}
