#include <iostream>
using namespace std;

const int maxN = 16;   

int dp[maxN][1 << (maxN + 1)], nxt[1 << (maxN + 1)], N, M, K, cle;

inline int add(int a, int b){
	return (a + b >= K ? a + b - K : a + b);
}

inline int solve(int N, int M, int K){
	if(N < M) swap(N, M);
	for(register int i = 0; i < (1 << (M + 1)); i++) dp[0][i] = ((i & 7) != 7);
	for(register int i = 1; i < N; i++){
		for(register int j = 1; j < M; j++){
			for(register int k = 0; k < (1 << (M + 1)); k++){
				int cnt = ((k >> (j - 1)) & 1) + ((k >> (j)) & 1) + ((k >> (j + 1)) & 1);
				if(cnt > 2){
					dp[j][k] = 0;
					continue;
				} 
				dp[j][k] = dp[j - 1][(k & ((1 << (M + 1)) - 1) - (1 << j))];
				if(cnt < 2){
					dp[j][k] = add(dp[j][k], dp[j - 1][k | (1 << j)]); 
				}
				//cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
			}
		}
		if(i < N - 1){
			for(register int k = 0; k < (1 << (M + 1)); k++){
				int cnt = (k & 1) + ((k >> 1) & 1) + ((k >> 2) & 1);
				if(cnt > 2){
					nxt[k] = 0;
					continue;
				}
				nxt[k] = add(dp[M - 1][(k >> 1) + (1 << (M))], dp[M - 1][(k >> 1)]);
				//cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
			}
			for(register int k = 0; k < (1 << (M + 1)); k++){
				dp[0][k] = nxt[k];
				nxt[k] = 0;
			}
		}

	}
	int ans = 0;
	for(register int i = 0; i < (1 << (M + 1)); i++) ans = add(ans, dp[M - 1][i]);
	return ans;
}

signed main(){
	cin >> N >> M >> K;	
	cout << solve(N, M, K);
	for(int i = 1; i <= maxN; i++){
		cout << "{";
		for(int j = 1; j <= i; j++){
			cout << solve(i, j
		}
	}
}
