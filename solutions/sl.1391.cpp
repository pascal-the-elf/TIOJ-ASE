#include <iostream>
using namespace std;

const int maxN = 326, INF = 2e5;
int N, t[maxN][maxN], dp[maxN][maxN];

inline void solve(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			cin >> t[i][j];
			dp[i][j] = INF;
		}
	}
	int ans = 0;
	dp[0][0] = t[0][0];
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			ans = max(ans, t[i][j]);
			dp[i + 1][j] = max(t[i + 1][j], dp[i][j] + 1); 
			dp[i + 1][j + 1] = min(t[i + 1][j], dp[i][j] + 1); 
		}
	}
	cout << ans << endl;
}
int main(){
	while(cin >> N){
		solve();
	}
}
