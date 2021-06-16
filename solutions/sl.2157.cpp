#include <cstdio>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 5e5 + 326, MOD = 998244353;
int N, arr[maxN], pp[maxN], ans, x;

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

signed main(){
	Read(N);
	int roll = 1;
	for(int i = 0; i < N; i++) Read(arr[i]); 
	sort(arr, arr + N);
	for(int i = 0; i < N; i++){
		x = roll * arr[i] % MOD;
		ans = (ans + x) % MOD;
		roll = roll * 2 % MOD;
	}
	printf("%lld\n", ans);
}
