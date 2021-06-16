#include <iostream>
#include <map>
#include <vector>
#define int long long int
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5000 + 226;
int nxt[maxN], dp[maxN], N, K, M, x; //dp[i][j] = first i items
map<int, int> mp;

inline int add(int a, int b){
	return (a + b >= M ? a + b - M : a + b);
}

inline void solve(){
	mp = map<int,int>();
	for(int i = 0; i < N; i++){
		cin >> x;
		mp[x]++;
	}
	fill(dp, dp + K + 1, 0);
	dp[0] = 1;
	for(auto [jizz, cnt] : mp){
		fill(nxt, nxt + K + 1, 0);
		for(int j = 0; j <= K; j++){
			for(int k = 0; k <= min(cnt, j); k++){
				nxt[j] = add(nxt[j], dp[j - k]);	
			}
		}
		for(int j = 0; j <= K; j++) dp[j] = nxt[j];
	}
	cout << dp[K] << '\n';
}

signed main(){
	ericxiao;
	while(cin >> N >> K >> M){
		solve();	
	}
}
