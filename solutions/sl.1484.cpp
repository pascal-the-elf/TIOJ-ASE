#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

int t, n, m, u, v;

int dep[maxN], low[maxN];
bool isCut[maxN], visited[maxN], hasV[maxN], hasE[maxN];
vector<int> opE, opV;
vector<pii> adj[maxN];

inline char readchar(){
	static const int size = 1 << 16;
	static char buf[size], *p = buf, *e = buf;
	if(p == e && (p = buf) == (e = fread(buf, sizeof(char), size, stdin) + buf))return EOF;
	return *p++;
}
template<class T>
void read(T &v){
	static char p;
	bool minus = false;
	while(!isdigit(p = readchar()))minus = p == '-';
	v = p ^ '0';
	while(isdigit(p = readchar())) v *= 10, v += p ^ '0';
}

struct Tarjan{

    Tarjan(){
        for(int i = 0; i < n; i++) vector<pii>().swap(adj[i]);
		vector<int>().swap(opE);
		vector<int>().swap(opV);
		fill(visited, visited + n, false);
        fill(isCut, isCut + n, false);
    }
    void addEdge(int u, int v, int i){
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    void dfs(int p, int u){
		dep[u] = dep[p] + 1;
		low[u] = dep[u];
		visited[u] = true;
		int cc = 0;
		for(pii e : adj[u]){
            if(e.F == p) continue;
			if(visited[e.F]){
				low[u] = min(low[u], dep[e.F]);
			} else {
				cc++;
				dfs(u, e.F);
				low[u] = min(low[u], low[e.F]);
				if(low[e.F] >= dep[u]) isCut[u] = true;
			}
		}
		if(p == u ){
            isCut[u] = (cc > 1);
		}
    }
	void getSize(int x, int &v, int &e){
		visited[x] = true;
		for(auto p : adj[x]){
			if(!hasE[p.S]){
				e++;
				hasE[p.S] = true;
				opE.push_back(p.S);
			}
			if(!hasV[p.F]){
				v++;
				hasV[p.F] = true;
				opV.push_back(p.F);
			}
			if(!visited[p.F] && !isCut[p.F]){
				getSize(p.F, v, e);
			}
		}
	}
    bool solve(){
        dep[0] = 0;
        dfs(0, 0);
        for(int i = 0; i < n; i++) if(!visited[i]) return false;
		fill(visited, visited + n, false);
		int v, e;
		for(int i = 0; i < n; i++){
			if(!visited[i] && !isCut[i]){
				v = 1, e = 0;
				hasV[i] = true;
				getSize(i, v, e);
				hasV[i] = false;
				//cout << "Running getSize(" << i << ")" << endl;
				if(v != e) return false;
				for(int x : opV) hasV[x] = false;
				for(int x : opE) hasE[x] = false;
				vector<int>().swap(opV);
				vector<int>().swap(opE);
			}
		}

		return true;
    }
} bcc;


int main(){
    ericxiao;
    read(t);
    while(t--){
        read(n);
        read(m);
        bcc = Tarjan();
        for(int i = 0; i < m; i++){
			read(u);
			read(v);
			if(u == v) continue;
			bcc.addEdge(u, v, i);
        }
        if(n == 1){
            cout << "YES\n";
            continue;
        }
		if(bcc.solve()) cout << "YES\n";
		else cout << "NO\n";
    }
}
