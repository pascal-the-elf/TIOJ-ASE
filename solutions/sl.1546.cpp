#include <iostream>
using namespace std;

const int maxN = 1e4 + 10;

int N, M, P, Q, x[maxN], y[maxN], curRow[maxN], nxtRow[maxN], h[maxN], prv, r;


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

signed main(){
    Read(N);
    Read(M);
    Read(P);
    Read(Q);
    prv = 1;
    r = (M - 1) * (M - 1) % N;
    for(int i = 0; i < M; i++){
        Read(x[i]);
        curRow[i] = x[i];
        h[i] = 1;
        if(i){
            prv = (x[i] >= x[i - 1] ? prv + 1 : 1);
        }
        if(prv >= P) r = (r + min(Q, prv) - P + 1);
        if(h[i] >= P) r = (r + min(Q, h[i]) - P + 1);
    }
    r %= N;
    for(int i = 1; i < M; i++) Read(y[i]);

    for(int i = 1; i < M; i++){
        prv = 1;
        for(int j = 0; j < M; j++){
            if(j)
                nxtRow[j] = x[0] ^ x[j] ^ y[i];
            else nxtRow[j] = y[i];

            if(nxtRow[j] >= curRow[j]) h[j]++;

            else h[j] = 1;
            if(j && nxtRow[j] >= nxtRow[j - 1]) prv++;
            else prv = 1;

            if(prv >= P)
                r = (r + min(Q, prv) - P + 1);
            if(h[j] >= P)
                r = (r + min(Q, h[j]) - P + 1);
            curRow[j] = nxtRow[j];
        }
        r %= N; //must mod last else TLE
    }
    cout << r << '\n';
}
