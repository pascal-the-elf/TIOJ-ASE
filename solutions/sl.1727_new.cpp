#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int maxN = 2020, INF = 1e9;

struct Edge{
    int u, v, w;
    Edge(){}
    Edge(int U, int V, int W): u(U), v(V), w(W){}
};

int N, K, T, x[maxN], y[maxN], c[maxN], ans, dsu[maxN], mstVal;
unordered_set<int> treeAdj[maxN];
vector<Edge> edges;
Edge dp[maxN];

inline void Flat(int x){
    if(x == dsu[x]) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

inline bool Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dsu[a] == dsu[b]) return false;
    dsu[dsu[a]] = dsu[b];
    return true;
}

inline void addEdge(int a, int b){
    treeAdj[a].insert(b);
    treeAdj[b].insert(a);
}

inline void subEdge(int a, int b){
    treeAdj[a].erase(b);
    treeAdj[b].erase(a);
}

inline void init();
inline int dist(int i, int j){
    if(!i) return c[j];
    if(!j) return c[i];
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

inline void kruskal(){
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });
    for(Edge e : edges){
        if(Merge(e.u, e.v)){
            addEdge(e.u, e.v);
            ans += e.w;
        }
    }
}

void dfs(int p, int u){
    for(int v : treeAdj[u]){
        if(v == p) continue;
        if(dp[v].w != -1){
            if(dist(u, v) > dp[u].w){
                dp[v] = Edge(u, v, dist(u, v));
            } else {
                dp[v] = dp[u];
            }
        }
        dfs(u, v);
    }
}

inline bool stp(){
    dp[0].w = -1;
    for(int i = 1; i <= N; i++){
        if(treeAdj[0].count(i)){
            dp[i].w = -1;
        } else {
            dp[i].w = 0;
        }
    }
    dfs(-1, 0);
    int minDelta = INF, minAt;
    for(int v = 1; v <= N; v++){
        if(treeAdj[0].count(v)) continue;
        if(minDelta > (dist(v, 0) - dp[v].w)){
            minDelta = (dist(v, 0) - dp[v].w);
            minAt = v;
        }
    }
    if(minDelta >= 0) return false;
    subEdge(dp[minAt].u, dp[minAt].v);
    addEdge(0, minAt);
    ans += minDelta;
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
    mstVal = ans;
    int minV = dist(0, 1), minAt = 1;
    for(int i = 1; i <= N; i++){
        if(minV > dist(0, i)){
            minV = dist(0, i);
            minAt = i;
        }
    }
    addEdge(minAt, 0);
    ans += minV;
    bool can = true;
    for(int i = 2; i <= min(K, N) && can; i++) can &= stp();
    cout << min(mstVal, ans) << endl;
}

signed main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        solve();
    }
}

inline void init(){
    ans = 0;
    vector<Edge>().swap(edges);
    for(int i = 0; i <= N; i++){
        dsu[i] = i;
        treeAdj[i] = unordered_set<int>();
    }
}

