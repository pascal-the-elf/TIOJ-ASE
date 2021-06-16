#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e3 + 226;
int T, N, vals[maxN], dp[maxN][maxN];

inline bool isSame(int a, int b, int c, int d){
	return (min(a, b) == min(c, d) && max(a, b) == max(c, d));
}

inline int add(int a, int b){
	return (a + b >= N) ? a + b - N : a + b;	
}

inline int sub(int a, int b){
	return (a < b ? a - b + N : a - b);
}

inline void solve(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> vals[i];
		for(int j = 0; j < N; j++) 
			dp[i][j] = 0;
	}
	int l, r;	
	for(int len = 2; len <= N; len += 2){
		for(l = 0; l < N; l++){
			if(len == 2){
				dp[l][add(l, 1)] = (vals[l] == vals[add(l, 1)]);
				continue;
			}
			r = (l + len - 1) % N;
			dp[l][r] = dp[add(l, 2)][r] + (vals[l] == vals[add(l, 1)]);
			dp[l][r] = max(dp[l][r], dp[add(l, 1)][sub(r, 1)] + (vals[l] == vals[r]));
			for(int i = add(l, 3); i != r; i = add(i, 2)){
				//cout << "i = " << i << ", v = " << dp[add(l, 1)][sub(i, 1)] + dp[add(i, 1)][r] +(vals[l] == vals[i]) << endl;
				dp[l][r] = max(dp[l][r], dp[add(l, 1)][sub(i, 1)] + dp[add(i, 1)][r] +(vals[l] == vals[i]));	
			}
			//cout << "dp[" << l << "][" << r << "] = " << dp[l][r] << endl;
		}
	}
	cout << dp[0][N - 1] << endl;
}

int main(){
	ericxiao;
	cin >> T;	
	while(T--){
		solve();
	}
}
