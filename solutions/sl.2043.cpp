#include <cstdio>
#include <vector>
#define int long long int

const int MOD = 1e9 + 7, maxN = 2001, jizz = 1e9 + 5;

int fact[maxN], invFact[maxN], dp[maxN], sts[maxN], ans;
std::vector<int> adj[maxN];

int inv(int x){
	int r = 1, b = x;
	for(int i = 0; i < 32; i++){
		if((jizz >> i) & 1) r = r * b % MOD;
		b = b * b % MOD;
	}
	return r;
}

inline char readchar() {
    static const size_t bufsize = 16384;
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


//p = ki + t
//ki = -t (mod p)
//-(t^-1)ki = 1 mod(p)
//(p - (t^-1)) * k

int N, u, v;

void run(int p, int u){
	sts[u] = 1;
	for(int v : adj[u]){
		if(v == p) continue;
		run(u, v);
		sts[u] += sts[v];
	}
	dp[u] = fact[sts[u] - 1]; 
	for(int v : adj[u]){
		if(v == p) continue;
		dp[u] = dp[u] * invFact[sts[v]] % MOD;
		dp[u] = dp[u] * dp[v] % MOD;
	}
}

void reroot(int p = 1, int u = 1){
	ans = (ans + dp[u]) % MOD;
	//cout << "ans for u = " << u << " is " << dp[u] << endl;
	for(int v : adj[u]){
		if(v == p) continue;	
		int _stsu = sts[u], _stsv = sts[v], _dpu = dp[u], _dpv = dp[v];
		dp[u] = invFact[sts[u] - 1] * dp[u] % MOD;
		dp[u] = fact[sts[u] - 1 - sts[v]] * dp[u] % MOD;
		dp[u] = fact[sts[v]] * dp[u] % MOD;
		dp[u] = inv(dp[v]) * dp[u] % MOD; 
		sts[u] = (sts[u] - sts[v]);
		dp[v] = invFact[sts[v] - 1] * dp[v] % MOD;
		dp[v] = fact[N - 1] * dp[v] % MOD;
		dp[v] = invFact[sts[u]] * dp[v] % MOD;
		dp[v] = dp[u] * dp[v] % MOD;
		sts[v] = N;
		reroot(u, v);
		sts[u] = _stsu;
		sts[v] = _stsv;
		dp[u] = _dpu;
		dp[v] = _dpv;
	}
}

signed main(){
	Read(N);
	fact[0] = invFact[0] = 1;
	for(int i = 1; i <= N; i++){ 
		fact[i] = fact[i - 1] * i % MOD;
		invFact[i] = inv(fact[i]);
	}
	for(int i = 0; i < N - 1; i++){
		Read(u); Read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	run(1, 1);
	reroot();
	printf("%lld\n", ans);
}

