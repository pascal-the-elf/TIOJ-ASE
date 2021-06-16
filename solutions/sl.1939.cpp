#include <iostream>
#define int long long int
using namespace std;

const int maxN = 110, M = 1e9 + 9;

inline int add(int a, int b){
    return (a + b >= M ? a + b - M : a + b);
}

int dp[maxN], pre[maxN], T, N;

signed main(){
    for(int i = 1; i < maxN; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            dp[i] = add(dp[i], dp[j] * (i - j) * 2 % M);
        }
        pre[i] = add(pre[i - 1], dp[i]);
    }
    cin >> T;
    while(T--){
        cin >> N;
        cout << pre[N] << endl;
    }
}
