#include <iostream>
#include <queue>
#include <map>
#define F first
#define S second
using namespace std;

int n, m, x, ans[300001], cnt;
bool arr[300001], has[300001];

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
    Read(n);
    Read(m);
    for(int i = 0; i < m; i++){
        Read(x);
        arr[x] ^= 1;
    }
    for(int i = 1; i <= n; i++){
        if(arr[i]){
            for(int j = i; j <= n; j += i) has[j] ^= 1;
        }
        if(has[i]) ans[cnt++] = i;
    }
    cout << cnt << '\n';
    for(int i = 0; i < cnt;i++) cout << ans[i] << '\n';
}
