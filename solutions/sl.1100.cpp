#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1226, INF = 1e7 + 226;
int dp[maxN][maxN], N, l[maxN], r[maxN], p[maxN];

void solve(){
    for(int i = 1; i <= N; i++) cin >> l[i] >> r[i] >> p[i];
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++){
            dp[i][j] = INF;
        }
    for(int i = 0; i <= N; i++) dp[i][0] = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] = dp[i - 1][j];
            int lim = max(dp[i - 1][j - 1], l[i]) + p[i];
            if(lim <= (r[i] + 1)) dp[i][j] = min(dp[i][j], lim);
        }
    }
    int mx = 0;
    for(int i = N; i >= 0; i--){
        if(dp[N][i] < INF){
            cout << i << '\n';
            break;
        }
    }
}

int main(){
    ericxiao;
    while(cin >> N){
        if(!N) return 0;
        solve();
    }
}
