#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <math.h>
#define pid pair<int,double>
#define pdi pair<double,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e4 + 10;
const double INF = 10001;

bool visited[maxN];
int N, M, s, t, u, v;
double minDist[maxN], w; //the weight is a double...

struct Dijkstra{
    vector<pid> adj[maxN];
    inline void addEdge(int u, int v, double w){
        adj[u].emplace_back(v, w);
    }
    double run(int s, int t){
        fill(visited, visited + N + 1, false);
        fill(minDist, minDist + N + 1, INF);
        priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
        pq.push({0.0, s});
        minDist[s] = 0.0;
        while(pq.size()){
            pdi tp = pq.top();
            pq.pop();
            if(visited[tp.S]) continue;
            visited[tp.S] = true;
            for(auto [u, w] : adj[tp.S]){
                if(visited[u]) continue;
                if(minDist[u] > tp.F + w){
                    minDist[u] = tp.F + w;
                    pq.push({minDist[u], u});
                }
            }
        }
        return minDist[t];
    }
} dijks;

signed main(){
    scanf("%d%d%d%d", &N, &M, &s, &t);
    dijks = Dijkstra();
    for(int i = 0; i < M; i++){
        scanf("%d%d%lf", &u, &v, &w);
        dijks.addEdge(u, v, log10(w + 1));
    }
    double res = dijks.run(s, t);
    int exp = floor(res);
    printf("%.2lfe+%03d\n", pow(10, res - exp), exp);
}
