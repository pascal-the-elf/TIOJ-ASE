#include <iostream>
#include <queue>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;

priority_queue<int> childs[maxN];
vector<int> adj[maxN];

int lead[maxN], cost[maxN], sz[maxN], maxChild[maxN], ans, root, anc, N, budget, sum[maxN];

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
    sz[u] = 1;
    maxChild[u] = -1;

    for(int v : adj[u]){
        if(v == p) continue;
        dfs(u, v);
        if(maxChild[u] == -1 || childs[maxChild[u]].size() < childs[v].size()){
            maxChild[u] = v;
        }
    }

    if(~maxChild[u]){
        swap(childs[u], childs[maxChild[u]]);
        sum[u] = sum[maxChild[u]];
    }

    childs[u].push(cost[u]);
    sum[u] += cost[u];

    for(int v : adj[u]){
        if(v == p || v == maxChild[u]) continue;
        while(childs[v].size()){
            childs[u].push(childs[v].top());
            sum[u] += childs[v].top();
            childs[v].pop();
        }
        childs[v] = priority_queue<int>();
    }

    while(childs[u].size() && sum[u] > budget){
        sum[u] -= childs[u].top();
        childs[u].pop();
    }

    ans = max(ans, (int)childs[u].size() * lead[u]);
}

signed main(){
    Read(N);
    Read(budget);
    for(int i = 1; i <= N; i++){
        Read(anc);
        Read(cost[i]);
        Read(lead[i]);
        if(!anc) root = i;
        else {
            adj[anc].push_back(i);
            adj[i].push_back(anc);
        }
    }
    dfs(root, root);
    cout << ans << '\n';
}
