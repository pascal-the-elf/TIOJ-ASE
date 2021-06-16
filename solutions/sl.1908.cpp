#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxN = 22, jizz = 46368 + 226;

int N, vals[maxN][maxN], dp[jizz], nxtdp[jizz], masks[jizz], m, ans, msk;
unsigned short id[(1 << maxN)];
vector<int> adj[jizz];

inline void rep(int x){
    for(int i = 0; i < N; i++){
        cout << (x & 1);
        x /= 2;
    }
    cout << endl;
}

void dfs(int id, int curmsk, int idx = 0){
    if(idx == N){
        //rep(msk);
        adj[id].push_back(msk);
        return;
    }
    if((idx && (msk >> (idx - 1)) & 1) || (curmsk >> idx) & 1 || (curmsk >> (idx - 1)) & 1 || (curmsk >> (idx + 1)) & 1){
        dfs(id, curmsk, idx + 1);
    } else {
        dfs(id, curmsk, idx + 1);
        msk ^= (1 << idx);
        dfs(id, curmsk, idx + 1);
        msk ^= (1 << idx);
    }
}



int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> vals[i][j];
        }
	}
    for(int i = 0; i < (1 << N); i++){
        bool f = true;
        for(int j = 1; j < N; j++) if(((i >> j) & 1) && ((i >> (j - 1)) & 1)) f = false;
        if(f){
            masks[m++] = i;
            id[i] = m - 1;
        }
    }

    for(int i = 0; i < m; i++){
        //fill(msk, msk + N, 0);
        //cout << "Bleh: "  << endl;
        //rep(masks[i]);
        //cout << endl;
        msk = 0;
        dfs(i, masks[i]);
    }
    //cout << "DONE\n";
    for(int i = 0; i < N; i++){
        for(int k = 0; k < m; k++){
            for(int j = 0; j < N; j++){
                if((masks[k] >> j) & 1) dp[k] += vals[i][j];
            }
            //cout << "dp[" << i << "][" << masks[k] << "] = " << dp[masks[k]] << endl;
            if(i == N - 1){
                ans = max(ans, dp[k]);
            }
            if(i < N - 1){
                for(int to : adj[k]){
                    //cout << "to = " << to << endl;
                    nxtdp[id[to]] = max(nxtdp[id[to]], dp[k]);
                }
            }
        }
        for(int k = 0; k < m; k++){
            dp[k] = nxtdp[k];
            nxtdp[k] = 0;
        }
    }
    cout << ans << endl;
}
