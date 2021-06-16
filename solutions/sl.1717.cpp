#pragma optimize ("Ofast")
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1005;

vector<int> adj[maxN];
int times[maxN], indeg[maxN], n, k, t;

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

int main(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << "$" << i << "\land" << j << " = " << (i & j) << "$" << endl;
        }
    }
    fastscan(t);
    while(t--){
        fastscan(n);
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        for(short i = 0; i < n; ++i){
            fastscan(times[i]);
            fastscan(k);
            adj[i].resize(k);
            for(short j = 0; j < k; ++j){
                fastscan(adj[i][j]);
                adj[i][j]--;
                indeg[adj[i][j]]++;
            }
        }
        for(short i = 0; i < n; ++i){
            if(!indeg[i]) pq.push({times[i], i});
        }
        int mt = 0;
        pii p;
        for(short i = 0; i < n; ++i){
            p = pq.top();
            pq.pop();
            mt = max(mt, p.F);
            for(int x : adj[p.S]){
                indeg[x]--;
                if(!indeg[x]){
                    pq.push({p.F + times[x], x});
                }
            }
        }
        printf("%d\n", mt);
    }
}
