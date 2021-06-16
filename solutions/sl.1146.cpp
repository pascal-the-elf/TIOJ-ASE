#include <iostream>
#include <vector>
#include <string.h>
#define vv vector<vector<int> >
using namespace std;

int N, K, u, v;
string s;
vv I;

vv operator*(vv a, vv b){
	vv r;
	r.resize(N);;
	for(int i = 0; i < N; i++){
		r[i].resize(N);
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				r[i][j] += a[i][k] * b[k][j]; 
			}
		}
	}
	return r;
}

vv A, B;

int main(){
	cin >> N;
	A.resize(N);
	B.resize(N);
	I.resize(N);
	for(int i = 0; i < N; i++){
		A[i].resize(N);
		B[i].resize(N);
		I[i].resize(N);
		cin >> s;
		for(int j = 0; j < N; j++){
			B[i][j] = A[i][j] = s[j] - '0';
			I[i][j] = (i == j);
		}
	}
	cin >> u >> v >> K;
	int ans = 0;
	u--, v--;
	for(int i = 1; i <= K; i++, B = B * A){
		ans += B[u][v];
	}
	cout << ans << endl;
}
