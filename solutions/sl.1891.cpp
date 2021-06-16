#include <iostream>
#include <map>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

const int maxN = 5e5 + 10, MOD = 1e9 + 7;

int N, M, com, k, x, u, v, hsh[maxN], h, e, xs;
map<int, int> mp;

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

signed main(){
    ericxiao;
    Read(N);
    Read(M);
    while(M--){
        Read(com);
        if(com == 0){
            Read(u);
            Read(v);
            if(u > v) swap(u, v);
            h = u * MOD + v;
            hsh[u] += h;
            hsh[v] -= h;
        } else if(com == 1){
            Read(u);
            Read(v);
            if(u > v) swap(u, v);
            h = u * MOD + v;
            hsh[u] -= h;
            hsh[v] += h;
        } else {
            xs = 0;
            Read(k);
            while(k--){
                Read(x);
                xs += hsh[x];
            }
            if(!xs) printf("1\n");
            else printf("0\n");
        }
    }
}
