#include <iostream>
using namespace std;

const int maxM = 226, maxN = 101;

int M, N, a, b, c, d, dp[maxM][maxM], t, vertMax[maxM][maxM], curmax, ans;

inline int wei(int i, int x, int y){
    return (a * (i - 1) + b * (x - 1) + c * (y - 1)) % d;
}

int main(){
    cin >> M >> N >> a >> b >> c >> d;
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= M; i++){
            curmax = 0;
            for(int j = 1; j <= M; j++){
                t = wei(k, i, j) + curmax;
                curmax = max(curmax, vertMax[i - 1][j]);
                vertMax[i][j] = max(vertMax[i - 1][j], dp[i][j]);
                dp[i][j] = t;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;
}
