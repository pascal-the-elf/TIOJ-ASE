#include <iostream>
#include <queue>
using namespace std;

const int maxN = 1e2 + 5;

queue<int> que;
int T, N, M, val[maxN][maxN], mdist[maxN][maxN];

inline int abs(int x){
	return x < 0 ? -x : x;
}
inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

inline void solve(){
	Read(N); Read(M);
	que = queue<int>();
	for(int i = 0; i <= N + 1; i++) for(int j = 0; j <= M + 1; j++){ 
		mdist[i][j] = maxN * maxN;
		val[i][j] = maxN * maxN;
	}
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++){
		Read(val[i][j]);
	}
	mdist[1][1] = 0;
	que.push(3 + M);
	while(que.size() && mdist[N][M] == maxN * maxN){
		int t = que.front(), y = t / (M + 2), x = t % (M + 2);
		que.pop();
		if(abs(val[y - 1][x] - val[y][x]) <= 5 && mdist[y - 1][x] == maxN * maxN){
			mdist[y - 1][x] = mdist[y][x] + 1;
			que.push((M + 2) * (y - 1) + x);
		}
		if(abs(val[y + 1][x] - val[y][x]) <= 5 && mdist[y + 1][x] == maxN * maxN){
			mdist[y + 1][x] = mdist[y][x] + 1;
			que.push((M + 2) * (y + 1) + x);
		}
		if(abs(val[y][x - 1] - val[y][x]) <= 5 && mdist[y][x - 1] == maxN * maxN){
			mdist[y][x - 1] = mdist[y][x] + 1;
			que.push((M + 2) * y + x - 1);
		}
		if(abs(val[y][x + 1] - val[y][x]) <= 5 && mdist[y][x + 1] == maxN * maxN){
			mdist[y][x + 1] = mdist[y][x] + 1;
			que.push((M + 2) * y + x + 1);
		}
	}
	printf("%d\n", mdist[N][M]);
}

int main(){
	Read(T);
	while(T--){
		solve();
	}
}
