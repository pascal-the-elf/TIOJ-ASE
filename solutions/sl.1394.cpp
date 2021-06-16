#include <stdio.h>
#define int unsigned short
int n, x, t, dp[32769][2], head[32769], sz[32769], adj[32769], cnt;

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


void dfs(int u){
	dp[u][0] = 0, dp[u][1] = 1;
	for(int i = 0; i < sz[u]; i++){
		int t = head[u] + i;
		dfs(adj[t]);
		dp[u][0] += dp[adj[t]][1];
		dp[u][1] += (dp[adj[t]][0] < dp[adj[t]][1] ? dp[adj[t]][0] : dp[adj[t]][1]);
	}
}
signed main(){
	Read(n);
    for(int i = 0; i < n; i++){
		Read(x);
		sz[i] = x;
		head[i] = cnt;
        while(x--){
			Read(t);
			adj[cnt++] = t;
        }
    }
	dfs(0);
	printf("%hu\n", (dp[0][1] <  dp[0][0] ? dp[0][1] : dp[0][0]));
}
