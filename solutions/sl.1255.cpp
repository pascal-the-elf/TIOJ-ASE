#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int INF = 1e8, maxN = 17;

int N, M, t[maxN], dp[1 << maxN][maxN], x[maxN], y[maxN];

inline int abs(int a, int b){
    return (a - b < 0 ? b - a : a - b);
}

inline bool hasBit(int i, int j){
    return (i & (1 << j)) > 0;
}

inline int dist(int i, int j){
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

string getRep(int x){
    string s = "";
    for(int i = 0; i < M; i++){
        s = (char)(((x & (1 << i)) > 0) + '0') + s;
    }
    return s;
}

signed main(){
    while(cin >> N >> M){
        if(!N && !M) return 0;
        for(int i = 0; i < M; i++){
            cin >> x[i] >> y[i] >> t[i];
        }
        dp[0][0] = 0;
        for(int i = 1; i < (1<<M); i++){
            vector<int> has;
            for(int j = 0; j < M; j++){
                dp[i][j] = INF;
                if(hasBit(i, j)) has.push_back(j);
            }
            if(has.size() == 1){
                //cout << "has[0] = " << has[0] << endl;
                dp[i][has[0]] = (abs(x[has[0]] - 1) + abs(y[has[0]] - 1) + t[has[0]] - 1) / t[has[0]] * t[has[0]];
                //cout << "dp[" << getRep(i) << "][" << has[0] << "] = " << dp[i][has[0]] << endl;
            } else {
                for(int k : has){ //going to calculate dp[i][k]
                    for(int l : has){
                        if(l == k) continue;
                        dp[i][k] = min(dp[i][k], (dp[i ^ (1 << k)][l] + dist(k, l) + t[k] - 1) / t[k] * t[k]);
                    }
                    //cout << "dp[" << getRep(i) << "][" << k << "] = " << dp[i][k] << endl;
                }
            }

        }
        int ans = INF;
        for(int i = 0; i < M; i++) ans = min(ans, dp[(1 << M) - 1][i]);
        cout << ans << endl;
    }

}
