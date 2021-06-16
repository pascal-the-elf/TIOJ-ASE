#include <iostream>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int maxN = 1e5 + 10, maxK = 71, MOD = (1LL << 61) - 1;
inline char readchar(){
	static const int size = 1 << 16;
	static char buf[size], *p = buf, *e = buf;
	if(p == e && (p = buf) == (e = fread_unlocked(buf, sizeof(char), size, stdin) + buf))return EOF;
	return *p++;
}
template<class T>
void read(T &v){
	static char p;
	bool minus = false;
	while(!isdigit(p = readchar()))minus = p == '-';
	v = p ^ '0';
	while(isdigit(p = readchar()))v *= 10, v += p ^ '0';
}
int N, K, T, sz, dp[2][maxN], arr[maxN], lis[maxN];

inline int add(int a, int b){
    return (a + b >= MOD ? a + b - MOD : a + b);
}

struct BIT{
    int n, bit[maxN];
    BIT(){
        n = sz + 5;
        fill(bit, bit + n, 0);
    }
    void modify(int p, int x){
        for(; p <= n; p += (p & -p)) bit[p] = add(bit[p], x);
    }
    int query(int p){
        int r = 0;
        for(; p; p -= (p & -p)) r = add(r, bit[p]);
        return r;
    }
} bit;

signed main(){
    ericxiao;
    read(T);
    while(T--){
        read(N);
		read(K);
        for(int i = 0; i < N; ++i){
			read(arr[i]);
            lis[i] = arr[i];
        }
        sort(lis, lis + N);
        sz = unique(lis, lis + N) - lis;
        for(int i = 0; i < N; i++) arr[i] = upper_bound(lis, lis + sz, arr[i]) - lis;
        int ans = 0;
        for(int i = 0; i < N; ++i){
            dp[0][i] = 1;
            ans = add(ans, dp[0][i]);
        }
        for(int k = 2; k <= K; ++k){
            bit = BIT();
            for(int i = k - 2; i < N; ++i){
                dp[1][i] = bit.query(arr[i] - 1);
                bit.modify(arr[i], dp[0][i]);
                ans = add(ans, dp[1][i]);
            }
            for(int i = 0; i < N; i++) dp[0][i] = dp[1][i];
        }
        cout << ans << '\n';
    }
}
