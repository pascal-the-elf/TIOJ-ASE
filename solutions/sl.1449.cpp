#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e3 + 226, INF = 1e18;
int arr[maxN], pre[maxN], dp[maxN][maxN], from[maxN][maxN], N, K, ans = INF;

inline int w(int i, int j){
	return (pre[j] - pre[(i + j) / 2]) - (j - (i + j) / 2) * arr[(i + j) / 2] + (arr[(i + j) / 2]) * ((i + j) / 2 - i) - (pre[(i + j) / 2 - 1] - pre[i - 1]);
}

signed main(){
	ericxiao;
	cin >> N >> K;
	K = min(K, N);
	arr[1] = 0;
	for(int i = 2; i <= N; i++) cin >> arr[i];
	sort(arr + 1, arr + 1 + N);
	for(int i = 2; i <= N; i++) pre[i] = arr[i] + pre[i - 1];
	for(int i = 1; i <= K; i++){
		dp[i][i] = 0;	
		from[i][i] = i;
	}
	for(int l = 1; l <= N; l++){
		for(int k = 1, i = 1 + l; k <= K && i <= N; k++, i++){
			//cout << "k = " << k << ", i = " << i << endl;
			dp[k][i] = INF;
			int lb = (k <= K ? from[k][i - 1] : 1);
			int ub = (k + 1 <= K ? from[k + 1][i] : N);
			for(int j = lb; j <= ub; j++){
				if(dp[k][i]	> dp[k - 1][j - 1] + w(j, i)){
					dp[k][i] = dp[k - 1][j - 1] + w(j, i);
					from[k][i] = j;
				}
			}
		}
	}
	cout << dp[K][N] << endl;
}
