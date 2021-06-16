#include <iostream>
using namespace std;

int val[105][105], dp[105][105];
int N;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            cin >> val[i][j];
            dp[i][j] = 0;
        }
    }
    dp[1][1] = val[1][1];
    int ans = 0;
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + val[i][j];
            if(i == N) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}

