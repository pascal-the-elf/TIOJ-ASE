#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1226, INF = 1e9;

int N, arr[maxN], pre[maxN], dp[maxN][maxN];

inline int getCost(int l, int m, int r){
    return (pre[m] - pre[l - 1]) *(pre[r] - pre[m]);
}

int main(){
    ericxiao;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++){
        pre[i] = pre[i - 1] + arr[i];
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) dp[i][j] = -INF;
        dp[i][i] = 0;
    }
    for(int d = 2; d <= N; d++){
        for(int i = 1; i <= N - d + 1; i++){
            //cout << "from " << i << " to " << i + d - 1 << endl;
            for(int j = i; j < i + d - 1; j++){
                //cout << "j = " << j << ", cost = " << getCost(i, j, i + d - 1) << endl;
                dp[i][i + d - 1] = max(dp[i][i + d - 1], getCost(i, j, i + d - 1) + max(dp[i][j], dp[j + 1][i + d - 1]));
            }
            //cout << "dp[" << i << "][" << i + d - 1 << "] = " << dp[i][i + d - 1] << endl;
        }
    }
    cout << dp[1][N] << endl;
}
