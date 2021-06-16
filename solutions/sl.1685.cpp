#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <numeric>
#define pii pair<int,int>
#define F first
#define S second
//#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 226, INF = 1e9;

int C, R, Q, u, v, w, dp[maxN][maxN];
vector<pii> adj[maxN];
vector<int> cost, ord, rk;

struct Dijkstra{
    vector<pii> adj[maxN];
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    bool visited[maxN];
    int minDist[maxN];

    Dijkstra(){
        for(int i = 1; i <= C; i++) vector<pii>().swap(adj[i]);
    }

    inline void addEdge(int u, int v, int w){
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    inline void run(int s){
        fill(minDist, minDist + C + 1, INF);
        fill(visited, visited + C + 1, false);
        minDist[s] = 0;
        pq = priority_queue<pii, vector<pii>, greater<pii> >();
        pq.push({0, s});
        pii p;
        for(int i = 0; i < C; i++){
            do{
                if(!pq.size()) return;
                p = pq.top();
                pq.pop();
            } while(visited[p.S] && pq.size());
            visited[p.S] = true;
            for(pii v : adj[p.S]){
                if(visited[v.F]) continue;
                if(minDist[v.F] > p.F + v.S){
                    minDist[v.F] = p.F + v.S;
                    pq.push({minDist[v.F], v.F});
                }
            }
        }
    }
} md;


signed main(){
    ericxiao;
    int c = 0;
    while(cin >> C >> R >> Q){
        if(!C && !R && !Q) return 0;
        md = Dijkstra();
        rk = ord = cost = vector<int>(C + 1);
        iota(ord.begin(), ord.end(), 0);
        cost[0] = -1;
        for(int i = 1; i <= C; i++){
            cin >> cost[i];
            vector<pii>().swap(adj[i]);
        }
        for(int i = 0; i < R; i++){
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        sort(ord.begin(), ord.end(), [=](int a, int b){
            return cost[a] < cost[b];
        });
        for(int i = 1; i <= C; i++){
            for(int j = 1; j <= C; j++) dp[i][j] = INF;
            dp[i][i] = 0;
            rk[ord[i]] = i;
            for(pii e : adj[i]) dp[i][e.F] = e.S + max(cost[i], cost[e.F]);
        }
        for(int k = 1; k <= C; k++){
            for(pii p : adj[ord[k]]){
                if(rk[p.F] < rk[ord[k]]){
                    md.addEdge(ord[k], p.F, p.S);
                }
            }
            md.run(ord[k]);
            //for(int i = 0; i < )
            for(int i = 1; i <= k; i++){
                for(int j = 1; j <= k; j++){
                    dp[ord[i]][ord[j]] = min(dp[ord[i]][ord[j]], md.minDist[ord[i]] + md.minDist[ord[j]] + cost[ord[k]]);
                    //cout << "dp[" << ord[i] << "][" << ord[j] << "] = " << dp[ord[i]][ord[j]] << endl;
                }
            }
        }
        cout << "Case #" << ++c << endl;
        while(Q--){
            cin >> u >> v;
            cout << (dp[u][v] == INF ? -1 : dp[u][v]) << endl;
        }
        cout << endl;
    }
}
