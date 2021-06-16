#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e6 + 10;

int sts[maxN], maxChild[maxN], u, v, N, ans;
vector<int> adj[maxN];

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
    sts[u] = 1;
    int mc = 0;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(u, v);
        sts[u] += sts[v];
        mc = max(mc, sts[v]);
    }
    mc = max(mc, N - sts[u]);
    ans = min(ans, mc);
}

int main(){
    Read(N);
    for(int i = 0; i < N - 1; i++){
        Read(u);
        Read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = maxN;
    dfs(0, 0);
    cout << ans << '\n';
}
