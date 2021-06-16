#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
inline char readchar(){
    static char buf[1<<16], *p = buf, *q = buf;
    if(p == q && (q=(p=buf)+fread(buf,1,1<<16,stdin))==buf) return EOF;
    return *p++;
}
template<typename T>
inline void read(T &v){
    static char p;
    while(isspace(p = readchar()));
    v = p-'0';
    while(isdigit(p = readchar()))v = v * 10 + p-'0';
}
const int maxN = 1e5;

int N, Q, u, v, w, t, x, pf0 = 0, cnt = 0, res;

struct Seg{
    vector<int> seg, arr, pre, tag;
    Seg(){}

    inline int getSum(int l, int r){
        return pre[r] - (l ? pre[l - 1] : 0);
    }

    inline void pull(int id){
        seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
    }

    inline void push(int id, int l, int r){
        seg[id] += tag[id] * getSum(l, r - 1);
        //cout << "add " << tag[id] * getSum(l, r) << endl;
        if(l + 1 < r){
            tag[2 * id + 1] += tag[id];
            tag[2 * id + 2] += tag[id];
        }
        tag[id] = 0;
    }

    void build(int id = 0, int l = 0, int r = N){
        tag[id] = 0;
        if(l + 1 == r){
            seg[id] = 0;
            return;
        }
        int m = (l + r) / 2;
        build(2 * id + 1, l, m);
        build(2 * id + 2, m, r);
        pull(id);
    }

    void modify(int id, int ql, int qr, int l = 0, int r = N){
        push(id, l, r);
        if(ql >= r || l >= qr) return;
        if(ql <= l && r <= qr){
            tag[id]++;
            push(id, l, r);
            return;
        }
        int m = (l + r) / 2;
        modify(2 * id + 1, ql, qr, l, m);
        modify(2 * id + 2, ql, qr, m, r);
        pull(id);
    }

    int query(int id, int ql, int qr, int l = 0, int r = N){
        push(id, l, r);
        if(ql >= r || l >= qr) return 0;
        if(ql <= l && r <= qr) return seg[id];
        int m = (l + r) / 2;
        return query(2 * id + 1, ql, qr, l, m) + query(2 * id + 2, ql, qr, m, r);
    }

    int qry(int l, int r){
        if(l > r) swap(l, r);
        return query(0, l, r + 1);
    }

    void change(int l, int r){
        if(l > r) swap(l, r);
        modify(0, l, r + 1);
    }

    Seg(vector<int> PRE): pre(PRE){
        seg.resize(N * 4 + 226);
        tag.resize(N * 4 + 226);
        build();
    }
};

struct zkw {
    vector<int> seg, arr, wei, tag;
    void upd(int p, int d){
        seg[p] += d*wei[p];
        if(p < N) tag[p] += d;
    }
    void pull(int p){
        while(p > 1) seg[p>>1] = seg[p]+seg[p^1]+tag[p>>1]*wei[p>>1], p>>=1;
    }
    void push(int p){
        int h = 1;
        while((1<<h) < N) ++h;
        for(; h >= 0; h--){
            int i = p>>h;
            if(!tag[i>>1]) continue; // j
            upd(i,tag[i>>1]); // j<<1
            upd(i^1,tag[i>>1]); // j<<1|1
            tag[i>>1] = 0;
        }
    }
    int query(int l, int r){
        push(l+N), push(r-1+N);
        int res = 0;
        for(l+=N,r+=N; l<r; l>>=1,r>>=1){
            if(l&1) res += seg[l++];
            if(r&1) res += seg[--r];
        }
        return res;
    }
    void modify(int l, int r){
        int L = l, R = r;
        for(l+=N,r+=N; l<r; l>>=1,r>>=1){
            if(l&1) upd(l++,1);
            if(r&1) upd(--r,1);
        }
        pull(L+N), pull(R-1+N);
    }
    int qry(int l, int r){
        if(l > r) swap(l, r);
        return query(l, r + 1);
    }

    void change(int l, int r){
        if(l > r) swap(l, r);
        modify(l, r + 1);
    }
    zkw(){}
    zkw(vector<int> PRE) {
        wei.resize(N * 2 + 226);
        seg.resize(N * 2 + 226);
        tag.resize(N + 126);
        for(int i = 0; i < N; i++) wei[i+N] = PRE[i] - (i?PRE[i-1]:0);
        for(int i = N-1; i > 0; i--) wei[i] = wei[i<<1] + wei[i<<1|1];
    }
} rmq;

vector<pii> adj[maxN], ances;
vector<int> dep, maxChild, ord, pos, pre, top;


bool hasMan[maxN];

void getChild(int p = 0, int u = 0){
    static int size[maxN];
    size[u] = 1;
    maxChild[u] = -1;
    int ms = -1;
    for(pii e : adj[u]){
        if(e.F == p) continue;
        dep[e.F] = dep[u] + e.S;
        getChild(u, e.F);
        size[u] += size[e.F];
        if(size[e.F] > ms){
            maxChild[u] = e.F;
            ms = size[e.F];
        }
    }
}

void getTree(int p = -1, int u = 0, int head = 0){
    //dfs maxChild -> dfs the rest
    pos[u] = ord.size();
    ord.push_back(u);
    top[u] = head;
    if(maxChild[u] != -1){
        getTree(u, maxChild[u], head);
    }
    for(auto e : adj[u]){
        if(e.F == p || e.F == maxChild[u]) continue;
        getTree(u, e.F, e.F);
    }
}
#define fastscan read
signed main(){
    read(N), read(Q);
    //fastscan(N);
    //fastscan(Q);
    ances.resize(N);
    maxChild.resize(N);
    pos.resize(N);
    pre.resize(N);
    top.resize(N);
    dep.resize(N);
    for(int i = 0; i < N - 1; i++){
        fastscan(u);
        fastscan(v);
        fastscan(w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        ances[v] = {u, w};
    }
    dep[0] = 0;
    getChild();
    getTree();
    //cout << "Tree: " << endl;
    //for(int x : ord) cout << x << " "; cout << endl;
    pre[0] = 0;
    for(int i = 1; i < N; i++){
        pre[i] = pre[i - 1] + ances[ord[i]].S;
        //cout << "pre[" << i << "] = " << pre[i] << endl;
    }
    rmq = zkw(pre);
    //cout << "Finished building seg tree" << endl;
    while(Q--){
        read(t), read(x);
        //cin >> t >> x;
        if(t == 1){ //modify
            //cout << "hasman[" << x << "]: " << hasMan[x] << endl;
            if(hasMan[x]) continue;
            hasMan[x] = true;
            cnt++;
            pf0 += dep[x];
            while(x){
                rmq.change(pos[x], pos[top[x]]);
                //cout << "x = " << x << ", next = " << ances[top[x]].F << endl;
                x = ances[top[x]].F;
            }
        } else if(t == 2){ //query
            res = cnt * dep[x] + pf0;
            //cout << "cnt = " << cnt << ", pf0 = " << pf0 << endl;
            //cout << "dep[" << x << "] = " << dep[x] << endl;
            //cout << "res = " << res << endl;
            while(x){
                //cout << "Querying " << x << " to " << top[x] << endl;
                //cout << "res = " << rmq.qry(pos[x], pos[top[x]]) << endl;
                //cout << "pos[" << x << "] = " << pos[x] << endl;
                res -= 2 * rmq.qry(pos[x], pos[top[x]]);
                x = ances[top[x]].F;
            }
            printf("%lld\n", res);
        }
    }
}
