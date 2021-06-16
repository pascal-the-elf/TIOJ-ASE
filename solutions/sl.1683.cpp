#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e4 + 10;

vector<int> adj[maxN], rev[maxN], sccadj[maxN], ord;
int nscc, wei[maxN], dp[maxN], indeg[maxN], ans, visited[maxN], scc[maxN];
int T, N, M, u, v, t;
queue<int> que;

inline void init(){
    que = queue<int>();
    vector<int>().swap(ord);
    for(int i = 0; i <= N; i++){
        vector<int>().swap(adj[i]);
        vector<int>().swap(rev[i]);
        vector<int>().swap(sccadj[i]);
        wei[i] = 0;
        indeg[i] = 0;
        visited[i] = 0;
        dp[i] = 0;
    }
}

void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]) dfs(v);
    }
    ord.push_back(u);
}

void revdfs(int u){
    visited[u] = true;
    scc[u] = nscc;
    wei[nscc]++;
    for(int v : rev[u]){
        if(!visited[v]) revdfs(v);
    }
}

int main(){
    ericxiao;
    cin >> T;
    while(T--){
        cin >> N >> M;
        ans = nscc = 0;
        init();
        for(int i = 0; i < M; i++){
            cin >> u >> v;
            if(u == v) continue;
            adj[u].push_back(v);
            rev[v].push_back(u);
        }
        for(int i = 1; i <= N; i++) if(!visited[i]) dfs(i);
        reverse(ord.begin(), ord.end());
        fill(visited, visited + N + 1, false);
        for(int u : ord){
            if(!visited[u]){
                revdfs(u);
                nscc++;
            }
        }
        fill(indeg, indeg + nscc, 0);
        for(int u = 1; u <= N; u++){
            for(int v : adj[u]){
                if(scc[u] != scc[v]){
                    sccadj[scc[u]].push_back(scc[v]);
                    indeg[scc[v]]++;
                }
            }
        }
        for(int i = 0; i < nscc; i++){
            if(!indeg[i]){
                que.push(i);
                dp[i] = wei[i];
            }
        }
        while(que.size()){
            t = que.front();
            ans = max(ans, dp[t]);
            que.pop();
            for(int v : sccadj[t]){
                dp[v] = max(dp[v], dp[t] + wei[v]);
                indeg[v]--;
                if(!indeg[v]) que.push(v);
            }
        }
        cout << ans << '\n';
    }

}
