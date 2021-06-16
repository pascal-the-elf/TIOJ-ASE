#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e4 + 10, MOD = 1e4;

int dp[2][maxN], ans[maxN], N;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}
signed main(){
	for(int i = 0; i < maxN; i++){
		dp[0][i] = 1;
	}
	ans[0] = 1;
	for(int y = 1; y < 2 * maxN; y++){
		for(int x = 0; x < maxN; x++){
			dp[1][x] = 0;
			if(2 * x >= y){
				dp[1][x] = add(dp[1][x], dp[0][x]);
				if(2 * (x - 1) >= y){
					dp[1][x] = add(dp[1][x], dp[1][x - 1]);
				}
			}
		}
		for(int x = 0; x < maxN; x++){
			dp[0][x] = dp[1][x];
		}
		if(y % 2 == 0) ans[y / 2] = dp[0][y / 2]; 
	}
	while(cin >> N){
		if(!N) return 0;
		if(N < 8) cout << ans[N] << endl;
		else {
			string s = to_string(ans[N] % (int)1e4);
			while(s.length() < 4) s = '0' + s;
			cout << s << endl;
		}
	}
}
