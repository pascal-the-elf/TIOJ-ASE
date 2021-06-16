#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1000, maxW = 1e5;

short N, M, arr[maxN];

bool can[maxW];

inline short readchar() {
    const int N = 1048576;
    static char buf[N];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}

void fastscan(short &x)
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

int main(){
    ericxiao;
    fastscan(M);
    fastscan(N);
    while(M--){
        int sum = 0;
        for(int i = 0; i < N; i++){
            fastscan(arr[i]);
            sum += arr[i];
        }
        if(sum % 2){
            cout << "No" << endl;
            continue;
        }
        fill(can, can + maxW, 0);
        can[0] = 1;
        for(int i = 0; i < N; i++){
            for(int w = sum; w >= arr[i]; w--) can[w] |= can[w - arr[i]];
        }

        if(can[sum / 2]) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
}
