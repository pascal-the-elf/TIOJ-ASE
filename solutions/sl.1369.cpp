#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e4 + 10;

int N, k, x, cnt = 0;
vector<int> adj[maxN], ans;

void dfs(int p, int u){
    ans[u] = ++cnt;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(u, v);
    }
}

int main(){
    ericxiao;
    cin >> N;
    ans.resize(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> k;
        while(k--){
            cin >> x;
            adj[i].push_back(x);
        }
    }
    dfs(1, 1);
    for(int i = 1; i <= N; i++) cout << ans[i] << '\n';
}
