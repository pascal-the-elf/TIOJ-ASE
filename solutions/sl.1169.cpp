#include <cstdio>
#include <algorithm>
//#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e7 + 200, maxRoots = 2e7;

int l[maxN], r[maxN], lMost[maxN], rMost[maxN], pri[maxN], id[maxN], roots[maxRoots], cnt, arr[maxN], maxLen[maxN], seed = 101, a, b, c, d;

inline int Rand(){
	return seed = (3 * seed + 23) % (0xdefaced);
}

int N, Q, C, com, A, B, K;

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

inline void pull(int i){
	lMost[i] = rMost[i] = id[i];
	maxLen[i] = 0;
	if(~l[i]){
		lMost[i] = lMost[l[i]];
		maxLen[i] = max(maxLen[i], maxLen[l[i]]);
		maxLen[i] = max(maxLen[i], id[i] - rMost[l[i]] - 1);
	}
	if(~r[i]){
		rMost[i] = rMost[r[i]];
		maxLen[i] =  max(maxLen[i], maxLen[r[i]]);
		maxLen[i] = max(maxLen[i], lMost[r[i]] - id[i] - 1);
	}
}

inline int newNode(int x){
	int o = cnt++;
	l[o] = r[o] = -1;
	id[o] = lMost[o] = rMost[o] = x;
	pri[o] = Rand();
	maxLen[o] = 0;
	return o;
}

void Split(int o, int &a, int &b, int k){
	if(o == -1){
		a = b = -1;
		return;
	}
	pull(o);
	if(id[o] <= k){
		a = o;
		Split(r[o], r[a], b, k);
		pull(a);
		return;
	}
	b = o;
	Split(l[o], a, l[b], k);
	pull(b);
	return;
}

int Merge(int a, int b){
	if(a == -1 || b == -1) return ~a ? a : b;
	if(pri[a] < pri[b]){
		r[a] = Merge(r[a], b);
		pull(a);
		return a;
	}
	l[b] = Merge(a, l[b]);
	pull(b);
	return b;
}

void Del(int col, int id){
	Split(roots[col], a, b, id - 1);
	Split(b, c, d, id);
	roots[col] = Merge(a, d);
}

void Ins(int col, int id){
	Split(roots[col], a, b, id);
	roots[col] = Merge(a, Merge(newNode(id), b));
}

int Query(int L, int R, int col){ //0-based [L, R)
	Split(roots[col], a, b, R - 1);
	Split(a, c, d, L - 1);
	//What we want is now in root d
	int r = (~d ? maxLen[d] : R - L);
	if(~d){
        if(lMost[d] - L > r) r= lMost[d] - L;
        if(R - rMost[d] - 1 > r) r = R - rMost[d] - 1;
	}
	roots[col] = Merge(Merge(c, d), b);
	return r;
}

int main(){
	Read(N);
	Read(Q);
	Read(C);
	fill(roots, roots + (1 << C), -1);
	for(int i = 0; i < N; i++){
		Read(arr[i]);
		roots[arr[i]] = Merge(roots[arr[i]], newNode(i));
	}
	while(Q--){
		Read(com);
		if(com){ //Query
			Read(A);
			Read(B);
			Read(K);
			printf("%d\n", Query(A, B, K));
		} else { //Modification
			Read(A);
			Read(K);
			Del(arr[A], A);
			Ins(K, A);
			arr[A] = K;
		}
	}
}
