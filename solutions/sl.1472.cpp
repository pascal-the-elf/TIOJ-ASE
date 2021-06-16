#pragma GCC target("popcnt")
#pragma gcc optimize ("O3", "unroll-loops")
#include <iostream>
using namespace std;

const int maxN = 24, M = 1e9 + 7;
int ind[1 << maxN], s[maxN], t[maxN], N, dp[1 << maxN], val[1 << maxN], x;

inline bool nocon(int a, int b){
	if(s[a] > s[b]) swap(a, b);
	return t[b] < t[a] || s[b] > t[a];
}

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> s[i] >> t[i];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(nocon(i, j)) ind[1 << i] |= (1 << j);
		}
	}
	for(register int i = 1; i < (1 << N); i++){
		x = i & -i;
		dp[i] = dp[i - x] + dp[i & ind[x]] + 1;
		val[i] = dp[i];
	}
	for(int k = 1; k <= N; k++){
		long long int c = 0;
		for(register int i = 1; i < (1 << N); i++){
			if(__builtin_popcount(i) & 1) c += val[i];
			else c -= val[i];
			if(c >= M) c -= M;
			if(c <  0) c += M;
		}
		if(c != 0){
			cout << k << endl;
			return 0;
		}
		for(int i = 1; i < (1 << N); i++) val[i] = (long long int)val[i] * dp[i] % M;
	}
}
