#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e6 + 10;

int N, K, price[maxN], dp[maxN][2], xAt;


inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

//dp[i][0] = max(price[i] - price[j] + dp[j - 1])
void Aliens(int C){
    dp[1][0] = 0;
    dp[1][1] = 0;
    int minFrom = 1;
    for(int i = 2; i <= N; i++){
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        if(price[i] - price[minFrom] + dp[minFrom - 1][0] - C > dp[i][0]){
            dp[i][0] = price[i] - price[minFrom] + dp[minFrom - 1][0] - C;
            dp[i][1] = dp[minFrom][1] + 1;
        } else if(price[i] - price[minFrom] + dp[minFrom - 1][0] - C == dp[i][0]){
            dp[i][1] = min(dp[minFrom][1] + 1, dp[i][1]);
        }
        if((dp[i - 1][0] - price[i] > dp[minFrom - 1][0] - price[minFrom]) || ((dp[i - 1][0] - price[i] == dp[minFrom - 1][0] - price[minFrom]) && (dp[i][1] < dp[minFrom][1]))){
            minFrom = i;
        }
    }

}

signed main(){
    ericxiao;
    Read(N);
    Read(K);
    for(int i = 1; i <= N; i++) Read(price[i]);
    int LC = -1, RC = 2e9, M;
    while(LC + 1 < RC){
        M = (LC + RC) / 2;
        Aliens(M);
        if(dp[N][1] > K) LC = M;
        else RC = M;
    }
    Aliens(++LC);
    cout << dp[N][0] + K * LC << endl;
}
