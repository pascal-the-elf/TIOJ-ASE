#include <cstdio>
#define int long long int
using namespace std;

const int maxN = 1e6 + 1, INF = 3e17;

int N, K, arr[maxN], pre[maxN], dp[maxN], cm, ma, rt, t;

inline int getMax(int lv, int s){
    for(int i = 1; i <= s; i++) dp[i] = pre[i];
    for(int k = 1; k <= lv; k++){
        cm = dp[k - 1][k - 1] + (k % 2 ? -pre[k - 1] : pre[k - 1]);
        ma = k - 1;
        for(int i = k; i <= s; i++){
            t = cm + (k % 2 ? pre[i] : -pre[i]);
            if(k == lv && i == s) rt = ma;
            if(cm < dp[i] + (k % 2 ? -pre[i] : pre[i])){
                ma = i;
                cm = dp[i] + (k % 2 ? -pre[i] : pre[i]);
            }
            dp[i] = t;
        }
        for(int i = 1; i <= s; i++) dp[0][i] = dp[1][i];
    }
    return rt;
}

signed main(){
    ericxiao;
    scanf("%lld%lld", &N, &K);
    for(int i = 1; i <= N; i++){
        scanf("%lld", arr + i);
        pre[i] = pre[i - 1] + arr[i];
    }
    for(int lv = K - 1, currentF = getMax(K, N); lv; currentF = getMax(lv--, currentF)){
        printf("%lld\n", currentF);
    }
}
