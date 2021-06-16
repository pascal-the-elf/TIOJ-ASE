#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1226;

int N, ans;
int x[maxN], t[maxN], y[maxN], match[maxN * 2], T;
bool visited[maxN * 2];
vector<int> adj[maxN * 2];

inline int Abs(int x){
	return x < 0 ? -x : x;
}

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

bool dfs(int x){
	for(int v : adj[x]){
		if(visited[v]) continue;
		visited[v] = true;
		if(match[v] == -1 || dfs(match[v])){
			match[v] = x;
			match[x] = v;
			return true;
		}
	}
	return false;
}

inline void solve(){
	Read(N);
	ans = 0;
	for(int i = 0; i <= N * 2; i++) vector<int>().swap(adj[i]);
	for(int i = 0; i < N; i++){
		Read(t[i]);
		Read(x[i]);
		Read(y[i]);
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j) continue;
			if(Abs(x[i] - x[j]) + Abs(y[i] - y[j]) + t[i] <= t[j]){
				adj[i].push_back(j + N);
				adj[j + N].push_back(i);
			}
		}
	}
	fill(match, match + 2 * N, -1);
	for(int i = 0; i < N; i++){
		fill(visited, visited + 2 * N, 0);
		if(dfs(i)) ans++;
	}
	printf("%d\n", N - ans);
}

int main(){
	Read(T);
	while(T--){
		solve();
	}
}
