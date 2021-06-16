#include <iostream>
using namespace std;

const int MOD = 32768, maxN = 1226;

int T, N, vals[maxN], mn, mxAt;

inline int Abs(int x){
    return (x > 0) ? x : -x;
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

inline int Swap(int i, int j){
    int r = 0;
    if(i > j) swap(i, j);
    if(i + 1 == j){
        if(i) r -= Abs(vals[i] - vals[i - 1]);
        if(j < N - 1) r -= Abs(vals[j] - vals[j + 1]);
        if(i) r += Abs(vals[j] - vals[i - 1]);
        if(j < N - 1) r += Abs(vals[i] - vals[j + 1]);
        return r;
    }
    if(i) r -= Abs(vals[i] - vals[i - 1]);
    if(i < N - 1) r -= Abs(vals[i] - vals[i + 1]);

    if(j) r -= Abs(vals[j] - vals[j - 1]);
    if(j < N - 1) r -= Abs(vals[j] - vals[j + 1]);

    if(i) r += Abs(vals[j] - vals[i - 1]);
    if(i < N - 1) r += Abs(vals[j] - vals[i + 1]);

    if(j) r += Abs(vals[i] - vals[j - 1]);
    if(j < N - 1) r += Abs(vals[i] - vals[j + 1]);

    return r;
}


void solve(){
    Read(N);
    for(int i = 0; i < N; i++) Read(vals[i]);
    for(int i = 0; i < N; i++){
        mn = 10226, mxAt = 0;
        for(int j = 0; j < N; j++){
            //cout << "Swap(" << i << ", " << j << ") = " << Swap(i, j) << endl;
            if(mn > Swap(i, j)){
                mn = Swap(i, j);
                mxAt = j;
            }
        }
        cout << mxAt + 1 << " \n"[i == N - 1];
    }
}

int main(){
    Read(T);
    while(T--){
        solve();
    }
}
