#include <iostream>
#include <string.h>
#include <algorithm>
#define int long long int
using namespace std;
const int maxN = 22;

int dp[(1 << maxN)], nxtDp[(1 << maxN)], vals[(1 << maxN)], N, M, v;
string s;

signed main(){
	cin >> N >> M;
	while(M--){
		cin >> s >> v;
		int d = 0;
		for(int i = 0; i < N; i++){
			if(s[i] == '1') d += (1 << i); 
		}
		dp[d] += v;
	}
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < (1 << N); j++){
			if((j >> (i - 1)) & 1){
				nxtDp[j] = dp[j] + dp[j ^ (1 << (i - 1))];
			} else {
				nxtDp[j] = dp[j];
			}
		}
		for(int j = 0; j < (1 << N); j++) dp[j] = nxtDp[j];
	}
	for(int i = 1; i < (1 << N); i++){
		//cout << "vals[" << i << "] = " << dp[i] << endl;
		vals[i] = dp[i];
	}
	sort(vals + 1, vals + (1 << N));
	int ans = 0;
	for(int i = 1; i < (1 << N); i++){
		ans += vals[i] * (i);
	}
	cout << ans << endl;
}
