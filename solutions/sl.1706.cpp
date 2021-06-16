#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10, INF = 1e17;

int N, M, s, t, D, u, v, m1, k1, m2, k2;

struct Dijkstra{
    vector<pii> adj[maxN];
    int minDist[maxN];
    bool visited[maxN];
    pii p;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    Dijkstra(){}
    inline void addEdge(int u, int v, int w){
        adj[u].emplace_back(v, w);
    }
    void run(int s){
        fill(minDist, minDist + N + 1,  INF);
        fill(visited, visited + N + 1,false);
        pq = priority_queue<pii, vector<pii>, greater<pii> >();
        minDist[s] = 0;
        pq.push({0, s});
        while(pq.size()){
            p = pq.top();
            pq.pop();
            if(visited[p.S]) continue;
            visited[p.S] = true;
            for(pii e : adj[p.S]){
                if(visited[e.F]) continue;
                if(minDist[e.F] > p.F + e.S){
                    minDist[e.F] = p.F + e.S;
                    pq.push({minDist[e.F], e.F});
                }
            }
        }
    }
} d[2][2];

signed main(){
    ericxiao;
    cin >> N >> M >> s >> t >> D;
    for(int kk = 0; kk < M; kk++){
        cin >> u >> v >> k1 >> m1 >> k2 >> m2;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                d[i][j].addEdge(u, v, (i == 0 ? k1 : k1 + m1 * (D - 1)));
                d[i][j].addEdge(v, u, (i == 0 ? k2 : k2 + m2 * (D - 1)));
            }
        }
    }
    d[0][0].run(s);
    d[0][1].run(t);
    d[1][0].run(s);
    d[1][1].run(t);
    cout << min(d[0][0].minDist[t] + d[0][1].minDist[s], d[1][0].minDist[t] + d[1][1].minDist[s]) << '\n';

}
