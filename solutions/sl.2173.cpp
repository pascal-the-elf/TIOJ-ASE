#include <iostream>
using namespace std;

const int maxN = 326;

int mp[maxN][maxN], dp[maxN][maxN][maxN], N, M;

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> mp[i][j];
	dp[0][0][0] = mp[0][0];
	for(int d = 1; d <= N + M - 2; d++){
		for(int a = 0; a < M; a++){
			for(int b = 0; b < M; b++){
				dp[d][a][b] = -100000; 
				if((d - a < 0 || d - a >= N || d - b < 0 || d - b >= N) || (mp[d - a][a] == -1 || mp[d - b][b] == -1)){
					//cout << "dp[" << d << "][" << a << "][" << b << "] = " << dp[d][a][b] << endl;
					continue;
				}
				int w = mp[d - a][a] + mp[d - b][b] - (a == b) * mp[d - b][b];
				if(d - a - 1 >= 0){
					if(d - b - 1 >= 0){
						if(dp[d - 1][a][b] >= 0)
							dp[d][a][b] = max(dp[d][a][b], dp[d - 1][a][b] + w);
					} if(b - 1 >= 0){
						if(dp[d - 1][a][b - 1] >= 0) 
							dp[d][a][b] = max(dp[d][a][b], dp[d - 1][a][b - 1] + w);
					} 
				} if(a - 1 >= 0){
					if(d - b - 1 >= 0){
						if(dp[d - 1][a - 1][b] >= 0) 
							dp[d][a][b] = max(dp[d][a][b], dp[d - 1][a - 1][b] + w);
					} if(b - 1 >= 0){
						if(dp[d - 1][a - 1][b - 1] >= 0) 
							dp[d][a][b] = max(dp[d][a][b], dp[d - 1][a - 1][b - 1] + w);
					}
				}
				//cout << "dp[" << d << "][" << a << "][" << b << "] = " << dp[d][a][b] << endl;
			}
		}
	}
	cout << max(0, dp[N + M - 2][M - 1][M - 1]) << endl;
}
