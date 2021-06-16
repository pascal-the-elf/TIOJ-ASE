#include <iostream>
using namespace std;

long long int N, M, c, w, dp[2020], ans;
int main(){
    cin >> N >> M;
    for(int ii = 0; ii < N; ii++){
        cin >> w >> c;
        for(int i = 0; i <= M - c; i++){
            dp[i + c] = max(dp[i + c], dp[i] + w);
        }
    }
    for(int i = 0; i <= M; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
}
