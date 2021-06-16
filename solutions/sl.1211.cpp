#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;

struct Edge{
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w): u(u), v(v), w(w){}
    bool operator<(const Edge e) const {
        return w > e.w;
    }
};

vector<int> dsu;
priority_queue<Edge> pq;
int N, M, wei = 0, cc;
int u, v, w;

void Flat(int a){
    if(dsu[a] == a) return;
    Flat(dsu[a]);
    dsu[a] = dsu[dsu[a]];
}

void Union(int a, int b){
    Flat(a);
    Flat(b);
    dsu[dsu[a]] = dsu[b];
}

int main(){
    while(cin >> N >> M){
        wei = 0;
        if(!N && !M) return 0;
        cc = N;
        pq = priority_queue<Edge>();
        dsu.resize(N + 1);
        iota(dsu.begin(), dsu.end(), 0);
        for(int i = 0; i < M; i++){
            cin >> u >> v >> w;
            pq.push(Edge{u, v, w});
        }
        Edge e;
        while(!pq.empty()){
            e = pq.top();
            pq.pop();
            Flat(e.u), Flat(e.v);
            if(dsu[e.u] == dsu[e.v]) continue;
            cc--;
            wei += e.w;
            Union(e.u, e.v);
        }
        if(cc == 1)
            cout << wei << '\n';
        else cout << -1 << '\n';
    }
}
