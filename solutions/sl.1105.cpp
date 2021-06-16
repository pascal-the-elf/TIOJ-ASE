#include <iostream>
#define int long long int
using namespace std;

const int maxN = 3226;

int N;
int x[maxN], y[maxN];

inline int readchar() {
    const int N = 1048576;
    static char buf[N];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}

void fastscan(int &x)
    {
        bool neg=false;
        register int c;
        x =0;
        c=readchar();
        if(c=='-')
        {
            neg = true;
            c=readchar();
        }
        for(;(c>47 && c<58);c=readchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }

signed main(){
    fastscan(N);
    while(true){
        if(!N) return 0;
        for(int i = 0; i < N; i++){
            fastscan(x[i]);
            fastscan(y[i]);
        }
        int maxLen = -1, a = -1, b = -1;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(maxLen < (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])){
                    maxLen = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                    a = i;
                    b = j;
                }
            }
        }
        cout << a << " " << b << '\n';
        fastscan(N);
    }
}
