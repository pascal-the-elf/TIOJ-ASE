#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
#define gc getchar_unlocked
using namespace std;

const int maxN = 2e3, INF = 2e9;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

struct Dijkstra{
    int N;
    vector<pii> adj[maxN];
    vector<bool> visited;
    vector<int> minDist;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    Dijkstra(){}

    Dijkstra(int N): N(N){
        visited.resize(N);
        minDist.resize(N);
        fill(visited.begin(), visited.end(), false);
        fill(minDist.begin(), minDist.end(), INF);
        for(int i = 0; i < N; i++){
            vector<pii>().swap(adj[i]);
        }
        pq = priority_queue<pii, vector<pii>, greater<pii>>();
    }

    void addEdge(int u, int v, int w){
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    void run(int s){
        //cout << "Running with start " << s << endl;
        minDist[s] = 0;
        pq.push({0, s});
        pii p;
        //cout << pq.size() << endl;
        for(int i = 0; i < N && pq.size(); i++){
            p = pq.top();
            pq.pop();
            while(pq.size() && visited[p.S]){
                p = pq.top();
                pq.pop();
            }
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

} sssp;

int n, m, st, ed, u, v, w;

int main(){
    while(cin >> n){
        scanint(m);
        scanint(st);
        scanint(ed);
        sssp = Dijkstra(n + 1);
        for(int i = 0; i < m; i++){
            scanint(u);
            scanint(v);
            scanint(w);
            sssp.addEdge(u, v, w);
        }
        sssp.run(st);
        if(sssp.minDist[ed] == INF){
            cout << "He is very hot\n";
        } else {
            cout << sssp.minDist[ed] << '\n';
        }
    }
}
