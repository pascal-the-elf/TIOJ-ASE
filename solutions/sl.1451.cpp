#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 1e5 + 10;
int N, M, a, b, belong[maxN], vis[maxN], cnt, need[maxN];
vector<int> adj[maxN], rev[maxN], ord;

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

void dfs(int x){
	vis[x] = true;
	for(int v : adj[x]){
		if(!vis[v]) dfs(v);
	}
	ord.push_back(x);
}

void dfs2(int x){
	vis[x] = true;
	belong[x] = cnt;
	for(int v : rev[x]){
		if(!vis[v]) dfs2(v);
	}
}

int main(){
	Read(N);
	Read(M);
	while(M--){
		Read(a);
		Read(b);
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for(int i = 1; i <= N; i++) if(!vis[i]) dfs(i);
	reverse(ord.begin(), ord.end());
	fill(vis, vis + N + 1, false);
	for(int v : ord){
		if(!vis[v]){
			cnt++;
			dfs2(v);
		}
	}
	for(int i = 1; i <= N; i++){
		for(int x : adj[i]){
			if(belong[x] != belong[i]) need[belong[x]] = true;
		}
	}
	int ans = 0;
	for(int i = 1; i <= cnt; i++) ans += !need[i];
	printf("%d\n", ans);
}


