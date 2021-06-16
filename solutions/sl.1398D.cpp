#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 326;
int R, G, B, r[maxN], g[maxN], b[maxN], dp[maxN][maxN][maxN];

int main(){
	cin >> R >> G >> B;
	for(int i = 1; i <= R; i++) cin >> r[i];
	for(int i = 1; i <= G; i++) cin >> g[i];
	for(int i = 1; i <= B; i++) cin >> b[i];
	sort(r + 1, r + R + 1, greater<int>());
	sort(g + 1, g + G + 1, greater<int>());
	sort(b + 1, b + B + 1, greater<int>());
	for(int i = 0; i <= R; i++){
		for(int j = 0; j <= G; j++){
			for(int k = 0; k <= B; k++){
				if(i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				if(j) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
				if(k) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
				if(i && j) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i] * g[j]);
				if(i && k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i] * b[k]);
				if(j && k) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + b[k] * g[j]);
				//cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
			}
		}
	}
	cout << dp[R][G][B];
}
