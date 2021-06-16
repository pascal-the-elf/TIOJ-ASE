#include <iostream>
#define int long long int
using namespace std;

const int maxP = 1e4 + 6, maxN = 101;

int n, k, dp[maxP], v;

signed main(){
    while(cin >> n >> k){
        if(!n && !k) return 0;
        fill(dp, dp + k + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            cin >> v;
            for(int j = v; j <= k; j++) dp[j] += dp[j - v];
        }
        cout << dp[k] << endl;
    }

}
