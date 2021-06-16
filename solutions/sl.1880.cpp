#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const int maxN = 2e5 + 226;
const long long int MOD = 1e6 + 7;

struct DSU{
    int N, dsu[maxN], sz[maxN], cc;
    DSU(){}
    DSU(int N): N(N){
        iota(dsu, dsu + N, 0);
        fill(sz, sz + N, 1);
        cc = N;
    }
    void Flat(int x){
        if(x == dsu[x]) return;
        Flat(dsu[x]);
        sz[x] = sz[dsu[x]];
        dsu[x] = dsu[dsu[x]];
    }
    void Merge(int a, int b){
        Flat(a);
        Flat(b);
        if(dsu[a] == dsu[b]) return;
        sz[dsu[a]] += sz[dsu[b]];
        dsu[dsu[b]] = dsu[a];
        cc--;
    }
} con, bip;

int N, M, u, v;

long long int modexp(long long int b, long long int e){
    if(!b) return 0;
    if(!e) return 1;
    long long int r = modexp(b, e/2);
    r = r * r % MOD;
    if(e % 2) r = r * b % MOD;
    return r;
}

signed main(){
    cin >> N >> M;
    con = DSU(N);
    bip = DSU(2 * N);
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        u--, v--;
        con.Merge(u, v);
        bip.Merge(u + N, v);
        bip.Merge(u, v + N);
    }
    for(int i = 0; i < N; i++){
        bip.Flat(i);
        bip.Flat(i + N);
        if(bip.dsu[i] == bip.dsu[i + N]){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << modexp(2, con.cc - 1) << endl;
}
