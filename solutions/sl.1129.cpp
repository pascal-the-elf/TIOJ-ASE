#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 4005;

int dsu[maxN], x[maxN], y[maxN], sz[maxN], N, C, A, ans[maxN], cnt;
inline void init();
inline int dist(int i, int j);
void Flat(int x);
void Merge(int a, int b);

void solve(){
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(dist(i, j) <= C * C) Merge(i, j);
        }
    }
    for(int i = 0; i < N; i++){
        Flat(i);
        if(i == dsu[i]){
            ans[cnt++] = sz[i];
        }
    }
    sort(ans, ans + cnt);
    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++) cout << ans[i] << " \n"[i == cnt - 1];
}

int main(){
    while(cin >> A >> N >> C){
        init();
        solve();
    }
}

inline void init(){
    x[0] = (269 * A + 11) % 103;
    y[0] = (271 * A + 13) % 97;
    cnt = 0;
    for(int i = 1; i < N; i++){
        x[i] = (269 * x[i - 1] + 11) % 103;
        y[i] = (271 * y[i - 1] + 13) % 97;
    }
    iota(dsu, dsu + N, 0);
    fill(sz, sz + N, 1);
}

int dist(int i, int j){
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

void Flat(int x){
    if(x == dsu[x]) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dsu[a] == dsu[b]) return;
    sz[dsu[b]] += sz[dsu[a]];
    dsu[dsu[a]] = dsu[b];
}
