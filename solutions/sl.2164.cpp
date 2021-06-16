#include <cstdio>
#define min(a,b) (a<b?a:b)
#define int long long int
using namespace std;

const int maxN = 5e3 + 326, INF = 1e18;
int minDist[maxN], N, x[maxN], y[maxN], z[maxN], ans;
bool isIn[maxN];

inline int d(int i, int j){
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]);
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

signed main(){
	Read(N);
	for(int i = 0; i < N; i++){
		Read(x[i]); 
		Read(y[i]);
		Read(z[i]);
		minDist[i] = INF;
	}
	isIn[0] = true;
	for(register int i = 1; i < N; i++) minDist[i] = d(0, i);
	for(register int i = 0; i < N - 1; i++){
		int minD = INF, minAt = -1;
		for(register int i = 0; i < N; i++){
			if(isIn[i]) continue;
			if(minD > minDist[i]){
				minD = minDist[i];
				minAt = i;
			}
		}
		ans += minD;
		isIn[minAt] = true;
		for(register int i = 0; i < N; i++){
			if(isIn[i]) continue;
			minDist[i] = min(minDist[i], d(i, minAt));
		}
	}
	printf("%ld\n", ans);
}


