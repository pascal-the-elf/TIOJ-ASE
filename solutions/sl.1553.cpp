#include <iostream>
using namespace std;

const int maxN = 226;

int dp[maxN][maxN], N, arr[maxN], pre[maxN], newarr[maxN], ans, mx, sm;

inline int sum(int l, int r){
    return pre[r] - (l ? pre[l - 1] : 0);
}

int canWin(int take){
    for(int i = take + 1; i < N; i++){
        newarr[i - take - 1] = arr[i];
    }
    for(int i = 0; i < take; i++){
        newarr[i + N - take - 1] = arr[i];
    }
    for(int i = 0; i < N - 1; i++){
        pre[i] = newarr[i];
        if(i) pre[i] += pre[i - 1];
        //cout << newarr[i] << " \n"[i == N - 2];
    }
    for(int i = 0; i < N - 1; i++){
        dp[i][i] = newarr[i];
    }
    for(int l = 2; l <= N - 1; l++){
        for(int i = 0; i + l - 1 < N - 1; i++){
            dp[i][i + l - 1] = sum(i, i + l - 1) - min(dp[i + 1][i + l - 1], dp[i][i + l - 2]);
            //cout << "dp[" << i << "][" << i + l - 1 << "] = " << dp[i][i + l - 1] << endl;
        }
    }
    mx = max(mx, sm - dp[0][N - 2]);
    //cout << "Shift = " << shift << endl;
    //cout << "mx = " << mx << endl;
    return (2 * dp[0][N - 2] < sm);
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sm += arr[i];
    }
    //cout << "sm = " << sm << endl;
    for(int i = 0; i < N; i++) ans += canWin(i);
    cout << ans << " " << mx << endl;
}


