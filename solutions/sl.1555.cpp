#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);
using namespace std;

const int maxN = 5005;

long long int cnt;
int N, M, dp[2][maxN], mx;
string s;

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
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

inline void const ReadStr(string & s) {
	s = "";
	static char c;
	for(int i = 0; i <= M; i++){
        c = readchar();
        if(c == '0' || c == '1')
            s += c;
	}
}

int main(){
    Read(N);
    Read(M);
    ReadStr(s);
    for(int i = 1; i <= M; i++){
        if(s[i - 1] == '0'){
            cnt++;
            mx = 1;
            dp[0][i] = 1;
        }
    }
    for(int i = 1; i < N; i++){
        ReadStr(s);
        for(int j = 1; j <= M; j++){
            if(s[j - 1] == '0'){
                dp[1][j] = min(dp[0][j - 1], min(dp[0][j], dp[1][j - 1])) + 1;
                mx = max(mx, dp[1][j]);
                cnt += dp[1][j];
            } else {
                dp[1][j] = 0;
            }
        }
        for(int j = 1; j <= M; j++) dp[0][j] = dp[1][j];
    }
    cout << cnt << " " << mx << '\n';
}
