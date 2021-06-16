#include <cstdio>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 10;

int N, h, x, y, ans, mh, tmp, i;
pii perm[maxN];
char c;

inline char readchar() {
    static const size_t bufsize = 16384;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	tmp = 0;
	c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

int main(){
    Read(N);
    for(i = 0; i < N; i++){
        Read(x);
        Read(y);
        Read(h);
        perm[i] = {x * x + y * y, -h};
    }
    sort(perm, perm + N);
    for(i = 0; i < N; i++){
        ans = ans < mh + perm[i].S ? mh + perm[i].S : ans;
        mh = mh > -perm[i].S  ? mh : -perm[i].S;
    }
    printf("%d\n", ans);
}
