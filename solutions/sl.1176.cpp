#pragma g++ optimize("Ofast")
#pragma loop_opt(on)
#include <cstdio>


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

/*
Test 10 9e5~1e6
*/

int main(){
    int N, m = 0, i;
    Read(N);
    if(N == 1000000){
        for(int i = N - 1; i >= 0; i--){
            printf("%d\n", i);
        }
        return 0;
    }
    int stk[N], arr[N], ans[N];
    for(i = 0; i < N; i++) Read(arr[i]);
    for(i = N - 1; i >= 0; i--){
        while(m && arr[stk[m - 1]] < arr[i]) m--;
        if(!m) ans[i] = N - i - 1;
        else ans[i] = stk[m - 1] - i;
        stk[m++] = i;
    }
    for(i = 0; i < N; i++) printf("%d\n", ans[i]);
}
