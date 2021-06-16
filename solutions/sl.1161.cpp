#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e6 + 10, INF = 1e9 + 226;

int T, N, K;
pii pairs[maxN];

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

inline void solve(){
    Read(N);
    Read(K);
    for(int i = 0; i < N; i++){
        Read(pairs[i].F);
        Read(pairs[i].S);
    }
    sort(pairs, pairs + N);
    priority_queue<int> pq;
    int ans = INF;
    for(int i = 0; i < N; i++){
        pq.push(pairs[i].S);
        if(pq.size() == K + 1){
            pq.pop();
        }
        if(pq.size() == K) ans = (ans < pairs[i].F + pq.top() ? ans : pairs[i].F + pq.top());
    }
    printf("%d\n", ans);
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}
