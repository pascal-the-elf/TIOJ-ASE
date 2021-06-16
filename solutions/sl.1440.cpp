#include <cstdio>
#include <algorithm>
#include <stack>
//#define int long long int
using namespace std;

const int maxN = 1e6 + 10;

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


struct Obj{
    int val, type, cost;
    Obj(){}
    Obj(int V, int C): val(V), type(1), cost(C){}; //breakfast
    Obj(int V): val(V), type(0){}; //person
    const bool operator<(const Obj &o) const {
        if(val == o.val) return type < o.type;
        return val < o.val;
    }
} objs[2 * maxN];

stack<Obj> stk;

int N, M, v, c;
long long int ans;
signed main(){
    Read(N);
    for(int i = 0; i < N; i++){
        Read(v);
        objs[i] = Obj(v);
    }
    Read(M);
    for(int i = N; i < N + M; i++){
        Read(v);
        Read(c);
        objs[i] = Obj(v, c);
    }
    sort(objs, objs + N + M);
    ans = 0;
    for(int i = 0; i < N + M; i++){
        if(objs[i].type){
            if(stk.size()){
                stk.pop();
                ans += objs[i].cost;
            }
        } else {
            stk.push(objs[i]);
        }
    }
    if(stk.size()) printf("Impossible.\n");
    else printf("%lld\n", ans);
}
