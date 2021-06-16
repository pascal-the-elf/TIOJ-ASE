#include <iostream>
#include <vector>
#include <algorithm>
#define ALL(x) x.begin(),x.end()
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
const int maxN = 1e5 + 226;

int N;
bool vis[maxN];
vector<int> vec, ord, dsu, lm, rm, sm, mv;

void Flat(int x){
    if(x == dsu[x]) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
    sm[x] = sm[dsu[x]];
    lm[x] = lm[dsu[x]];
    rm[x] = rm[dsu[x]];
    mv[x] = mv[dsu[x]];
}

void Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dsu[a] == dsu[b]) return;
    sm[dsu[a]] += sm[dsu[b]];
    lm[dsu[a]] = min(lm[dsu[a]], lm[dsu[b]]);
    rm[dsu[a]] = max(rm[dsu[a]], rm[dsu[b]]);
    mv[dsu[a]] = min(mv[dsu[a]], mv[dsu[b]]);
    dsu[dsu[b]] = dsu[a];
}

inline void solve(){
    vec.resize(N);
    ord.resize(N);
    dsu.resize(N);
    sm.resize(N);
    lm.resize(N);
    rm.resize(N);
    mv.resize(N);
    fill(vis, vis + N, false);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
        lm[i] = rm[i] = dsu[i] = ord[i] = i;
        sm[i] = mv[i] = vec[i];
    }
    sort(ALL(ord), [=](int a, int b){
        return vec[a] > vec[b];
    });
    int ans = -1, L = maxN, R = maxN;
    for(int x : ord){
        vis[x] = true;
        if(x && vis[x - 1]){
            Merge(x, x - 1);
        }
        if(x < N - 1 && vis[x + 1]){
            Merge(x, x + 1);
        }
        Flat(x);
        //cout << "Val for " << x << ": " << mv[x] * sm[x]  << endl;
        if(mv[x] * sm[x] > ans){
            ans = mv[x] * sm[x];
            L = lm[x];
            R = rm[x];
        } else if(mv[x] * sm[x]  == ans){
            if(lm[x] < L){
                L = lm[x];
                R = rm[x];
            } else if(lm[x] == L && rm[x] < R){
                L = lm[x];
                R = rm[x];
            }
        }
    }
    cout << ans << endl << L + 1 << " " << R + 1 << endl;
}

signed main(){
    ericxiao;
    while(cin >> N){
        solve();
    }
}
