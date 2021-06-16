#include <iostream>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 4e5 + 10, INF = 1e18;

int seg[maxN * 4], minId[maxN * 4], tag[maxN * 4], N, m[maxN], d[maxN], ans[maxN];

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

void pull(int id){
	if(seg[2 * id + 1] < seg[2 * id + 2]){
		minId[id] = minId[2 * id + 1];
		seg[id] = seg[2 * id + 1];
	} else {
		minId[id] = minId[2 * id + 2];
		seg[id] = seg[2 * id + 2];
	}
}

void push(int id, int l, int r){
	seg[id] += tag[id];
	if(l + 1 < r){
		tag[2 * id + 1] += tag[id];
		tag[2 * id + 2] += tag[id];
	}
	tag[id] = 0;
}

void build(int id = 0, int l = 0, int r = N){
	if(l + 1 == r){
		seg[id] = 0; 
		minId[id] = l;
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	pull(id);
}

void modify(int id, int l, int r, int ql, int qr, int v){
	push(id, l, r);
	if(l >= qr || ql >= r) return;
	if(ql <= l && r <= qr){
		tag[id] += v;
		push(id, l, r);
		return;
	}
	int m = (l + r) / 2;
	modify(2 * id + 1, l, m, ql, qr, v);
	modify(2 * id + 2, m, r, ql, qr, v);
	pull(id);
}

pii minAt(int id, int l, int r, int ql, int qr){
	push(id, l, r);
	if(l >= qr || ql >= r) return {INF, -1};
	if(ql <= l && r <= qr){
		return {seg[id], minId[id]};
	}
	int m = (l + r) / 2;
	return min(minAt(2 * id + 1, l, m, ql, qr), minAt(2 * id + 2, m, r, ql, qr));
}

void Modify(int p, int rad, int val){
	//want: p ~ rad + 1, p - rad ~ p
	modify(0, 0, N, p + 1, min(p + rad + 1, N), val);
	if(p + rad + 1 > N){
		modify(0, 0, N, 0, p + rad + 1 - N, val);
	}
	modify(0, 0, N, max(0LL, p - rad), p, val);
	if(p - rad < 0){
		modify(0, 0, N, N - rad + p, N, val);
	}
}

void disp(){
	for(int i = 0; i < N; i++){
		cout << minAt(0, 0, N, i, i + 1).F << " ";
	}
	cout << endl;
}

signed main(){
	//ericxiao;
	Read(N);
	build();
	for(int i = 0; i < N; i++){
		Read(m[i]);
		Read(d[i]);
		Modify(i, d[i], m[i]); 
	}
	for(int i = 0; i < N; i++){
		ans[i] = minAt(0, 0, N, 0, N).S;
		Modify(ans[i], d[ans[i]], -m[ans[i]]);
		modify(0, 0, N, ans[i], ans[i] + 1, INF);
	}
	for(int i = N - 1; i >= 0; i--) printf("%lld ", ans[i] + 1);
}
