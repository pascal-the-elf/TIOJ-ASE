#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e5 + 10, maxLog = 20;

int sparse[maxLog][maxN][2], arr[maxN], N, M, l, r;

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

inline void build(){
    for(int i = 1; (1 << i) <= N; i++){
        for(int j = 1; j + (1 << i) - 1 <= N; j++){
            sparse[i][j][0] = min(sparse[i - 1][j][0], sparse[i - 1][j + (1 << (i - 1))][0]);
            sparse[i][j][1] = max(sparse[i - 1][j][1], sparse[i - 1][j + (1 << (i - 1))][1]);
        }
    }
}

signed main(){
    Read(N);
    Read(M);
    for(int i = 1; i <= N; i++){
        Read(sparse[0][i][0]);
        sparse[0][i][1] = sparse[0][i][0];
    }
    build();
    while(M--){
        Read(l);
        Read(r);
        for(int k = 0;; k++){
            if((1 << (k + 1)) > (r - l + 1)){
                //cout << "K = " << k << endl;
                //cout << "M = " << max(sparse[k][l][1], sparse[k][r - (1 << k) + 1][1]) << ", m = " << min(sparse[k][l][0], sparse[k][r - (1 << k) + 1][0]) << endl;
                cout << max(sparse[k][l][1], sparse[k][r - (1 << k) + 1][1]) - min(sparse[k][l][0], sparse[k][r - (1 << k) + 1][0]) << '\n';
                break;
            }
        }
    }
}
