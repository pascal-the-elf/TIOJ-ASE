#include <iostream>
#include <string.h>
using namespace std;

int N, M, n;

int gcd(int a, int b){
    return(!b) ? a : gcd(b, a % b);
}


int main(){
    while(cin >> N >> M){
        if(!(M | N)) return 0;
        int dp1[M], dp2[M];
        for(int i = 0; i < M; i++)
            dp1[i] = dp2[i] = 0;
        for(int i = 0; i < N; i++){
            cin >> n;
            //cout << " n = " << n << endl;
            for(int j = 0; j < M; j++){
                if(dp1[j] > 0){
                    //cout << "j = " << j << endl;
                    dp2[(j*10 + n) % M] = max(dp1[j] + 1, dp2[(j*10 + n) % M]);
                    //cout << "a : dp2[" << (j*10 + n) % M << "] = " << dp2[(j*10 + n) % M] << endl;
                }
            }
            if(!dp2[n % M]) {
                dp2[n % M] = 1;
                //cout << "dp2[" << n % M << "] = " << dp2[n%M] << endl;
            }
            for(int j = 0; j < M; j++){
                dp1[j] = dp2[j];
            }
            /*
            for(int j = 0 ; j < M; j++)
                cout << dp1[j] << " ";
            cout << endl;
            */
        }
        if(M == 1){
            cout << N << endl;
            continue;
        }
        int maxLen = 0;
        for(int i = 1 ; i < M; i++){
            maxLen = max(maxLen, (gcd(i, M) == 1) * dp1[i]);
        }
        cout << maxLen << endl;
    }
}
