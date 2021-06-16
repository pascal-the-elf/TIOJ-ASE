#include <iostream>
#include <queue>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

int visited[maxN], minDist[maxN], wei[maxN], N, M, D, u, v, ans, tp;
vector<int> adj[maxN];
queue<int> que;

int main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> wei[i];
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> D;

    fill(visited, visited + N, false);
    fill(minDist, minDist + N, maxN);
    minDist[0] = 0;
    visited[0] = true;
    ans += wei[0];
    que.push(0);

    while(que.size()){
        tp = que.front();
        que.pop();
        if(minDist[tp] >= D) continue;
        for(int v : adj[tp]){
            if(visited[v]) continue;
            else {
                ans += wei[v];
                visited[v] = true;
                minDist[v] = minDist[tp] + 1;
                que.push(v);
            }
        }
    }
    cout << ans << endl;
}
