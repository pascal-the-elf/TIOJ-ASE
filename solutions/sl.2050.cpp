#include <iostream>
#include <vector>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2005;

int N, M, u, v, a;

struct DSU{
    int dsu[maxN];
    DSU(){}
    DSU(int N){
        iota(dsu, dsu + N + 3, 0);
    }
    void Find(int x){
        if(x == dsu[x]) return;
        Find(dsu[x]);
        dsu[x] = dsu[dsu[x]];
    }
    inline bool Merge(int a, int b){
        Find(a);
        Find(b);
        if(dsu[a] == dsu[b]) return false;
        dsu[dsu[a]] = dsu[b];
        return true;
    }
} dsus[3];

struct Tarjan{
    vector<int> adj[maxN];
    bool oriCut[maxN], isCut[maxN], visited[maxN];
    int low[maxN], dep[maxN], ignore;
    Tarjan(){}
    inline void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int p, int u){
        //cout << "Running dfs(" << p << ", " << u << ")" << endl;
        dep[u] = dep[p] + 1;
        low[u] = dep[u];
        int c = 0;
        visited[u] = true;
        for(int v : adj[u]){
            if(v == ignore || v == p) continue;
            if(visited[v]){
                low[u] = min(low[u], dep[v]);
            } else {
                c++;
                dfs(u, v);
                low[u] = min(low[u], low[v]);
                if(low[v] >= dep[u]) isCut[u] = true;
            }
        }
        if(p == u) isCut[u] = (c > 1);
    }
    void init(){
        fill(isCut, isCut + N + 1, false);
        fill(visited, visited + N + 1, false);
        ignore = -1;
        dfs(1, 1);
        for(int i = 1; i <= N; i++){
            oriCut[i] = isCut[i];
        }
    }
    int get(int ig){
        ignore = ig;
        fill(isCut, isCut + N + 1, false);
        fill(visited, visited + N + 1, false);
        int root = (ig == 1 ? 2 : 1);
        dep[root] = 0;
        dfs(root, root);
        int rt = 0;
        for(int i = 1; i <= N; i++){
            rt += isCut[i];
        }
        return rt;
    }
} tarjan;

int main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 0; i < 3; i++) dsus[i] = DSU(N);
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        for(int j = 0; j < 3; j++){
            if(dsus[j].Merge(u, v)){
                //cout << "Adding " << u << ", " << v << endl;
                tarjan.addEdge(u, v);
                break;
            }
        }
    }
    tarjan.init();
    //cout << "A = " << a << endl;
    for(int i = 1; i <= N; i++){
        if(!tarjan.oriCut[i]){
            //cout << "Pulling " << i << endl;
            a += tarjan.get(i);
            //cout << "add = " << tarjan.get(i) << endl;
        } else {
            a += (N - 1);
            int cnt = 0;
            for(int v : tarjan.adj[i]) if(tarjan.adj[v].size() == 1) cnt++;
            if(tarjan.adj[i].size() == 2) a -= cnt;
        }
    }
    cout << a/2 << endl;
}
