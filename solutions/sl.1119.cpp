#include <iostream>
#define int long long int
using namespace std;

const int maxN = 25;

int dp[maxN], dp2[maxN], sizes[maxN], n, k;

signed main(){
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> sizes[i];
            dp2[i] = 2 * dp2[i - 1] + sizes[i];
            if(i == 1){
                dp[i] = 2 * sizes[i] - 1;
                continue;
            }

            if(sizes[i] == 1)
                dp[i] = 2 * dp2[i - 1] + sizes[i];
            else {
                dp[i] = 2 * dp2[i - 1] + sizes[i] * 2 + dp[i - 1];
            }
        }
        cout << dp[n] << '\n';
    }

}
