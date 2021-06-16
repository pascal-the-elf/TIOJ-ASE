#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


const int maxN = 1e3 + 226;
vector<int> adj[maxN];

int N, M, a, b, indeg[maxN], now;


inline void solve(){
    for(int i = 0; i < N; i++){
        vector<int>().swap(adj[i]);
        indeg[i] = 0;
    }
    while(M--){
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        indeg[b]++;
    }
    bool f = true;
    while(N--){
        cin >> now;
        if(!f) continue;
        now--;
        if(indeg[now]) f = false;
        for(int x : adj[now]){
            indeg[x]--;
        }
    }
    cout << (f ? "YES\n" : "NO\n");
}

int main(){
    ericxiao;
    while(cin >> N >> M){
        solve();
    }
}
