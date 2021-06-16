#include <iostream>
#define int long long int
using namespace std;

const int maxN = 42;

int dp[maxN], N;

signed main(){
    dp[1] = 1;
    for(int i = 3; i < maxN; i += 2){
        dp[i] = dp[i - 2];
        for(int j = 2; i - j > 0; j += 2){
            dp[i] += dp[i - j] * 2;
        }
        dp[i]++;
    }
    while(cin >> N){
        cout << dp[N] << endl;
    }
}
