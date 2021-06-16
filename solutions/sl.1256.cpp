#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e4;

vector<int> adj[maxN], low, dep, cuts;
vector<bool> isCut;
int N, M, u, v, c;

void dfs(int p = 1, int u = 1){
    dep[u] = dep[p] + 1;
    low[u] = dep[u];
    int cc = 0;
    for(int v : adj[u]){
        if(v == p) continue;
        if(low[v]){
            low[u] = min(low[u], dep[v]);
        } else {
            dfs(u, v);
            cc++;
            low[u] = min(low[u], low[v]);
            if(low[v] >= dep[u]) isCut[u] = true;
        }
    }
    if(p == u) isCut[u] = (cc > 1);
}

int main(){
    ericxiao;
    while(cin >> N >> M){
        if(!N && !M) return 0;
        vector<int>().swap(cuts);
        low.resize(N + 1);
        dep.resize(N + 1);
        isCut.resize(N + 1);
        fill(low.begin(), low.end(), 0);
        fill(dep.begin(), dep.end(), 0);
        fill(isCut.begin(), isCut.end(), 0);
        for(int i = 1; i <= N; i++) vector<int>().swap(adj[i]);
        for(int i = 0; i < M; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dep[0] = 0;
        dfs();
        for(int i = 1; i <= N; i++) if(isCut[i]) cuts.push_back(i);
        cout << "Case #" << ++c << ":" << cuts.size();
        if(!cuts.size()) cout << " 0";
        else for(int v : cuts) cout << " " << v;
        cout << endl;
    }

}
