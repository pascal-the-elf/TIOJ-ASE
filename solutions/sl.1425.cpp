#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int MSQRT = 1e4;

int Q, MN, N, d, pfs[(int)(1e7 + 10)], x, w, quots[MSQRT], m, ans;

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
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


inline void initPrime(){
    int i, j;
    fill(pfs, pfs + N + 1, 1);
    for(i = 2; i <= N; i++){
        if(pfs[i] == 1){
            for(j = i; j <= N; j += i){
                pfs[j] <<= 4;
            }
        }
    }
}

inline int solve(int N){
    ans = N + 1;
    m = 0;
    for(int d = 1; d <= N; d++){
        if(d > 1){
            w = pfs[N / (d - 1)];
            if(ans < (d - 1) + w) ans = (d - 1) + w;
        }
        //cout << N << "/" << d << " = " << N /d << endl;
        d = (N / (N / d));
    }
    return ans;
}

signed main(){
    Read(N);
    initPrime();
    Read(Q);
    while(Q--){
        Read(N);
        printf("%d\n", solve(N));
    }
}
