#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5226;

multiset<int> degs[maxN];

int dsu[maxN], oriDeg[maxN], deg[maxN], N, M, u, v, ans = 0;

vector<pii> edges;

void Flat(int x){
    if(x == dsu[x]) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
    Flat(a);
    Flat(b);
    int da = deg[a], db = deg[b];
    degs[dsu[a]].erase(degs[dsu[a]].find(da));
    degs[dsu[b]].erase(degs[dsu[b]].find(db));
    degs[dsu[a]].insert(da + 1);
    degs[dsu[b]].insert(db + 1);
    deg[a]++;
    deg[b]++;
    if(dsu[a] != dsu[b]){ //do one thing
        if(degs[dsu[a]].size() < degs[dsu[b]].size()) swap(a, b);
        //cout << "Degs[" << dsu[a] << "].size() = " << degs[dsu[a]].size() << endl;
        //cout << "In degs[" << dsu[a] << "]: ";
        //for(int u : degs[dsu[a]]) cout << u << " ";
        //cout << endl;
        //cout << "Degs[" << dsu[b] << "].size() = " << degs[dsu[b]].size() << endl;
        //cout << "In degs[" << dsu[b] << "]: ";
        //for(int u : degs[dsu[b]]) cout << u << " ";
        //cout << endl;
        for(int u : degs[dsu[b]]){
            //cout << "Inserting " << u << " to set of " << a << endl;
            degs[dsu[a]].insert(u);
        }
        //degs[dsu[b]] = multiset<int>();
        dsu[dsu[b]] = dsu[a];
    }
    //cout << "Sz of degs " << dsu[a] << " = " << degs[dsu[a]].size() << endl;
    ans = max(ans, (int)((*degs[dsu[a]].begin()) * (degs[dsu[a]].size())));
}

signed main(){
    ericxiao;
    cin >> N >> M;
    edges.resize(M);
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        oriDeg[u]++;
        oriDeg[v]++;
        edges[i] = {u, v};
    }
    sort(edges.begin(), edges.end(), [](pii a, pii b){
        return min(oriDeg[a.F], oriDeg[a.S]) > min(oriDeg[b.F], oriDeg[b.S]);
    });
    for(int i = 1; i <= N; i++){
        dsu[i] = i;
        degs[i].insert(0);
    }
    for(auto edge : edges){
        //cout << "Merging " << edge.F << ", " << edge.S << endl;
        Merge(edge.F, edge.S);
        //cout << "New ans = " << ans << endl;
    }
    cout << ans << endl;
}
