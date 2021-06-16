#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 5226;

int dp[2][maxN], grid[maxN], N, M;

int main(){
    ericxiao;
    while(cin >> N >> M){
        if(!N && !M) return 0;
        int ans = 0;
        for(int i = 0; i < M; i++){
            cin >> grid[i];
            dp[0][i] = !(grid[i] == 2);
            if(ans < dp[0][i]) ans = dp[0][i];
        }
        for(int i = 1; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> grid[i];
                if(grid[i] == 2) dp[1][j] = 0;
                else if(!j) dp[1][j] = 1;
                else {
                    dp[1][j] = min({dp[0][j], dp[1][j - 1], dp[0][j - 1]}) + 1;
                }
                if(ans < dp[1][j]) ans = dp[1][j];
            }
            for(int j = 0; j < M; j++) dp[0][j] = dp[1][j];
        }
        cout << ans * ans << endl;
    }
}
