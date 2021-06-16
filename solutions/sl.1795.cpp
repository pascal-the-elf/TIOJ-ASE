#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

int N, M, K, u, v, w;

struct Edge{
	int u, v, w;
	Edge(){}
	Edge(int u, int v, int w): u(u), v(v), w(w){}
	bool operator<(Edge e) const {
		return w < e.w;
	}
};

vector<Edge> edgelist;

struct DSU{
	int dsu[maxN], N;
	DSU(){}
	DSU(int n): N(n){
		iota(dsu, dsu + N + 1, 0);
	}
	void Flat(int x){
		if(dsu[x] == x) return;
		Flat(dsu[x]);
		dsu[x] = dsu[dsu[x]];
	}
	bool Merge(int a, int b){
	    //cout << "Merging " << a << " and " << b << endl;
		Flat(a);
		Flat(b);
		if(dsu[a] == dsu[b]) return false;
		dsu[dsu[a]] = dsu[b];
		return true;
	}
} dsu;

int main(){
    ericxiao;
	cin >> N >> M >> K;
	edgelist.resize(M);
	dsu = DSU(N + 1);
	for(int i = 0; i < M; i++){
		cin >> u >> v >> w;
		edgelist[i] = Edge(u, v, w);
	}
	sort(edgelist.begin(), edgelist.end());
	int minSpan = 0, maxSpan = 0;
	for(Edge e : edgelist){
        //cout << "Looking at " << e.u << ", " << e.v << endl;
		if(dsu.Merge(e.u, e.v)) minSpan += e.w;
	}
    //cout << "K" << endl;
	//cout << "Done with MST" << endl;
	reverse(edgelist.begin(), edgelist.end());
	dsu = DSU(N + 1);
	for(Edge e : edgelist){
		if(dsu.Merge(e.u, e.v)) maxSpan += e.w;
	}
	if(minSpan <= K && K <= maxSpan){
		cout << "TAK\n";
	} else {
		cout << "NIE\n";
	}

}
