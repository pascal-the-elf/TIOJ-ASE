#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

const int maxN = 2020, INF = 2e9;

int x[maxN], y[maxN], c[maxN], darr[maxN];
bool inTree[maxN][maxN];
long long int mv, mstval;
int T, N, K;

inline int dist(int i, int j){
    if(!i) return c[j];
    if(!j) return c[i];
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

struct Edge{
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w): u(u), v(v), w(w){}
} dp[maxN];

vector<Edge> edges;

void Flat(int x){
    if(x == darr[x]) return;
    Flat(darr[x]);
    darr[x] = darr[darr[x]];
}

bool Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(darr[a] == darr[b]) return false;
    darr[darr[a]] = darr[b];
    return true;
}

inline void init(){
    vector<Edge>().swap(edges);
    for(int i = 0; i <= N; i++){
        darr[i] = i;
        for(int j = 0; j <= N; j++){
            inTree[i][j] = false;
        }
    }
    mv = 0;
}

inline void kruskal(){
    sort(edges.begin(), edges.end(), [=](Edge a, Edge b){
        return a.w < b.w;
    });
    for(Edge e : edges){
        Flat(e.u);
        Flat(e.v);
        if(darr[e.u] != darr[e.v]){
            Merge(e.u, e.v);
            inTree[e.u][e.v] = inTree[e.v][e.u] = true;
            mv += e.w;
        }
    }
}

void dfs(int p, int u){
    for(int i = 1; i <= N; i++){
        if(inTree[u][i]){
            if(i == p) continue;
            if(dp[i].w != -1){
                if(dp[i].w < dist(u, i)){
                    dp[i] = Edge(u, i, dist(u, i));
                } else {
                    dp[i] = dp[u];
                }
            }
            dfs(u, i);
        }
    }
}

bool stp(){
    for(int i = 1; i <= N; i++) dp[i].w = 0;
    dp[0].w = -1;
    for(int i = 1; i <= N; i++) if(inTree[i][0]) dp[i].w = -1;

    dfs(-1, 0);
    int minV = INF, minAt;
    for(int i = 1; i <= N; i++){
        if(!inTree[i][0]){
            if(minV > dist(0, i) - dp[i].w){
                minV = dist(0, i) - dp[i].w;
                minAt = i;
            }
        }
    }
    if(minV >= 0) return false;
    inTree[0][minAt] = inTree[minAt][0] = true;
    inTree[dp[minAt].u][dp[minAt].v] = inTree[dp[minAt].v][dp[minAt].u] = false;
    mv += minV;
    return true;
}

inline void solve(){
    init();
    for(int i = 1; i <= N; i++){
        cin >> x[i] >> y[i] >> c[i];
        for(int j = 1; j < i; j++){
            edges.emplace_back(i, j, dist(i, j));
        }
    }
    kruskal();
    //cout << "mv = " << mv << endl;
    int minVal = INF, minAt;

    for(int i = 1; i <= N; i++){
        if(minVal > dist(0, i)){
            minAt = i;
            minVal = dist(0, i);
        }
    }

    inTree[0][minAt] = inTree[minAt][0] = true;
    mv += minVal;
    //cout << "mv = " << mv << endl;
    bool need = true;
    for(int i = 2; i <= min(N, K) && need; i++){
        need &= stp();
    }
    cout << min(mstval, mv) << endl;
}

signed main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        solve();
    }
}

