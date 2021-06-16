#include <iostream>
#include <vector>
using namespace std;
const int maxN = 1e5 + 10;

int dep[maxN], low[maxN], T, N, M, u, v;
bool isCut[maxN], visited[maxN];
vector<int> adj[maxN], cuts;

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
    low[u] = dep[u] = dep[p] + 1;
    int chi = 0;
    visited[u] = true;
    for(int v : adj[u]){
        if(v == p) continue;
        if(visited[v]){
            low[u] = min(low[u], dep[v]);
        } else {
            chi++;
            dfs(u, v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dep[u]) isCut[u] = true;
        }
    }
    if(!p) isCut[u] = (chi > 1);
}

void solve(){
    Read(N);
    Read(M);
    fill(isCut, isCut + N + 1, false);
    fill(visited, visited + N + 1, false);
    vector<int>().swap(cuts);
    for(int i = 1; i <= N; i++) vector<int>().swap(adj[i]);
    for(int i = 0; i < M; i++){
        Read(u);
        Read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1);
    for(int i = 1; i <= N; i++) if(isCut[i]) cuts.push_back(i);
    cout << cuts.size() << '\n';
    if(cuts.size()) for(int x : cuts) cout << x << " ";
    else cout << 0;
    cout << '\n';

}

int main(){
    Read(T);
    while(T--){
        solve();
    }
}
