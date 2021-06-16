#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e4 + 10;

vector<int> adj[maxN];

int N, v;

pii getFar(int p, int u){
    pii res = {0, u}, _r;
    for(int v : adj[u]){
        if(v == p) continue;
        _r = getFar(u, v);
        _r.F++;
        res = max(res, _r);
    }
    return res;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        while(cin >> v){
            if(v == -1) break;
            adj[v].push_back(i);
            adj[i].push_back(v);
        }
    }
    int t = getFar(0, 0).S;
    cout << getFar(t, t).F << endl;

}
