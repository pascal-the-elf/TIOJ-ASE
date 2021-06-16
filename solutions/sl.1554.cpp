#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const int maxN = 20;

int N, l2[(1 << maxN)];
double dp[(1 << maxN)], nxtdp[(1 << maxN)], arr[maxN][maxN];
int main(){
    cout << fixed << setprecision(2);
    cin >> N;
    for(int i = 0; i < N; i++) l2[(1 << i)] = i;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            arr[i][j] /= 100;
        }
    }
    for(int i = 0; i < N; i++){
        dp[(1 << i)] = arr[0][i];
    }
    for(int i = 1; i < N; i++){
        for(int m = 0; m < (1 << N); m++){
            int _m = m;
            //cout << "m = " << m << endl;
            nxtdp[m] = dp[m];
            while(_m){
                //cout << "Looking at bit " << (_m & -_m) << endl;
                nxtdp[m] = max(nxtdp[m], dp[m ^ (_m & -_m)] * arr[i][l2[(_m & -_m)]]);
                _m -= (_m & -_m);
            }
            //cout << "dp[" << i << "][" << m << "] = " << nxtdp[m] << endl;
        }
        for(int m = 0; m < (1 << N); m++) dp[m] = nxtdp[m];
    }
    //for(int i = 0; i < (1 << N); i++) cout << "FINDP[" << i << "] = " << dp[i] << endl;
    cout << dp[(1 << N) - 1] * 100 << endl;
}
