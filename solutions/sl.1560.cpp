#include <iostream>
using namespace std;

long long int dp[55][2], N;

int main(){
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= 50; i++){
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }
    while(cin >> N){
        cout << dp[N][0] + dp[N][1] << endl;
    }

}
