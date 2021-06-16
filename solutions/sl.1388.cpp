#include <iostream>
#define int long long int
using namespace std;

const int maxN = 226;

int vals[maxN], dp[maxN][maxN], N;

signed main(){
    while(cin >> N){
        for(int i = 0; i < N; i++){
            cin >> vals[i];
            dp[i][i] = vals[i];
        }
        for(int l = N - 1; l >= 0; l--){
            for(int r = l + 1; r < N; r++){
                dp[l][r] = -1;
                for(int i = l; i < r; i++){
                    if((r - l + 1) % 2){
                        dp[l][r] = max(dp[l][i] * dp[i + 1][r], dp[l][r]);
                    } else {
                        dp[l][r] = max(dp[l][i] + dp[i + 1][r], dp[l][r]);
                    }
                }
                //cout << "dp[" << l << "][" << r << "] = " << dp[l][r] << endl;
            }
        }
        cout << dp[0][N - 1] << endl;
    }

}
