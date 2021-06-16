#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e4 + 10;

int dp[maxN][2], N, u, v;
vector<int> adj[maxN];

void dfs(int p, int u){
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(u, v);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }

}

int main(){
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    cout << min(dp[1][0], dp[1][1]) << endl;
}
