#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 22625, maxO = 1e5 + 10;

int seg[maxN << 2], tag[maxN << 2], N, l, r, u, d;

struct Op{
    int x, u, d, o;
    Op(int X, int U, int D, int O): x(X), u(U), d(D), o(O){}
    bool operator<(const Op &t) const {
        return x < t.x;
    }
};

vector<Op> ops;

int query(int id, int ql, int qr, int x, int l = 0, int r = maxN){
    if(ql >= r || qr <= l) return (tag[id] ? r - l : seg[id]);
    if(ql <= l && r <= qr){
        tag[id] += x;
        return (tag[id] ? r - l : seg[id]);
    }
    int m = (l + r) / 2;
    seg[id] = query(2 * id + 1, ql, qr, x, l, m) + query(2 * id + 2, ql, qr, x, m, r);
    return (tag[id] ? r - l : seg[id]);
}

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> l >> r >> d >> u;
        ops.emplace_back(l, u, d, 1);
        ops.emplace_back(r, u, d, -1);
    }
    long long int ans = 0, cur, now;
    sort(ops.begin(), ops.end());
    for(Op o : ops){
        ans += cur * (o.x - now);
        now = o.x;
        cur = query(0, o.d, o.u, o.o);
    }
    cout << ans << endl;
}
