#include <iostream>
#include <vector>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e4 + 10;
vector<int> adj[maxN];
bool win[maxN], visited[maxN];
//win[i] represents the winning of the person about to move, that is the person not standing on the
//first circle at the start.
int n, m, u, v;

string nm;

void dfs(int x){
    visited[x] = true;
    win[x] = false;
    for(int u : adj[x]){
        if(!visited[u]) dfs(u);
        if(!win[u]) win[x] = true;
    }
}

int main(){
    ericxiao;
    while(cin >> n >> m){
        if(!n && !m) return 0;
        for(int i = 1; i <= n; i++){
            vector<int>().swap(adj[i]);
        }
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            adj[u].push_back(v);
        }
        fill(visited, visited + n + 1, false);
        visited[n] = true;
        win[n] = 0;
        dfs(1);
        cin >> nm;
        if(!win[1]) cout << nm << endl;
        else {
            if(nm == "Mimi") cout << "Moumou" << endl;
            else cout << "Mimi" << endl;
        }
    }
}
