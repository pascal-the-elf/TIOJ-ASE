#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#include "lib1164.h"
using namespace std;

const int maxN = 1e6 + 10;

int mnT, mxT = 1, N, M, shortlen, longlen;
vector<pii> adj[maxN];
pii cur;

pii getFar(int p, int u){
    //cout << "p = " << p << ", u = " << u << endl;
    pii r = {0, u}, _r;
    for(auto [v, w] : adj[u]){
        if(v == p) continue;
        _r = getFar(u, v);
        _r.F += w;
        if(_r.F > r.F) r = _r;
    }
    return r;
}

void initAdj(int k){
    MAP mp = getct(k);
    for(int i = 0; i < mp.m; i++) adj[i].clear();
    for(int i = 0; i < mp.k; i++){
        adj[mp.x[i]].emplace_back(mp.y[i], mp.len[i]);
        adj[mp.y[i]].emplace_back(mp.x[i], mp.len[i]);
    }
}




int main(){
    N = init();
    if(N % 2){
        mxT = mnT = 0;
        for(int i = 1; i < N; i += 2){
            if(query(i, i + 1)){
                mxT = query(i, mxT) ? i : mxT;
                mnT = query(i + 1, mnT) ? mnT : i + 1;
            } else {
                mxT = query(i + 1, mxT) ? i + 1 : mxT;
                mnT = query(i, mnT) ? mnT : i;
            }
        }
    } else {
        if(query(0, 1)){
            mxT = 0;
            mnT = 1;
        } else {
            mxT = 1;
            mnT = 0;
        }
        for(int i = 2; i < N; i += 2){
            if(query(i, i + 1)){
                mxT = query(i, mxT) ? i : mxT;
                mnT = query(i + 1, mnT) ? mnT : i + 1;
            } else {
                mxT = query(i + 1, mxT) ? i + 1 : mxT;
                mnT = query(i, mnT) ? mnT : i;
            }
        }
    }
    //cout << "mnT = " << mnT << endl;
    //cout << "mxT = " << mxT << endl;
    initAdj(mnT);
    cur = getFar(0, 0);
    //cout << "Far from " << 0 << " is " << cur.S << " with len " << cur.F << endl;
    cur = getFar(cur.S, cur.S);
    shortlen = cur.F;
    initAdj(mxT);
    cur = getFar(0, 0);
    cur = getFar(cur.S, cur.S);
    longlen = cur.F;
    answer(longlen, shortlen);
}
