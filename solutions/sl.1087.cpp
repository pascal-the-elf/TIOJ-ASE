#include <iostream>
#include "lib1087.h"
using namespace std;

const int maxN = 21;
int dp[maxN][maxN][maxN];

int main(){
	dp[0][0][0] = 1;
	for(int i = 0; i <= 10; i++){
		for(int j = 0; j <= 15; j++){
			for(int k = 0; k <= 20; k++){
				for(int a = 1; a <= i; a++) dp[i][j][k] = max(dp[i][j][k], 1 - dp[i - a][j][k]);
				for(int a = 1; a <= j; a++) dp[i][j][k] = max(dp[i][j][k], 1 - dp[i][j - a][k]);
				for(int a = 1; a <= k; a++) dp[i][j][k] = max(dp[i][j][k], 1 - dp[i][j][k - a]);
			}
		}
	}
	Initialize();
	int A = 10, B = 15, C = 20, P, N;
	while(true){
		bool t = false;
		for(int a = 1; a <= A && !t; a++){
			if(!dp[A - a][B][C]){
				A -= a;
				Take_Stone(1, a, &P, &N);
				if(P == 1){
					A -= N;
				} else if(P == 2){
					B -= N;
				} else {
					C -= N;
				}
			}
		}
		for(int a = 1; a <= B && !t; a++){
			if(!dp[A][B - a][C]){
				B -= a;
				Take_Stone(2, a, &P, &N);
				if(P == 1){
					A -= N;
				} else if(P == 2){
					B -= N;
				} else {
					C -= N;
				}
			}
		}
		for(int a = 1; a <= C && !t; a++){
			if(!dp[A][B][C - a]){
				C -= a;
				Take_Stone(3, a, &P, &N);
				if(P == 1){
					A -= N;
				} else if(P == 2){
					B -= N;
				} else {
					C -= N;
				}
			}
		}
	}
}
