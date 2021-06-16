#include <iostream>
using namespace std;

const int maxN = 505, INF = 1e9;

int minDist[maxN][maxN], N, M, a, b, ans;

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

int main(){
    Read(N);
    Read(M);
    while(true){
        if(!N && !M) return 0;
        ans = INF;
        for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) minDist[i][j] = INF;
        for(int i = 0; i < M; i++){
            Read(a);
            Read(b);
            minDist[a][b] = 1;
        }
        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    if(minDist[i][j] > minDist[i][k] + minDist[k][j])
                        minDist[i][j] = minDist[i][k] + minDist[k][j];
                }
            }
        }
        for(int i = 1; i <= N; i++){
            if(minDist[i][i] < ans) ans = minDist[i][i];
        }
        cout << (ans == INF ? 0 : ans) << '\n';
        Read(N);
        Read(M);
    }

}
