#include <iostream>
using namespace std;

int T, N, x, l;
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

int main(){
	Read(T);
	while(T--){
		Read(N);
		N--;
		Read(l);
		int cmax = -1, cmin = 2147483647;
		while(N--){
			Read(x);
			if(x > l) cmin = min(x, cmin);
			if(x < l) cmax = max(x, cmax);
		}
		printf("%d %d\n", cmin, cmax);
	}
}
