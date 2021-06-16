#pragma GCC optimize ("Ofast")
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <deque>
#include <numeric>
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define piiii pair<pii, pii>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 6e5;

int T, N, M, Q, a, b, cc, ans[maxN + 10], dsu[maxN + 10], rk[maxN + 10];
char com;

vector<pii>seg[maxN * 4];


inline void init();
int  Find(int a);
inline piiii Merge(int a, int b);

void ins(int id, int l, int r, int ql, int qr, pii p){
    if(qr <= l || ql >= r) return;
    if(ql <= l && r <= qr){
        seg[id].push_back(p);
        return;
    }
    ins(2 * id + 1, l, (l + r)/2, ql, qr, p);
    ins(2 * id + 2, (l + r)/2, r, ql, qr, p);
}


void dfs(int id, int l, int r){
    vector<piiii> v;
    for(auto p : seg[id]){
        //do and record
        v.push_back(Merge(p.F, p.S));
    }
    vector<pii>().swap(seg[id]);
    //recurse
    if(l + 1 < r){
        dfs(2 * id + 1, l, (l + r) / 2);
        dfs(2 * id + 2, (l + r) / 2, r);
    } else {
        ans[l] = cc;
    }
    //undo
    reverse(v.begin(), v.end());
    for(piiii p : v){
        dsu[p.F.F] = p.F.F;
        cc += p.F.S;
        rk[p.S.F] = p.S.S;
    }
    vector<piiii>().swap(v);
}

int main(){
    ericxiao;
    cin >> T;
    while(T--){
        cin >> N >> M >> Q;
        init();
        int ct = 0;
        map<pii,deque<int> > mp;
        for(int i = 0; i < M; ++i){
            cin >> a >> b;
            if(a > b) swap(a, b);
            mp[{a, b}].push_back(0);
            ct++;
        }
        /*
        com:
        N new edge
        D del edge
        */
        for(int i = 0; i < Q; ++i){
            cin >> com >> a >> b;
            if(a > b) swap(a, b);
            if(com == 'N'){
                mp[{a, b}].push_back(ct);
            } else if(com == 'D') {
                ins(0, 0, (M + Q), mp[{a, b}].front(), ct, {a, b});
                mp[{a,b}].pop_front();
            }
            ct++;
        }

        for(auto p : mp){
            if(p.S.empty()) continue;
            while(p.S.size()){
                ins(0, 0, (M + Q), p.S.front(), ct, p.F);
                p.S.pop_front();
            }
        }
        //cout << "Ct = " << ct << endl;
        dfs(0, 0, (M + Q));
        for(int i = 0; i < Q; ++i){
            cout << ans[i + M] << '\n';
        }
    }
}

inline void init(){
    iota(dsu, dsu + N, 0);
    fill(rk, rk + N, 1);
    cc = N;
}

int Find(int a){
    if(dsu[a] == a) return a;
    return Find(dsu[a]);
}

inline piiii Merge(int a, int b){
    //cout << "Gonna merge " << a << " and " << b << endl;
    //cout << "Find(a) = " << Find(a) << " and Find(b) = " << Find(b) << endl;
    if(Find(a) == Find(b)) return {{Find(a), 0}, {Find(b), rk[Find(b)]}};
    if(rk[Find(a)] > rk[Find(b)]) swap(a, b);
    piiii res = {{Find(a), 1}, {Find(b), rk[Find(b)]}};
    if(rk[Find(a)] == rk[Find(b)]) rk[Find(b)]++;
    //cout << "Merging " << a << " and " << b << endl;
    cc--;
    dsu[ Find(a) ] = Find(b);
    return res;
}
