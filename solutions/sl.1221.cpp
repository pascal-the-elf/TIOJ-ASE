#include <cstdio>
using namespace std;

const int maxN = 5e5 + 10;

int N, K, P, arr[maxN], last[maxN], nxt[maxN], nxtPos[maxN], cnt, ans;

bool has[maxN];

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


inline int cmp(int i, int j){
	if(!has[i]) return j;
	if(!has[j]) return i;
	return (nxtPos[i] > nxtPos[j]) ? i : j;
}

struct ZCK{
	int seg[maxN * 2], sz;
	inline void pull(int id){
		seg[id] = cmp(seg[2 * id + 1], seg[2 * id]);
	}
	ZCK(){}
	ZCK(int sz): sz(sz){
		for(int i = sz; i < 2 * sz; i++) seg[i] = i - sz;
		for(int i = sz - 1; i >= 0; i--) pull(i);
	}
	inline void upd(int p){
		for(p += sz; p; p >>= 1) pull(p >> 1);
	}
	inline int getMax(){
		return seg[0];
	}
} rmq;

int main(){
	Read(N);
	Read(K);
	Read(P);
	for(int i = 1; i <= N; i++) last[i] = P + 1;
	for(int i = 0; i < P; i++) Read(arr[i]); 
	for(int i = P - 1; i >= 0; i--){
		nxt[i] = last[arr[i]];
		last[arr[i]] = i;
	}
	rmq = ZCK(N + 1);
	for(int i = 0; i < P; i++){
		nxtPos[arr[i]] = nxt[i];
		if(!has[arr[i]]){
			ans++;
			if(cnt == K){
				int mx = rmq.getMax();	
				has[mx] = false;
				rmq.upd(mx);
			} else {
				cnt++;		
			}
			has[arr[i]] = true;
		}
		rmq.upd(arr[i]);
	}
	printf("%d\n", ans);
}
