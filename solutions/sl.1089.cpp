#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1226;

int N, K, a, b, match[maxN], matches;
bool visited[maxN];
vector<int> adj[maxN];

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

int main(){
    cin >> N >> K;
    fill(match, match + 2 * N, -1);
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b + N);
        adj[b + N].push_back(a);
    }
    for(int i = 0; i < N; i++){
        fill(visited, visited + 2 * N, false);
        matches += dfs(i);
    }
    cout << matches << endl;
}
