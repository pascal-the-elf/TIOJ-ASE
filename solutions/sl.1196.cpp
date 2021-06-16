#include <iostream>
#include <string>
using namespace std;

const int INF = 1e7;

string s;

int N, vals[15][15], dp[15][15];

int main(){
    cin >> N >> s;
    s = '$' + s;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++) dp[i][j] = -INF;
    }
    dp[1][1] = 0;
    for(int i = 2; i <= N; i++){
        vals[1][i] = (s[i] == 'X' ? -INF : s[i] - '0');
        dp[1][i] = vals[1][i] + max(0, dp[1][i - 1]);
    }
    for(int i = 2; i < N; i++){
        cin >> s;
        s = '$' + s;
        for(int j = 1; j <= N; j++){
            vals[i][j] = (s[j] == 'X' ? -INF : s[j] - '0');
            dp[i][j] = vals[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cin >> s;
    s = '$' + s;
    for(int j = 1; j < N; j++){
        vals[N][j] = (s[j] == 'X' ? -INF : s[j] - '0');
        dp[N][j] = vals[N][j] + max(dp[N - 1][j], dp[N][j - 1]);
    }
    dp[N][N] = max(dp[N - 1][N], dp[N][N - 1]);
    if(dp[N][N] < 0) cout << "X\n";
    else cout << dp[N][N] << endl;
}
