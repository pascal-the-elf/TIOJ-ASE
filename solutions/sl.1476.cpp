#include <iostream>
#define int long long int
using namespace std;

int dp[50], N;

signed main(){
    dp[0] = dp[1] = 1;
    for(int i = 2; i < 46; i++) dp[i] = dp[i - 1] + dp[i - 2];
    cin >> N;
    cout << dp[N] << endl;
}
