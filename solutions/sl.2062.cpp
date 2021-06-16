#include <iostream>
#include <vector>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 226;

int dsu[maxN * 2], dsu2[maxN], S[maxN], T[maxN], sh, th, N, M, a, b;


inline char readchar()
{
    static const size_t bufsize = 1 << 20;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

template <class T> void input(T& a)
{
    static char p;
    while ((p = readchar()) < '0') ;
    a = p ^ '0';
    while ((p = readchar()) >= '0') a *= 10, a += p ^ '0';
}

void Flat(int x){
    if(x == dsu[x]) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

void Flat2(int x){
    if(x == dsu2[x]) return;
    Flat2(dsu2[x]);
    dsu2[x] = dsu2[dsu2[x]];
}

void Merge(int a, int b){
    Flat(a);
    Flat(b);
    dsu[dsu[a]] = dsu[b];
}

void Merge2(int a, int b){
    Flat2(a);
    Flat2(b);
    dsu2[dsu2[a]] = dsu2[b];
}
int main(){
    input(N);
    input(M);
    iota(dsu, dsu + maxN * 2, 0);
    iota(dsu2, dsu2 + maxN, 0);
    while(M--){
        input(a);
        input(b);
        Merge(a, b + N);
        Merge(b, a + N);
        Merge2(a, b);
    }
    for(int i = 1; i <= N; i++){
        Flat(i);
        Flat(i + N);
        Flat2(i);
    }
    for(int i = 1; i <= N; i++){
        if(dsu[i] == dsu[i + N]){
            printf("-1\n");
            return 0;
        }
        if(dsu[dsu2[i]] == dsu[i]) S[sh++] = i;
        else T[th++] = i;
    }
    printf("%d %d\n", sh, th);
    for(int i = 0; i < sh; i++) printf("%d\n", S[i]);
    for(int i = 0; i < th; i++) printf("%d\n", T[i]);
}
