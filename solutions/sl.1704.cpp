#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 2e9, maxN = 2005;

int n, k;
vector<int> vals[maxN];
vector<int> dp;

int main(){
    ericxiao;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        vals[i].resize(n + 1);
        cin >> vals[i][0];
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            cin >> vals[i][j];
        }
    }
    sort(vals, vals + n, [](vector<int> a, vector<int> b){
        return a[0] < b[0];
    });

    dp.resize(n + 1);
    fill(dp.begin(), dp.end(), -INF);
    dp[0] = 0;
    int ans = n + 1;
    for(int i = 0; i < n; i++){
        for(int j = n; j; j--){
            if(dp[j - 1] == -INF) continue;
            else dp[j] = max(dp[j], dp[j - 1] + vals[i][j]);
            if(dp[j] >= k){
                ans = min(ans, j);
            }
            //cout << "Max cost for " << j << " oranges = " << dp[j] << endl;
        }
    }
    if(ans == n + 1) cout << -1 << endl;
    else cout << ans << endl;
}
