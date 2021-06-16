#include <iostream>
#include <queue>
using namespace std;

struct Dinic{
	static const int MXN = 10000;
	struct Edge{ int v, f, re; };
	int n, s, t, level[MXN];
	vector<Edge> E[MXN];
	void init (int _n, int _s, int _t){
		n = _n; s = _s; t = _t;
		for(int i = 0; i < n; i++) E[i].clear();
	}
#define SZ(x) ((int)x.size())
#define PB push_back
	void add_edge(int u, int v, int f){
		E[u].PB({v, f, SZ(E[v])});
		E[v].PB({u, 0, SZ(E[u]) - 1});
	}
	bool BFS(){
		for(int i = 0; i < n; i++) level[i] = -1;	
		queue<int> que;
		que.push(s);
		level[s] = 0;
		while(!que.empty()){
			int u = que.front(); que.pop();
			for(auto it : E[u]){
				if(it.f > 0 && level[it.v] == -1){
					level[it.v] = level[u] + 1;	
					que.push(it.v);
				}
			}
		}
		return level[t] != -1;
	}
	int DFS(int u, int nf){
		if(u == t) return nf;	
		int res = 0;
		for(auto &it : E[u]){
			if(it.f > 0 && level[it.v] == level[u] + 1){
				int tf = DFS(it.v, min(nf, it.f));	
				res += tf;
				nf -= tf;
				it.f -= tf;
				E[it.v][it.re].f += tf;
				if(!nf) return res;
			}
		}
		if(!res) level[u] = -1;
		return res;
	}
	int flow(int res = 0){
		while(BFS()){
			res += DFS(s, 2147283647);
		}
		return res;
	}
} flow;

int N, M, K, t, x;

int main(){
	cin >> N >> M >> K;
	flow.init(2 * N + M + 3, 0, 2 * N + M + 2);
	flow.add_edge(0, 1, K);
	for(int i = 1; i <= N; i++){
		flow.add_edge(0, i + 1, 1);
		flow.add_edge(1, N + i + 1, 1);
	}
	for(int i = 1; i <= M; i++){
		flow.add_edge(i + 2 * N + 1, 2 * N + M + 2, 1);
	}
	for(int i = 1; i <= N; i++){
		cin >> t;
		while(t--){
			cin >> x;
			flow.add_edge(i + 1, x + 2 * N + 1, 1);
			flow.add_edge(N + i + 1, x + 2 * N + 1, 1);
		}
	}
	cout << flow.flow() << endl;
}
