#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1024;

bool adj[maxN][maxN];
vector<int> path;
int N, M, u, v, ans[maxN];
unordered_map<int, bool> can;

inline int sub(int a, int b){
    return (a - b < 0) ? a - b + N : a - b;
}

inline int add(int a, int b){
    return (a + b <= N ? a + b : a + b - N);
}

inline int hsh(int cur, int l, int r){
    return (cur + 1) * maxN * maxN + (l + 1) * maxN + r + 1;
}

bool dfs(int cur, int l, int r, int cnt){
    if(can.count(hsh(cur, l, r))) return can[hsh(cur, l, r)];
    //cout << "Running dfs(" << cur << ", " << l << ", " << r << ", " << cnt << ")\n";
    ans[cnt] = cur;
    if(cnt == N - 1){
        can[hsh(cur, l, r)] = true;
        return true;
    }
    if(l < r){
        if(adj[cur][l] && dfs(l, sub(l, 1), r, cnt + 1)) can[hsh(cur, l, r)] = true;
        else if(adj[cur][r] && dfs(r, l, add(r, 1), cnt + 1)) can[hsh(cur, l, r)] = true;
        else can[hsh(cur, l, r)] = false;
    } else {
        if(adj[cur][r] && dfs(r, l, add(r, 1), cnt + 1)) can[hsh(cur, l, r)] = true;
        else if(adj[cur][l] && dfs(l, sub(l, 1), r, cnt + 1)) can[hsh(cur, l, r)] = true;
        else can[hsh(cur, l, r)] = false;
    }
    return can[hsh(cur, l, r)];
}


signed main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        u--, v--;
        adj[u][v] = adj[v][u] = true;
    }
    for(int i = 0; i < N; i++){
        vector<int>().swap(path);
        can = unordered_map<int, bool>();
        //l = sub(i, 1), r = add(i, 1), cur = i;
        //cout << "l = " << l << ", r = " << r << endl;
        if(dfs(i, sub(i, 1), add(i, 1), 0)){
            for(int i = 0; i < N; i++){
                cout << ans[i] + 1 << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
}
