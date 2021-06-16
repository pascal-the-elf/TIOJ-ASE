#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10, maxLog = 17;

int dep[maxN], anc[maxN][maxLog], u, v, k, N, Q;
vector<int> adj[maxN];

void dfs(int p, int u){
    dep[u] = dep[p] + 1;
    anc[u][0] = p;
    for(int i = 1; i < maxLog; i++){
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(u, v);
    }
}

inline int kthAnc(int u, int k){
    for(int l = maxLog - 1; l >= 0; l--){
        if((k >> l) & 1) u = anc[u][l];
    }
    return u;
}

inline int LCA(int u, int v){
    if(dep[u] >= dep[v]) swap(u, v); //v is deeper
    v = kthAnc(v, dep[v] - dep[u]);
    if(u == v) return u;
    for(int l = maxLog - 1; l >= 0; l--){
        if(anc[u][l] != anc[v][l]){
            u = anc[u][l];
            v = anc[v][l];
        }
    }
    return anc[u][0];
}

inline void solve(int u, int v, int k){
    int lca = LCA(u, v), ans;
    //cout << "LCA = " << lca << endl;
    if(k > dep[u] + dep[v] - 2 * dep[lca]){
        cout << "-1\n";
        return;
    }
    ans = (dep[u] - dep[lca] + 1 > k ? kthAnc(u, k) : kthAnc(v, dep[u] + dep[v] - 2 * dep[lca] - k));
    cout << ans << '\n';
}

int main(){
    ericxiao;
    cin >> N >> Q;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    while(Q--){
        cin >> u >> v >> k;
        solve(u, v, k);
    }
}
