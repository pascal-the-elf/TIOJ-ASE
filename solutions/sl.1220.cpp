#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 1, maxM = 2e6 + 10;

int N, M, u, v, ans, t, last[maxN], nxt[maxN], prv[maxN], cnt, vis[maxN];

inline char readchar() {
    static const size_t bufsize = 1 << 20;
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
	int v, to;
} edges[maxM << 1];

queue<int> que;

void addEdge(int u, int v){
	edges[cnt] = {v, last[u]};
	last[u] = cnt++;
}

void del(int x){	
	int _p = prv[x];
	nxt[_p] = nxt[x];
	prv[nxt[x]] = _p;
}

void bfs(int src){
	que.push(src);
	int t;
	while(que.size()){
		t = que.front();
		que.pop();
		for(int cur = last[t]; ~cur; cur = edges[cur].to) vis[edges[cur].v]++;
		for(int i = nxt[0]; i; i = nxt[i]) if(!vis[i]){
			del(i);
			que.push(i);
		}
		for(int cur = last[t]; ~cur; cur = edges[cur].to) vis[edges[cur].v]--;
	}

}


int main(){
	ericxiao;
	cin >> N >> M;
	fill(last + 1, last + 1 + N, -1);
	for(int i = 0; i <= N; i++){
		prv[i] = i - 1;
		nxt[i] = i + 1;
	}
	prv[0] = nxt[N] = 0;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}
	for(int i = nxt[0]; i; i = nxt[0]){
		del(i);
		ans++;
		//cout << "Running bfs(" << nxt[0] << ")" << endl;
		bfs(i);
	}
	cout << ans << endl;
}
