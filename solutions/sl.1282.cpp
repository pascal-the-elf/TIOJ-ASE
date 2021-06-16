#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 226250;

int diff[maxN], arr[maxN], N, Q, c, l, r, k;

int gcd(int a, int b){
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    return !b ? a : gcd(b, a % b);
}

struct BIT{
    int b[maxN];

    int query(int p){
        int r = 0;
        for(;p > 0; p -= (p & -p)) r += b[p];
        return r;
    }

    void modify(int p, int x){
        for(; p < maxN; p += p & -p) b[p] += x;
    }
} bit;

struct Seg{
    int seg[maxN * 2];
    inline void pull(int id){
        seg[id] = gcd(seg[2 * id + 1], seg[2 * id + 2]);
    }

    void build(int id = 0, int l = 1, int r = N + 1){
        if(l + 1 == r){
            seg[id] = diff[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * id + 1, l, m);
        build(2 * id + 2, m, r);
        pull(id);
    }

    void modify(int id, int l, int r, int pos, int val){
        if(l + 1 == r){
            seg[id] += val;
            return;
        }
        int m = (l + r) / 2;
        if(pos < m) modify(2 * id + 1, l, m, pos, val);
        else modify(2 * id + 2, m, r, pos, val);
        pull(id);
    }

    int query(int id, int ql, int qr, int l, int r){
        if(l >= qr || ql >= r) return 0;
        if(ql <= l && r <= qr) return seg[id];
        int m = (l + r) / 2;
        return gcd(query(2 * id + 1, ql, qr, l, m), query(2 * id + 2, ql, qr, m, r));
    }
} rmq;



signed main(){
    ericxiao;
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        diff[i] = (i == 1) ? arr[i] : arr[i] - arr[i - 1];
        bit.modify(i, diff[i]);
    }
    rmq.build();
    while(Q--){
        cin >> c >> l >> r;
        if(c == 1){
            cin >> k;
            bit.modify(l, k);
            bit.modify(r + 1, -k);
            rmq.modify(0, 1, N + 1, l, k);
            if(r + 1 <= N)
                rmq.modify(0, 1, N + 1, r + 1, -k);
        } else if(c == 2){
            //cout << "l = " << bit.query(l) << endl;
            //cout << "Others: " << rmq.query(0, l + 1, r + 1, 1, N + 1) << endl;
            if(l == r) cout << bit.query(l) << '\n';
            else cout << gcd(bit.query(l), rmq.query(0, l + 1, r + 1, 1, N + 1)) << '\n';
        }
    }
}
