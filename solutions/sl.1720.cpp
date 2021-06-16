#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 10;

pii pairs[maxN];
int N, M, sz, bit[maxN * 2];
long long int ans;
vector<int> lis;


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

inline void modify(int p){
    for(; p <= sz; p += (p & -p)) bit[p]++;
}

inline int getsum(int p){
    int r = 0;
    for(; p; p -= (p & -p)) r += bit[p];
    return r;
}

int main(){
    Read(N);
    Read(M);
    for(int i = 0; i < N; i++){
        Read(pairs[i].F);
        lis.push_back(pairs[i].F);
    }
    for(int i = 0; i < N; i++){
        Read(pairs[i].S);
        lis.push_back(pairs[i].S);
    }
    sort(lis.begin(), lis.end());
    sz = unique(lis.begin(), lis.end()) - lis.begin();
    for(int i = 0; i < N; i++){
        pairs[i].F = lower_bound(lis.begin(), lis.begin() + sz, pairs[i].F) - lis.begin() + 1;
        pairs[i].S = lower_bound(lis.begin(), lis.begin() + sz, pairs[i].S) - lis.begin() + 1;
    }
    sort(pairs, pairs + N);
    //for(int i = 0; i < N; i++) cout << pairs[i].F << " " << pairs[i].S << endl;
    for(int i = 0; i < N; i++){
        ans += getsum(sz) - getsum(pairs[i].S);
        modify(pairs[i].S);
    }
    cout << ans << '\n';
}
