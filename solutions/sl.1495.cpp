#include <iostream>
#include <numeric>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

/*
First, merge all the 1's together to form many connected components. The problem then reduces to
the original, but without 1's. (if there are two vertices connected by a chain of ones, then they
must also be connected by a one!). Shrink the connected components into one point.

 Then merge all the 0's.
Consider every edge with weight zero. Call the heads e.u and e.v. If e.u and e.v belong to
two different components, then we can safely merge them (this means every pair of points, one belonging to
        e.u's 1 component and the other belonging to e.v's 1 component have a zero in between); else, it fails. After finishing merging the
0's, we've reduced the problem to one without any graphs. Turns out, the answer is 2^{n - 1} for
n nodes without any edges!
*/

const int maxN = 2e6 + 10, MOD = 1e9 + 7;

int N, M, u, v, w;

inline int add(int a, int b){
    return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int sub(int a, int b){
    return (a - b < 0 ? a - b + MOD : a - b);
}

struct DSU{
    vector<int> dsu;
    DSU(){}
    void Flat(int x){
        if(x == dsu[x]) return;
        Flat(dsu[x]);
        dsu[x] = dsu[dsu[x]];
    }
    bool Merge(int a, int b){
        Flat(a);
        Flat(b);
        if(dsu[a] == dsu[b]) return false;
        dsu[dsu[a]] = dsu[b];
        return true;
    }
    DSU(int n){
        dsu.resize(n);
        iota(dsu.begin(), dsu.end(), 0);
    }
} dsu1, dsu2;


long long int exp2(int p){
    if(!p) return 1LL;
    long long int res = exp2(p / 2);
    res = res * res % MOD;
    if(p % 2) res = res * 2 % MOD;
    return res;
}

vector<pii> ones, zeroes;

signed main(){
    ericxiao;
    cin >> N >> M;
    dsu1 = DSU(N);
    dsu2 = DSU(N);
    while(M--){
        cin >> u >> v >> w;
        (w ? ones : zeroes).emplace_back(u, v);
    }
    for(pii e : ones){
        dsu1.Merge(e.F, e.S);
    }
    int ccs = 0;
    for(int i; i < N; i++){
        dsu1.Flat(i);
    }
    for(int i = 0; i < N; i++){
        dsu1.Flat(i);
    }
    for(pii e : zeroes){
        dsu1.Flat(e.F);
        dsu1.Flat(e.S);
        if(dsu1.dsu[e.F] == dsu1.dsu[e.S]){
            cout << 0 << endl;
            return 0;
        }
        dsu2.Merge(dsu1.dsu[e.F], dsu1.dsu[e.S]);
    }
    bool has[N];
    fill(has, has + N, 0);
    for(int i = 0; i < N; i++) dsu2.Flat(dsu2.dsu[i]);
    for(int i = 0; i < N; i++){
        if(dsu2.dsu[dsu1.dsu[i]] == dsu1.dsu[i] && !has[dsu1.dsu[i]]){
            ccs++;
            has[dsu1.dsu[i]] = true;
        }
    }
    cout << exp2(ccs - 1) << endl;
}
