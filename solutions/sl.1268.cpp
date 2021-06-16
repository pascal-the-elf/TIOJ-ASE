#include <iostream>
#define max(a,b) (a>b?a:b)
using namespace std;

const int maxN = 3e3 + 326, INF = 2e9;
int arr[maxN][maxN], vpre[maxN][maxN], hpre, N, M, hm, vm[maxN], ans, dp;

int main(){
	scanf("%d", &N);
	scanf("%d", &M);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			scanf("%d\n", &arr[i][j]);
			vpre[i][j] = vpre[i - 1][j] + arr[i][j];
		}
	}
	for(int i = 1; i <= N; i++){
		int hm = 0, hpre = 0;
		for(int j = 1; j <= M; j++){
			hpre += arr[i][j];
			dp = max(hm + hpre, vm[j] + vpre[i][j]);
			dp = max(arr[i][j], dp);
			hm = max(hm, dp - hpre);
			vm[j] = max(vm[j], dp - vpre[i][j]);
			ans = max(ans, dp);
			//cout << "dp[" << i << "][" << j << "] = " << dp << endl;
		}
	}
	printf("%d\n", ans);
}
