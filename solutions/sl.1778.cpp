#include <iostream>
#include <vector>
#define vv vector<vector<int> >
#define int long long int
using namespace std;

const int MOD = 1000000009;

int N, M, S, T, K, u, v;
vv I, adj;

inline vv operator *(vv a, vv b){
    vv res;
    res.resize(N);
    for(int i = 0; i < N; i++){
        res[i].resize(N);
        for(int j = 0; j < N; j++){
            res[i][j] = 0;
            for(int k = 0; k < N; k++){
                res[i][j] = (res[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    return res;
}

inline vv operator^(vv b, int e){
    vv r = I, c = b;
    for(int i = 0; i < 60; i++){
        if((e >> i) & 1){
            r = r * c;
        }
        c = c * c;
    }
    return r;
}

signed main(){
    cin >> N >> M >> S >> T >> K;
    S--;
    T--;
    adj.resize(N);
    I.resize(N);
    for(int i = 0; i < N; i++){
        adj[i].resize(N);
        I[i].resize(N);
        for(int j = 0; j < N; j++) adj[i][j] = I[i][j] = 0;
        I[i][i] = 1;
    }
    while(M--){
        cin >> u >> v;
        u--;
        v--;
        adj[u][v]++; //有重邊
        adj[v][u]++;
    }
    adj = adj ^ (K);
    cout << adj[S][T] << endl;
}
