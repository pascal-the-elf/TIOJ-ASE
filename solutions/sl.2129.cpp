#include <iostream>
#include <stack>
#include <utility>
#define F first
#define S second
#define int long long int
#define pii pair<long long ,long long >

#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e4 + 10, INF = 1e15;

int seg[maxN * 4], tag[maxN * 4], vals[maxN], N, K, dp[maxN];

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

void build(int id, int l, int r){
    tag[id] = 0;
    if(l + 1 == r){
        seg[id] = dp[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m, r);
    pull(id);
}

void modify(int id, int ql, int qr, int l, int r, int v){
    push(id, l, r);
    if(qr <= l || ql >= r) return;
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

stack<pair<pii, int> > maxstk, minstk;

signed main(){
    ericxiao;
    cin >> N >> K;
    for(int i = 0; i < N; ++i) cin >> vals[i];
    int mmax = -INF, mmin = INF;
    for(int i = 0; i < N; ++i){
        mmax = max(mmax, vals[i]);
        mmin = min(mmin, vals[i]);
        dp[i] = mmax - mmin;
        //cout << "dp[1][" << i << "] = " << dp[1][i] << endl;
    }
    build(0, 0, N);
    int cv;
    pii p;
    for(int k = 2; k <= K; ++k){
        maxstk = stack<pair<pii, int> >();
        minstk = stack<pair<pii, int> >();
        for(int i = 0; i < N; ++i){
            cv = vals[i];
            p = {i, i};
            while(maxstk.size() && maxstk.top().S <= cv){
                modify(0, max(0LL, maxstk.top().F.F - 1), maxstk.top().F.S, 0, N, cv - maxstk.top().S);
                maxstk.pop();
            }
            if(maxstk.size()) p.F = maxstk.top().F.S + 1;
            else p.F = 0;
            maxstk.push({p, vals[i]});
            p = {i, i};
            while(minstk.size() && minstk.top().S >= cv){
                modify(0, max(0LL, minstk.top().F.F - 1), minstk.top().F.S, 0, N, minstk.top().S - cv);
                minstk.pop();
            }
            if(minstk.size()) p.F = minstk.top().F.S + 1;
            else p.F = 0;
            minstk.push({p, vals[i]});
            if(i >= k - 1) dp[i] = query(0, 0, i, 0, N);
            else dp[i] = INF;
            //cout << "dp[" << k << "][" << i << "] = " << dp[k][i] << endl;
        }
        build(0, 0, N);
    }
    cout << dp[N - 1] << endl;
}
