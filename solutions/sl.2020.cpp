#include <cstdio>
#define int char
using namespace std;

const int INF = 100;

int a, b, dp[100][100];

signed main(){
    int i, j, k;
    for(i = 0; i < 100; i++){
        dp[i][i] = 1;
        dp[0][i] = dp[i][0] = i + 1;
    }
    for(i = 1; i < 100; i++){
        for(j = i + 1; j < 100; j++){
            dp[i][j] = dp[j][i] = INF;
            for(k = 0; k < j; k++){
                if((dp[i][k] + dp[i][j - k - 1]) < dp[i][j]) dp[i][j] = (dp[i][k] + dp[i][j - k - 1]);
            }
            for(k = 0; k < i; k++){
                if((dp[k][j] + dp[i - k - 1][j]) < dp[i][j]) dp[i][j] = (dp[k][j] + dp[i - k - 1][j]);
            }
            //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            dp[j][i] = dp[i][j];
            //mv = max(dp[i][j], mv);
        }
    }
    //cout << "max = " << mv << endl;
    scanf("%hhu%hhu", &a, &b);
    a--;
    b--;
    printf("%hhu\n", dp[a][b]);
}
