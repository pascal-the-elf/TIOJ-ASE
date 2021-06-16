#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int short
using namespace std;

const int maxN = 226 * 2;

vector<int> adj[maxN];

int N, M, x, visited[maxN], match[maxN], k, matches, c;

bool dfs(int u){
    for(int v : adj[u]){
        if(visited[v]) continue;
        visited[v] = true;
        if(match[v] == -1 || dfs(match[v])){
            match[v] = u;
            return true;
        }
    }
    return false;
}

inline void solve(){
    matches = 0;
    fill(match, match + N + M, -1);
    fill(adj, adj + N + M, vector<int>());
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> x;
            if(!x){
                adj[i].push_back(j + N);
                adj[j + N].push_back(i);
            }
        }
    }
    for(int i = 0; i < N; i++){
        fill(visited, visited + N + M, false);
        matches += dfs(i);
    }
    cout << "Case " << ++c << ": " << 2 * (N + M - matches) << '\n';
}

signed main(){
    ericxiao;
    while(cin >> N >> M){
        solve();
    }
}
