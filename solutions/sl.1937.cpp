#pragma gcc optimize ("O3", "unroll-loops", "-funroll-loops") 
#include <iostream>
#define ericxiao std::ios_base::sync_with_stdio(0);std::cin.tie(0);

const int maxN = 2048;
int N, A[maxN][maxN], B[maxN][maxN], C[maxN][maxN];

int main(){
	ericxiao;
	while(std::cin >> N){
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) std::cin >> A[i][j];
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) std::cin >> B[j][i], C[i][j] = 0;
				
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				for(int k = 0; k < N; k++){
					C[i][j] += A[i][k] * B[j][k];	
				}
			}
		}
		
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) std::cout << C[i][j] << " \n"[j == N - 1];
	}
}
