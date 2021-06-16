#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 1e4 + 10;

int N, x[maxN], ls, sm;

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


int main(){
    Read(N);
    for(int i = 1; i <= N; i++) Read(x[i]);
    sort(x, x + N + 1);
    for(int i = 1; i <= N; i++) sm += (x[i] - x[i - 1]) * (x[i] - x[i - 1]);
    cout << sm << '\n';
}
