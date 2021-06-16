#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 226;

int N, M, sx, sy, ex, ey;
char mp[maxN][maxN];
inline int getId(int y, int x, int o){
    return y * N + x + o * N * M;
}

bool isValid(int y, int x){
    return (y >= 0 && x >= 0 && y < N && x < M && mp[y][x] == 'O');
}

struct Dijkstra{
    vector<pii> adj[maxN * maxN * 2];
    int minDist[maxN * maxN * 2];
    bool visited[maxN * maxN * 2];
    void add(int u, int v, int w){
        adj[u].emplace_back(v, w);
    }
    void run(int s){
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        fill(minDist, minDist + maxN * maxN * 2, maxN * 100);
        fill(visited, visited + maxN * maxN * 2, false);
        pq.push({0, s});
        minDist[s] = 0;
        while(pq.size()){
            pii p = pq.top();
            pq.pop();
            if(visited[p.S]) continue;
            visited[p.S] = true;
            for(pii e : adj[p.S]){
                if(visited[e.F]) continue;
                if(minDist[e.F] > minDist[p.S] + e.S){
                    minDist[e.F] = minDist[p.S] + e.S;
                    pq.push({minDist[e.F], e.F});
                }
            }
        }
    }
} dijk;

int main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> mp[i][j];
        }
    }
    cin >> sx >> sy >> ex >> ey;
    sx--;
    sy--;
    ex--;
    ey--;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(mp[i][j] == 'X') continue;
            if(isValid(i, j - 1)){
                dijk.add(getId(i, j, 0), getId(i, j - 1, 0), 0);
                dijk.add(getId(i, j, 1), getId(i, j - 1, 0), 1);
            }
            if(isValid(i, j + 1)){
                dijk.add(getId(i, j, 0), getId(i, j + 1, 0), 0);
                dijk.add(getId(i, j, 1), getId(i, j + 1, 0), 1);
            }
            if(isValid(i - 1, j)){
                dijk.add(getId(i, j, 0), getId(i - 1, j, 1), 1);
                dijk.add(getId(i, j, 1), getId(i - 1, j, 1), 0);
            }
            if(isValid(i + 1, j)){
                dijk.add(getId(i, j, 0), getId(i + 1, j, 1), 1);
                dijk.add(getId(i, j, 1), getId(i + 1, j, 1), 0);
            }
        }
    }
    dijk.run(getId(sx, sy, 0));
    int ans = min(dijk.minDist[getId(ex, ey, 0)], dijk.minDist[getId(ex, ey, 1)]);
    dijk.run(getId(sx, sy, 1));
    ans = min(ans, min(dijk.minDist[getId(ex, ey, 0)], dijk.minDist[getId(ex, ey, 1)]));
    if(ans == maxN * 100) cout << "No Way!!" << endl;
    else cout << ans << endl;
}
