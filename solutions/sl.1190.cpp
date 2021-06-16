#include <cstdio>
using namespace std;

const int maxLog = 32, maxN = 510;
int pos[maxN * maxN][2], nxtpos[maxN * maxN][2], N, M, K;

inline void constructTable(){
	int cnt = 0, i = 0, j = 0;
	for(int jizz = 0; jizz < N * N; jizz++){
		pos[i * N + j][0] = jizz / N;
		pos[i * N + j][1] = jizz % N;
		if(i == N - 1){ //N - 1, j
			i = j + 1;
			j = N - 1;
		} else if(!j){
			j = i + 1;
			i = 0;
		} else {
			j--;
			i++;
		}
	}
}

inline void nxt(){
	int x;
	for(int i = 0; i < N * N; i++){
		x = N * pos[i][0] + pos[i][1];
		nxtpos[i][0] = pos[x][0];
		nxtpos[i][1] = pos[x][1];
	}
	for(int i = 0; i < N * N; i++){
		pos[i][0] = nxtpos[i][0];
		pos[i][1] = nxtpos[i][1];
	}
}

int main(){
	scanf("%d%d%d", &N, &M, &K);
	constructTable();
	M--;
	int i = M / N, j = M % N;
	for(int b = 0; b < maxLog; b++){
		if((K >> b) & 1){
			int x = N * i + j;
			i = pos[x][0];	
			j = pos[x][1];
		}
		nxt();
	}
	//for(int i = 0; i < N * N; i++){
	//	cout << i << ": " << pos[0][i][0] << ", " << pos[0][i][1] << endl;
	//}
	printf("%d\n", N * i + j + 1);
}
