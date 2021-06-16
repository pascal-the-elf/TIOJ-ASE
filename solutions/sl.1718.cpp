#include <iostream>
using namespace std;

const int maxN = 1e4 + 10;

int M, N, P, dp[maxN], newdp[maxN], w, v;

int main(){
    cin >> M >> N >> P;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < P; j++){
            cin >> w >> v;
            for(int k = M; k >= w; k--){
                newdp[k] = max(newdp[k], dp[k - w] + v);
            }
        }
        for(int j = 0; j <= M; j++){
            dp[j] = max(dp[j], newdp[j]);
            newdp[j] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i <= M; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
}
