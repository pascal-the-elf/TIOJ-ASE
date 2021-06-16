#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e6, INF = 1e16;

int vals[maxN], sts[maxN], N, maxLen = -1, maxAt = -1;
stack<pii> stk;
pii lft[maxN], rgt[maxN];

vector<int> adj[maxN];

void getSts(int p, int u){
    //cout << "Running dfs(" << p << ", " << u << ")" << endl;
    sts[u] = 1;
    int res = 0;
    for(int x : adj[u]){
        if(x == p) continue;
        getSts(u, x);
        sts[u] += sts[x];
        res += ((N - sts[x] + 1) * sts[x]);
    }
    res += (N - sts[u]) * (sts[u] + 1);
    if(maxLen < res || (maxLen == res && u < maxAt)){
        maxLen = res;
        maxAt = u;
    }
    //cout << "sts[" << u << "] = " << sts[u] << endl;
}

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> vals[i];
    for(int i = 0; i < N; i++){
        while(stk.size() && stk.top().F < vals[i]) stk.pop();
        if(stk.size()) lft[i] = stk.top();
        else lft[i] = {INF, i};
        stk.emplace(vals[i], i);
    }
    stack<pii>().swap(stk);
    for(int i = N - 1; i >= 0; i--){
        while(stk.size() && stk.top().F < vals[i]) stk.pop();
        if(stk.size()) rgt[i] = stk.top();
        else rgt[i] = {INF, i};
        stk.emplace(vals[i], i);
    }

    for(int i = 0; i < N; i++){
        if(rgt[i].F == INF && lft[i].F == INF) continue;
        else if(rgt[i].F > lft[i].F){
            adj[i].push_back(lft[i].S);
            adj[lft[i].S].push_back(i);
        } else {
            adj[i].push_back(rgt[i].S);
            adj[rgt[i].S].push_back(i);
        }
    }
    getSts(-1, 0);
    cout << maxLen << " " << maxAt + 1 << "\n";
}
