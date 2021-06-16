#include <iostream>
#include <math.h>
using namespace std;
//By S
int N, M;

int main(){
    while(cin >> M >> N){
        unsigned long long int dp[N][M+1]; //ith day has j bulbs lit up ways
        for(int i = 0; i < N; i++)
            for(int j = 0; j <= M; j++)
                dp[i][j] = 0;
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 0; i < N-1; i++){
            for(int j = 0; j <= M; j++){
                dp[i+1][0] += dp[i][j];
                if(j < M) dp[i+1][j+1] += dp[i][j];
            }
            /*
            for(int j = 0; j <= M; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
            */
        }
        /*
        for(int j = 0; j <= M; j++){
                cout << dp[N][j] << " ";
            }
        cout<< endl;
        */
        unsigned long long int ans = 0;
        for(int i = 0; i <= M; i++)
            ans += dp[N-1][i];
        printf("%lld\n", ans);
    }
}
