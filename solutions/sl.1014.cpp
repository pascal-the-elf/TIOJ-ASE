#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 18, INF = 1e18;

int dp[(1LL << maxN)][maxN], N, times[maxN];

inline int ceil(int a, int b){
    return (a + b - 1) / b;
}

inline bool hasBit(int i, int j){
    return (i & (1 << j)) > 0;
}

inline int diff(int a, int b){
    return (a - b < 0 ? b - a : a - b);
}

void DP(){
    vector<int> has;
    for(int i = 1; i < (1LL << N); i++)
        for(int j = 0; j < N; j++)
            dp[i][j] = INF;
    for(int i = 0; i < N; i++){
        dp[1 << i][i] = ceil(i + 1, times[i]) * times[i];
    }
    for(int i = 1; i < (1LL << N); i++){
        for(int j = 0; j < N; j++){
            has.clear();
            if(dp[i][j] != INF) continue;
            if(!hasBit(i, j)) continue;
            for(int k = 0; k < N; k++){
                if(hasBit(i, k) && k != j) has.push_back(k);
            }
            for(int x : has){
                dp[i][j] = min(dp[i][j], ceil(dp[i ^ (1 << j)][x] + diff(x, j), times[j]) * times[j]);
            }
            //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> times[i];
    DP();
    int ans = INF; //define inf
    for(int i = 0; i < N; i++) ans = min(dp[(1LL << N) - 1][i], ans);
    cout << ans << endl;
}
