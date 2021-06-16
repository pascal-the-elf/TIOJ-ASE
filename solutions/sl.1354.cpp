#include <iostream>
#define int long long int
using namespace std;

const int maxN = 226;

int t, n, dp[maxN][2];

signed main(){
    dp[0][0] = 0;
    dp[0][1] = 1;
    for(int i = 1; i < maxN; i++){
        dp[i][0] = 2 * dp[i - 1][0] + 3 * dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
        //cout << "dp[" << i << "][" << 1 << "] = " << dp[i][1] << endl;
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n][1] << endl;
    }
}
