#include <iostream>
#include <stack>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 122526, INF = 1e18;

int W[maxN], H[maxN], dp[maxN], seg[maxN * 4], tag[maxN * 4], N, L;

inline void push(int id, int l, int r){
    seg[id] += tag[id];
    if(l + 1 < r){
        tag[2 * id + 1] += tag[id];
        tag[2 * id + 2] += tag[id];
    }
    tag[id] = 0;
}

inline void pull(int id){
    seg[id] = min(seg[2 * id + 1], seg[2 * id + 2]);
}

void build(int id = 0, int l = 0, int r = maxN){
    seg[id] = tag[id] = 0;
    if(l + 1 < r){
        int m = (l + r) / 2;
        build(2 * id + 1, l, m);
        build(2 * id + 2, m, r);
    }
}

void modify(int id, int ql, int qr, int l, int r, int v){
    push(id, l, r);
    if(ql >= r || qr <= l) return;
    if(ql <= l && r <= qr){
        tag[id] += v;
        push(id, l, r);
        return;
    }
    int m = (l + r) / 2;
    modify(2 * id + 1, ql, qr, l, m, v);
    modify(2 * id + 2, ql, qr, m, r, v);
    pull(id);
}

int query(int id, int ql, int qr, int l, int r){
    push(id, l, r);
    if(ql >= r || qr <= l) return INF;
    if(ql <= l && r <= qr) return seg[id];
    int m = (l + r) / 2;
    return min(query(2 * id + 1, ql, qr, l, m), query(2 * id + 2, ql, qr, m, r));
}

struct Thing{
    int l, r, h;
};

inline void show(int L, int R){
    cout << "Status of segtree: " << endl;
    for(int i = L; i < R; i++){
        cout << query(0, i, i + 1, 0, N) << " \n"[i == R - 1];
    }

}

signed main(){
    ericxiao;
    cin >> N >> L;
    for(int i = 1; i <= N; i++) cin >> H[i] >> W[i];
    W[0] = 0;
    for(int i = 1; i <= N; i++) W[i] += W[i - 1];
    dp[0] = 0;
    build();
    stack<Thing> stk;
    Thing t, tp;
    int ind;
    for(int i = 1; i <= N; i++){
        //cout << "For i = " << i << endl;
        t = {i, i, H[i]};
        modify(0, i - 1, i, 0, N, H[i]);
        while(stk.size() && stk.top().h <= H[i]){ //modify the thing
            tp = stk.top();
            stk.pop();
            //cout << "Popping: " << tp.l << ", " << tp.r << ", h = " << tp.h << endl;
            modify(0, max(0LL, tp.l - 1), tp.r, 0, N, H[i] - tp.h);
            //cout << "Modify: " << max(0LL, tp.l - 1) << " to " << tp.r << " with val " << tp.h << endl;
        }
        t.l = (stk.size() ? stk.top().r + 1 : 0);
        //cout << "The value " << H[i] << " affects all values from " << t.l << " to " << t.r << endl;
        stk.push(t);
        ind = lower_bound(W, W + i + 1, W[i] - L) - W;
        //cout << "ind = " << ind << endl;
        //show(0, i + 1);
        dp[i] = query(0, ind, i, 0, N);
        modify(0, i, i + 1, 0, N, dp[i]);
        //cout << "dp[" << i << "] = " << dp[i] << endl << endl;



    }
    cout << dp[N] << endl;
}
