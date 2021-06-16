#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector<int> adj[maxN], d, dist, visited, all, ans;

int N, u, v, sz[maxN];

int getSz(int p, int u){ //gets the size of subtree
    sz[u] = 1;
    for(int v : adj[u]){
        if(v == p || visited[v]) continue;;
        //getSz(u, v); well fuck
        sz[u] += getSz(u, v);
    }
    return sz[u];
}

int getCentroid(int p, int u, int n){ //get the centroid
    for(int v : adj[u]){
        if(v == p || visited[v]) continue;
        if(sz[v] > n / 2) return getCentroid(u, v, n);
    }
    return u;
}

void getSubtree(int p, int u, vector<int> &vec){ //gets distance
    vec.push_back(u);
    all.push_back(u);
    dist[u] = dist[p] + 1;
    for(int v : adj[u]){
        if(v == p || visited[v]) continue;
        getSubtree(u, v, vec);
    }
}

void decompose(int u, int dep = 1){
    assert(dep < 20);
    //cout << "Decomposing at root = " << u << endl;
    int n = getSz(u, u);
    int centroid = getCentroid(u, u, n);
    //cout << "Centroid = " << centroid << endl;
    visited[centroid] = true;
    vector< vector<int> > subtrees;
    vector<int> _tmp;
    all.clear();
    all.push_back(centroid);
    dist[centroid] = 0;
    for(int i = 0; i < adj[centroid].size(); i++){
        if(!visited[adj[centroid][i]]){
            subtrees.push_back(vector<int>());
            getSubtree(centroid, adj[centroid][i], subtrees.back());
        }

    }

    for(int &v : all) v = dist[v];
    sort(all.begin(), all.end());

    ans[centroid] += upper_bound(all.begin(), all.end(), d[centroid]) - all.begin();

    for(vector<int> &st : subtrees){
        vector<int>().swap(_tmp);
        for(int v : st) _tmp.push_back(dist[v]);
        sort(_tmp.begin(), _tmp.end());
        for(int v : st){
            ans[v] += upper_bound(all.begin(), all.end(), d[v] - dist[v]) - all.begin();
            ans[v] -= upper_bound(_tmp.begin(), _tmp.end(), d[v] - dist[v]) - _tmp.begin();
        }
    }

    for(int v : adj[centroid]) if(!visited[v]) decompose(v, dep + 1);
}

int main(){
    ericxiao;
    cin >> N;
    d.resize(N + 1);
    ans.resize(N + 1);
    dist.resize(N + 1);
    visited.resize(N + 1);
    for(int i = 1; i <= N; i++) cin >> d[i];
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //go get them dudes
    decompose(1);
    for(int i = 1; i <= N; i++) cout << ans[i] << endl;
}
