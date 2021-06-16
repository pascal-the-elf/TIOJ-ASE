#include <iostream>
#include <vector>
#include <utility>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5010;
vector<int> dep, adj[maxN];
set<int> st;
vector<bool> visited;

struct Edge{
    int u, v, id, col;
    Edge(){}
    Edge(int U, int V, int ID): u(U), v(V), id(ID){}
};

vector<Edge> ans;


int n, m, a, b, k = 1;

void dfs(int c){
    //cout << "Running dfs(" << c << ")" << endl;
    visited[c] = true;
    for(int u : adj[c]){
        if(visited[u]) continue;
        dep[u] = dep[c] + 1;
        dfs(u);
    }
}

bool dfs2(int u){
    visited[u] = true;
    st.insert(u);
    for(int v : adj[u]){
        if(visited[v] && st.count(v)) return true;
        else if(visited[v]) continue;
        if(dfs2(v)) return true;
    }
    st.erase(u);
    return false;
}


int main(){
    ericxiao;
    cin >> n >> m;
    dep.resize(n + 1);
    visited.resize(n + 10);
    fill(visited.begin(), visited.end(), false);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        ans.push_back(Edge(a, b, i));
        adj[a].push_back(b);
    }
    bool t = false;
    for(int i = 1; i <= n; i++){
        fill(visited.begin(), visited.end(), false);
        st = set<int>();
        t |= dfs2(i);
    }
    if(!t){
        cout << 1 << endl;
        for(int i = 0; i < m; i++){
            cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        fill(visited.begin(), visited.end(), false);
        dep[i] = 0;
        dfs(i);
    }
    bool has1 = false, has2 = false;
    for(Edge &e : ans){
        if(dep[e.u] <= dep[e.v]){
            e.col = 1;
            has1 = true;
        } else {
            e.col = 2;
            k = 2;
            has2 = true;
        }
    };
    if(has1 && has2) k = 2;
    else k = 1;

    cout << k << endl;
    for(Edge &e : ans){
        if(has2 && !has1)
        e.col--;
        cout << e.col << " ";
    }
}
