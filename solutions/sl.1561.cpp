#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;


const int maxN = 226, INF = 1e9;

struct Dijkstra{
    int N;
    vector<pii> adj[maxN];
    bool visited[maxN];
    vector<int> minDist;
    vector<int> secDist;
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    void addEdge(int u, int v, int w){
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    Dijkstra(){}
    Dijkstra(int N): N(N){
        minDist.resize(N);
        secDist.resize(N);
        for(int i = 0; i < N; i++){
            adj[i].clear();
        }
    }

    void run(int s){
        pq = priority_queue<pii, vector<pii>, greater<pii> >();
        fill(minDist.begin(), minDist.end(), INF);
        fill(secDist.begin(), secDist.end(), INF);
        pq.push({0, s});
        minDist[s] = 0;
        pii tp;
        while(pq.size()){
            tp = pq.top();
            pq.pop();
            for(pii e : adj[tp.S]){
                if(minDist[e.F] > tp.F + e.S){
                    secDist[e.F] = minDist[e.F];
                    minDist[e.F] = tp.F + e.S;
                    pq.push({minDist[e.F], e.F});
                } else if(secDist[e.F] > tp.F + e.S && tp.F + e.S != minDist[e.F]){
                    secDist[e.F] = tp.F + e.S;
                    pq.push({secDist[e.F], e.F});
                }
            }
        }
    }
} dijk;

int N, M, u, v, w, s, t, md, ans;

int main(){
    while(cin >> N >> M){
        dijk = Dijkstra(N);
        for(int i = 0; i < M; i++){
            cin >> u >> v >> w;
            dijk.addEdge(u, v, w);
        }
        cin >> s >> t;
        dijk.run(s);
        cout << (dijk.secDist[t] >= INF ? -1 : dijk.secDist[t]) << endl;
    }
}
