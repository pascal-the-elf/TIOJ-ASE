#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e4 + 10, MOD = 100000007;

int dp[maxN], nxtdp[maxN], pre[maxN], N;

inline int modpow(int b, int e){
    int r = 1, c = b;
    for(int i = 0; i < 31; i++){
        if((e >> i) & 1) r = r * c % MOD;
        c = c * c % MOD;
    }
    return r;
}

inline int inv(int x){
    return modpow(x, MOD - 2);
}

signed main(){
    cin >> N;
    fill(dp, dp + N + 1, 1);
    for(int i = 1; i <= N; i++){
       pre[i] = (pre[i - 1] + dp[i] * inv(modpow(2, i + 1)) % MOD) % MOD;
       //cout << "pre[1][" << i << "] = " << pre[i] << endl;
    }
    int roll, tom, ans = 1;
    for(int j = 2; j <= N; j++){
        //cout << j << " numbers " << endl;
        //dp[i] = sum(dp[x] * j^{-x}) * j^{i} (1 <= x < i)
        roll = modpow(j, j);
        tom = j;
        for(int i = j; i <= N; i++){
            dp[i] = pre[i - 1] * roll % MOD;
            roll = roll * tom % MOD;
            //cout << "len = " << i << ", dp = " << dp[i] << endl;
        }
        ans = (ans + dp[N]) % MOD;
        fill(pre, pre + N + 1, 0);
        roll = inv(modpow(j + 1, j + 1));
        tom = inv(j + 1);
        for(int i = j; i <= N; i++){
           pre[i] = (pre[i - 1] + dp[i] * roll % MOD) % MOD;
           roll = roll * tom % MOD;
        }
    }
    cout << ans << endl;
}
