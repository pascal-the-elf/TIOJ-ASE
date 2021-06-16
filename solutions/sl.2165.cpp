#pragma gcc optimize ("Ofast")
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 5e5 + 10;

int arr[maxN], N, Q, S, q, mq, queries[maxN], sums[maxN];

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
	for(int i = 0; i < N; i++){
		int s = 0;
		if(arr[i] > mq) break;
		for(int j = i; j >= 0; j--){
			s += arr[j];
			if(s > mq) break;
			sums[s]++;
		}
	}
}

int main(){
	Read(N);
	for(int i = 0; i < N; i++) Read(arr[i]);
	Read(Q);
	for(int i = 0; i < Q; i++){
		Read(queries[i]);
		mq = max(mq, queries[i]);
	}
	solve();
	for(int i = 0; i < Q; i++) printf("%d\n", sums[queries[i]]);
}
