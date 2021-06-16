#pragma gcc optimize ("Ofast")
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define endl '\n'
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10, maxLog = 200;

pii seg[maxN * 4];
int seed = 101,x, y, l, r, k; 
int N, Q, arr[maxN], com, cnt = 1, val[maxN * maxLog], lft[maxN * maxLog], rgt[maxN * maxLog], sz[maxN * maxLog], pri[maxN * maxLog];
bool isAllZero[maxN * 4];
unordered_map<int, int> treaps;

inline char readchar(){
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

inline int Rand(){
	return seed = (seed * 3 + 1) % 0xdefaced;
}

inline int newNode(int x){
	sz[cnt] = 1;
	val[cnt] = x;
	lft[cnt] = rgt[cnt] = 0;
	pri[cnt] = Rand();
	return cnt++;
}

inline int Sz(int x){
	return x ? sz[x] : 0;
}

inline void tpull(int x){
	sz[x] = 1 + Sz(lft[x]) + Sz(rgt[x]);
}

int Merge(int a, int b){
	if(!a || !b) return a ? a : b;
	if(pri[a] < pri[b]){
		rgt[a] = Merge(rgt[a], b);
		tpull(a);
		return a;
	}
	lft[b] = Merge(a, lft[b]);
	tpull(b);
	return b;
}

void Split(int o, int &a, int &b, int v){
	if(!o){
		a = b = 0;
		return;
	}
	if(val[o] < v){
		a = o;
		Split(rgt[o], rgt[a], b, v);
		tpull(a);
		return;
	}
	b = o;
	Split(lft[o], a, lft[b], v);
	tpull(b);
}

inline void Ins(int &root, int val){
	int a, b, c, d;
	Split(root, a, b, val);
	root = Merge(a, Merge(newNode(val), b));
}

inline void Del(int &root, int val){
	int a, b, c, d;	
	Split(root, a, b, val);
	Split(b, b, c, val + 1);
	root = Merge(a, c);
}

inline int getNum(int &root, int l, int r){ //[l, r)
	int a, b, c;
	Split(root, a, c, r);
	Split(a, a, b, l);
	int k = Sz(b);
	root = Merge(a, Merge(b, c));
	return k;
}

inline void pull(int id){
	if(seg[2 * id + 1].F == seg[2 * id + 2].F) seg[id] = {seg[2 * id + 1].F, seg[2 * id + 1].S + seg[2 * id + 2 ].S};
	else if(seg[2 * id + 1].S >= seg[2 * id + 2].S) seg[id] = {seg[2 * id + 1].F, seg[2 * id + 1].S - seg[2 * id + 2].S};
	else seg[id] = {seg[2 * id + 2].F, seg[2 * id + 2].S - seg[2 * id + 1].S};
	isAllZero[id] = isAllZero[2 * id + 1] & isAllZero[2 * id + 2];
}

void build(int id = 0, int l = 0, int r = N){
	if(l + 1 == r){
		seg[id] = {arr[l], 1};
		isAllZero[id] = (arr[l] == 0);
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	pull(id);
}

void div(int id, int l, int r, int ql, int qr, int val){
	if(l >= qr || ql >= r || isAllZero[id]) return;	
	if(l + 1 == r){
		Del(treaps[seg[id].F], l);
		seg[id].F /= val;
		Ins(treaps[seg[id].F], l);
		isAllZero[id] = (seg[id].F == 0); 
		return;
	}
	int m = (l + r) / 2;
	div(2 * id + 1, l, m, ql, qr, val);
	div(2 * id + 2, m, r, ql, qr, val);
	pull(id);
}

void mod(int id, int l, int r, int pos, int val){
	if(l + 1 == r){
		Del(treaps[seg[id].F], l);
		seg[id].F = val;
		Ins(treaps[seg[id].F], l);
		isAllZero[id] = (seg[id].F == 0);
		return;
	}
	int m = (l + r) / 2;
	if(pos < m){
		mod(2 * id + 1, l, m, pos, val);
	} else {
		mod(2 * id + 2, m, r, pos, val);
	}
	pull(id);
}

pii query(int id, int l, int r, int ql, int qr){
	if(l >= qr || ql >= r) return {-1, 0};
	if(ql <= l && r <= qr) return seg[id];
	int m = (l + r) / 2;
	pii lft = query(2 * id + 1, l, m, ql, qr);
	pii rgt = query(2 * id + 2, m, r, ql, qr);
	if(lft.F == rgt.F) return {lft.F, lft.S + rgt.S};
	if(lft.S >= rgt.S) return {lft.F, lft.S - rgt.S};
	if(lft.S < rgt.S) return {rgt.F, rgt.S - lft.S};
}
/*
void dfs(int x){
	if(!x) return;
	dfs(lft[x]);
	cout << val[x] << " ";
	dfs(rgt[x]);
}

void treapDisp(){
	for(auto [f, r] : treaps){
		cout << "Treap of " << f << ": "; dfs(r);
		cout << endl;
	}
}

void segDisp(){	
	for(int i = 0; i < N; i++){
		cout << query(0, 0, N, i, i + 1).F  << query(0, 0, N, i, i + 1).S << " "; 
	}
	cout << endl;
}
*/
int main(){
	//ericxiao;
	Read(N);
	Read(Q);
	treaps.reserve(N* 30);
	treaps.max_load_factor(100);
	for(int i = 0; i < N; i++){
		Read(arr[i]);
		//cout << "Root = " << treaps[arr[i]] << endl;
		treaps[arr[i]] = Merge(treaps[arr[i]], newNode(i));
	}
	build();
	//cout << "Seg: " << endl;
	//segDisp();
	//cout << "Treap: "  << endl;
	//treapDisp();
	while(Q--){
		Read(com);
		if(com == 1){
			Read(x);
			Read(y);
			mod(0, 0, N, x - 1, y);
		} else if(com == 2){
			Read(l);
			Read(r);
			Read(k);
			div(0, 0, N, l - 1, r, k);
		} else {
			Read(l);
			Read(r);
			pii res = query(0, 0, N, l - 1, r); 
			//cout << res.F << " * " << res.S << endl;
			if(getNum(treaps[res.F], l - 1, r) >= (r - l + 3) / 2){
				printf("%d\n", res.F);
			} else {
				printf("-1\n");
			}
		}
		//cout << "Seg: " << endl;
		//segDisp();
		//cout << "Treap: "  << endl;
		//treapDisp();
	}
}
