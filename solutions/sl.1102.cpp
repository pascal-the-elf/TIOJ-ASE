#include <iostream>
#include <deque>
#define int long long int
using namespace std;

const int INF = 1e10, maxN = 1e5 + 10;
int R1, R2, N, K, x, sm, mnSum, dp[maxN];
deque<int> dq;

inline int dist(int i, int j){
    return (j - i + N + K) % (N + K) + 1;
}

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

inline void solve(){
    dq = deque<int>();
    for(int i = 0; i < N; i++){
        Read(x);
        dq.push_back(x);
    }
    mnSum = INF;
    for(int ttttt = 0; ttttt < 4; ttttt++){
        sm = 0;
        //for(int i = 0; i < N; i++) cout << dq[i] << " \n"[i == N - 1];
        dp[0] = INF;
        dp[1] = dist(dq[0], dq[1]);
        dp[2] = dist(dq[0], dq[2]);
        for(int i = 3; i < N; i++)
            dp[i] = min(dist(dq[i - 2], dq[i]) + dp[i - 3], dist(dq[i - 1], dq[i]) + dp[i - 2]);
        //for(int i = 0; i < N; i++){
            //cout << "dq[" << i << "] = " << dq[i] << endl;
            //cout << "dp[" << i << "] = " << dp[i] << endl;
        //}
        mnSum = min(mnSum, dp[N - 1]);
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout << N + K - mnSum << '\n';
}

signed main(){
    Read(R1);
    Read(R2);
    Read(N);
    Read(K);
    while(R1 || R2 || N || K){
        solve();
        Read(R1);
        Read(R2);
        Read(N);
        Read(K);
    }
}
