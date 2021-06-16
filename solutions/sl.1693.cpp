#include <iostream>
using namespace std;

const int maxN = 226;

int N, x[maxN], y[maxN], r[maxN], h[maxN];
int adj[maxN][maxN], dist[maxN][maxN], colour[maxN], stk[maxN], m;

inline bool isAdj(int i, int j){
    int l1, r1, u1, d1, l2, r2, u2, d2;
    if(i & 1){
        i >>= 1;
        l1 = x[i] - r[i];
        r1 = x[i] + r[i];
        u1 = y[i] + h[i];
        d1 = y[i] - h[i];
    } else {
        i >>= 1;
        l1 = x[i] - h[i];
        r1 = x[i] + h[i];
        u1 = y[i] + r[i];
        d1 = y[i] - r[i];
    }
    if(j & 1){
        j >>= 1;
        l2 = x[j] - r[j];
        r2 = x[j] + r[j];
        u2 = y[j] + h[j];
        d2 = y[j] - h[j];
    } else {
        j >>= 1;
        l2 = x[j] - h[j];
        r2 = x[j] + h[j];
        u2 = y[j] + r[j];
        d2 = y[j] - r[j];
    }
    if(l1 > r2 || l2 > r1 || u1 < d2 || u2 < d1) return false;
    return true;
    //cout << "For i = " << i << ", l, r, u, d = " << l1 << ", " << r1 << ", " << u1 << ", " << d1 << endl;
    //cout << "For j = " << j << ", l, r, u, d = " << l2 << ", " << r2 << ", " << u2 << ", " << d2 << endl;
}

bool dfs(int u){
    if(colour[u] ==-1) return false;
    if(colour[u] == 1) return true;

    stk[m++] = u;
    colour[u    ] =  1;
    colour[u ^ 1] = -1;
    for(int i = 0; i < 2 * N; i++){
        if(u == i) continue;
        if(!adj[u][i] && !dfs(i)) return false;
    }
    return true;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> r[i] >> h[i];
        h[i] = max(h[i], r[i]);
    }

    for(int i = 0; i < 2 * N; i++){
        for(int j = 0; j < 2 * N; j++){
            adj[i][j] = 1;
            dist[i][j] = 1;
        }
        dist[i][i] = 0;
    }

    for(int i = 0; i < 2 * N; i++){
        for(int j = 0; j < 2 * N; j++){
            if((i >> 1) == (j >> 1)) continue;
            if(isAdj(i, j)){
                //cout << i << " " << (j ^ 1) << endl;
                //cout << j << " " << (i ^ 1) << endl;
                adj[i][j ^ 1] = adj[j][i ^ 1] = dist[i][j ^ 1] = dist[j][i ^ 1] = 0;
            }
        }
    }
    for(int k = 0; k < 2 * N; k++)
        for(int i = 0; i < 2 * N; i++)
            for(int j = 0; j < 2 * N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for(int i = 0; i < N; i++){
        if(!dist[i << 1][(i << 1) | 1] && !dist[(i << 1) | 1][(i << 1)]){
            cout << "so sad\n";
            return 0;
        }
    }

    //ODD: H
    //EVEN: V
    for(int i = 1; i < 2 * N; i += 2){
        if(!colour[i]){
            m = 0;
            if(!dfs(i)){
                while(m){
                    colour[stk[m - 1]] = colour[stk[m - 1] ^ 1] = 0;
                    m--;
                }
                if(!dfs(i ^ 1)){
                    cout << "so sad\n";
                    return 0;
                }
            }
        }
    }
    for(int i = 0; i < 2 * N; i += 2){
        cout << (colour[i] == 1 ? 'V' : 'H');
    }
}
