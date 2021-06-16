#include <iostream>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10;

int t, n, m, mons[maxN], hero[maxn], seg[maxN << 2];
pii premax[maxN];

void build(int id = 0, int l = 0, int r = n){
    if(l + 1 == r){
        seg[id] = mons[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m, r);
    seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
}

int que(int id, int ql, int qr, int l = 0, int r = n){
    if(ql >= r || qr <= l) return -1;
    if(ql <= l && r <= qr) return seg[id];
    int m = (l + r) / 2;
    return max(query(2 * id + 1, ql, qr, l, m), query(2 * id + 2, ql, qr, m, r));
}

bool can(int l, int r){ //from [l, r)
    int mv = que(0, l, r);
    pii p = {mv, -1};
    int pos = lower_bound(hero, hero + m, p) - hero;
    return premax[pos] >= (r - l);
}

int main(){
    ericxiao;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> mons[i];
        for(int i = 0; i < m; i++) cin >> hero[i].F >> hero[i].S;
        sort(hero, hero + m);
        premax[m - 1] = hero[i].S;
        for(int i = m - 2; i >= 0; i--) premax[i] = max(premax[i + 1], hero[i].S);
        int pos = 0;
        while()
    }
}
