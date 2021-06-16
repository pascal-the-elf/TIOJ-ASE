#include "lib1481.h"
#include <iostream>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2226, maxM = 20226;

int N, M, u, v, val[maxN], id[maxM], cnt, edges[maxM][2];
bool hasId[maxM], visited[maxN];
vector<pii> adj[maxN];
/*
void Init(){
    cout << "Init" << endl;
}
void Possible(){
    cout << "Possible!" << endl;
}
void Impossible(){
    cout << "Impossible!" << endl;
}
void Number(int x){
    cout << x << endl;
}
void Finish(){
    cout << "Finish" << endl;
}
*/
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void dfs(int x){
    visited[x] = true;
    for(auto [u, i] : adj[x]){
        if(!id[i]) id[i] = ++cnt;
        if(!visited[u]) dfs(u);
    }
}

int main(){
    Init();
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        edges[i][0] = u;
        edges[i][1] = v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    for(int i = 1; i <= N; i++) if(!visited[i]) dfs(i);
    for(int i = 0; i < M; i++){
        val[edges[i][0]] = gcd(val[edges[i][0]], i + 1);
        val[edges[i][1]] = gcd(val[edges[i][1]], i + 1);
    }
    bool can = true;
    for(int i = 1; i <= N; i++){
        if(adj[i].size() > 1) can |= (val[i] == 1);
    }
    if(can){
        Possible();
        for(int i = 0; i < M; i++){
            Number(id[i]);
        }
    } else {
        Impossible();
    }
    Finish();
}
