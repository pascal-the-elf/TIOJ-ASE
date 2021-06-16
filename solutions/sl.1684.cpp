#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <vector>
#include <set>
#include <numeric>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1005, maxM = maxN * maxN + 10;

bool am[maxN][maxN], visited[maxN], pushed[maxM];
set<int> st, st2;
vector<pii> adj[maxN], edges, bcc[maxN];
int N, M, u, v, nbcc, dsu[2 * maxN], dep[maxN], low[maxN], ans;
stack<int> stk;


inline void init(){
    ans = 0;
    nbcc = 0;
    stk = stack<int>();
    st2 = set<int>();
    vector<pii>().swap(edges);
    iota(dsu, dsu + 2 * N + 1, 0);
    for(int i = 0; i <= N * (N - 1) / 2; i++){
        pushed[i] = false;
    }
    for(int i = 0; i <= N; i++){
        visited[i] = false;
        dep[i] = 0;
        vector<pii>().swap(adj[i]);
        vector<pii>().swap(bcc[i]);
        for(int j = 1; j < i; j++){
            am[i][j] = 0;
        }
    }
}


void Find(int x);
inline bool Merge(int a, int b);
inline void undo();

void getBCC(int p, int u){
    dep[u] = dep[p] + 1;
    low[u] = dep[u];
    int chi = 0;
    visited[u] = true;
    for(auto [v, id] : adj[u]){
        if(v == p) continue;
        if(!pushed[id]){
            pushed[id] = true;
            stk.push(id);
        }
        if(visited[v]){
            low[u] = min(low[u], dep[v]);
        } else {
            getBCC(u, v);
            chi++;
            low[u] = min(low[v], low[u]);
            if(low[v] >= dep[u]){
                while(stk.size()){
                    int tp = stk.top();
                    bcc[nbcc].push_back(edges[tp]);
                    stk.pop();
                    if(tp == id) break; //Seems to be important, why?
                }
                nbcc++;
            }

        }
    }
}


int main(){
    while(cin >> N >> M){
        if(!N && !M) return 0;
        init();
        for(int i = 0; i < M; i++){
            cin >> u >> v;
            if(u < v) swap(u, v);
            am[u][v] = 1;
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j < i; j++){
                if(!am[i][j]){
                    adj[i].emplace_back(j, edges.size());
                    adj[j].emplace_back(i, edges.size());
                    edges.emplace_back(i, j);
                }
            }
        }
        for(int i = 1; i <= N; i++) if(!visited[i]) getBCC(i, i);
        for(int i = 0; i < nbcc; i++){
            bool can = true;
            st = set<int>();
            iota(dsu, dsu + 2 * N + 3, 0);
            //cout << i << " th bcc: " << endl;
            for(auto [u, v] : bcc[i]){
                //cout << u << ", " << v << endl;
                Merge(u, v + N);
                Merge(v, u + N);
                st.insert(u);
                st.insert(v);
            }
            for(auto x : st){
                Find(x);
                Find(x + N);
                can &= (dsu[x] != dsu[x + N]);
            }
            //cout << "can: " << can << endl;
            if(!can){
                for(int x : st) st2.insert(x);
            }

            //ans = max(ans, (!can) * ((int)st.size() - 1) / 2 * 2 + 1);
        }
        cout << N - st2.size() << endl;
    }
}


void Find(int x){
    if(dsu[x] == x) return;
    Find(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

inline bool Merge(int a, int b){
    Find(a);
    Find(b);
    if(dsu[a] == dsu[b]) return false;
    dsu[dsu[b]] = dsu[a];
    return true;
}
