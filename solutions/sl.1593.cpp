#include <iostream>
#define int long long int
using namespace std;

int len[50], T, N, K;

int solve(int N, int K){
	if(N > 49 && (N & 1)) N = 49;
	if(N > 49 && !(N & 1)) N = 48;
	if(K > len[N]) return -1;
	if(N == 1) return 1;
	if(N == 2) return 2;
	if(N == 3){
		return K;
	}
	if(N & 1){
		if(K == len[N - 2]) return 3;
		if(K < len[N - 2]) return solve(N - 2, K);
		return solve(N - 1, K - len[N - 2] + 1);
	} else {
		if(K == len[N - 2]) return 2;
		if(K < len[N - 2]) return solve(N - 2, K);
		return solve(N - 1, K - len[N - 2]);
	}
}

signed main(){
	len[1] = len[2] = 1;
	len[3] = 2;
	for(int i = 4; i < 50; i++) len[i] = (len[i - 1] + len[i - 2]) - (i & 1);
	//for(int i = 1; i < 50; i++) cout << len[i] << endl;
	cin >> T;
	while(T--){
		cin >> N >> K;
		if(N <= 0 || K < 0){
			cout << -1 << endl;
			continue;
		}
		cout << solve(N, K) << endl;
	}
}
