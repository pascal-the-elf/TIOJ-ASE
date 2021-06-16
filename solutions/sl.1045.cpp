#include <iostream>
#include <vector>
#include <algorithm>
#define m (l + r)/2
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e4;

int seg[maxN * 4], tag[maxN * 4];

struct Op{
    int x, y1, y2, val;
    Op(){}
    Op(int X, int Y1, int Y2, int VAL): x(X), y1(Y1), y2(Y2), val(VAL){}
    bool operator<(Op o) const {
        return x < o.x;
    }
};

void push(int id, int l, int r){
    int t = tag[id];
    if(t < 0){
        while(t < 0){
            seg[id] /= 2;
            t++;
        }
    } else {
        while(t > 0){
            seg[id] *= 2;
            t--;
        }
    }
    if(l + 1 < r){
        tag[2 * id + 1] += tag[id];
        tag[2 * id + 2] += tag[id];
    }
    tag[id] = 0;
}

void pull(int id){
    seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

void build(int id = 0, int l = 0, int r = maxN){
    tag[id] = 0;
    if(l + 1 == r){
        seg[id] = 1;
        return;
    }
    build(2 * id + 1, l, m);
    build(2 * id + 2, m, r);
    pull(id);
}

void modify(int id, int ql, int qr, int l, int r, int v){
    push(id, l, r);
    if(ql >= r || qr <= l) return;
    if(ql <= l && r <= qr){
        tag[id] += v;
        push(id, l, r);
        return;
    }
    modify(2 * id + 1, ql, qr, l, m, v);
    modify(2 * id + 2, ql, qr, m, r, v);
    pull(id);
}

int query(int id, int ql, int qr, int l, int r){
    push(id, l, r);
    if(ql >= r || qr <= l) return 0;
    if(ql <= l && r <= qr){
        return seg[id];
    }
    return query(2 * id + 1, ql, qr, l, m) + query(2 * id + 2, ql, qr, m, r);
}

int n, u, d, l, r;

vector<Op> ops;

signed main(){
    ericxiao;
    while(cin >> n){
        if(!n) return 0;
        ops.clear();
        for(int i = 0; i < n; i++){
            cin >> l >> u >> r >> d;
            ops.emplace_back(l, u, d, 1);
            ops.emplace_back(r, u, d, -1);
        }
        sort(ops.begin(), ops.end());
        build();
        int pt = 0, ans = 0;
        for(int i = 0; i < maxN; i++){
            while(pt < 2 * n && ops[pt].x == i){
                //cout << "Modify: " << ops[pt].x << ", " << ops[pt].y1 << ", " << ops[pt].y2 << ", val = " << ops[pt].val << endl;
                modify(0, ops[pt].y1, ops[pt].y2, 0, maxN, ops[pt].val);
                pt++;
            }
            push(0, 0, maxN);
            ans += seg[0];
        }
        cout << ans << '\n';
    }

}
