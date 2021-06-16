#include <iostream>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 226;

int N, M, arr[maxN], l[maxN], r[maxN], pri[maxN], sz[maxN], fat[maxN], pos[maxN], seed = 101, rings, x, y, a, b, c, d, e;
bool visited[maxN];

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


inline int Rand(){
	return seed = (seed * seed + 1) % (0xdefaced);
}

inline int Sz(int x){
	return x ? sz[x] : 0;
}

inline void pull(int x){
	fat[x] = 0;
	sz[x] = 1;
	if(l[x]){
		sz[x] += sz[l[x]];
		fat[l[x]] = x;
	}
	if(r[x]){
		sz[x] += sz[r[x]];
		fat[r[x]] = x;
	}
}

int Merge(int a, int b){
	if(!a || !b) return a ? a : b;
	if(pri[a] < pri[b]){
		r[a] = Merge(r[a], b);
		pull(a);
		return a;
	}
	l[b] = Merge(a, l[b]);
	pull(b);
	return b;
}

void Split(int o, int &a, int &b, int k){
	if(!o){
		a = b = 0;
		return;
	}
	if(Sz(l[o]) + 1 <= k){
		a = o;
		Split(r[o], r[a], b, k - Sz(l[o]) - 1);
		pull(a);
	} else {
		b = o;
		Split(l[o], a, l[b], k);
		pull(b);
	}
}

inline int getRk(int x){
	int res = Sz(l[x]);
	for(int c = x; c; c = fat[c]){
		if(r[fat[c]] == c)
			res += Sz(l[fat[c]]) + 1;
	}
	return res;
}

inline int getTop(int x){
	for(int c = x;; c = fat[c]){
		if(!fat[c]) return c;
	}
}

void disp(int x){
	if(!x) return;
	disp(l[x]);
	cout << x << ", fat[x] = " << fat[x] << ", l[x] = " << l[x] << ", r[x] = " << r[x] << endl;
	disp(r[x]);
}

int main(){
	Read(N);
	Read(M);
	for(int i = 1; i <= N; i++){
		Read(arr[i]);
		pos[arr[i]] = i;
		pri[i] = Rand();
		sz[i] = 1;
	}
	for(int i = 1; i <= N; i++){
		if(visited[i]) continue;
		int t = i;
		//cout << "i = " << i << endl;
		rings++;
		visited[i] = true;
		//cout << "visited[" << i << "] = true" << endl;
		while(!visited[arr[t]]){
			Merge(getTop(t), getTop(arr[t]));
			t = arr[t];
			visited[t] = true;
		}
	}
	/*
	for(int i = 1; i <= N; i++){
		if(!fat[i]){
			disp(i);
			cout <<endl;
		}
	}
	*/
	printf("%d\n", N - rings);
	while(M--){
		Read(x);
		Read(y);
		swap(pos[x], pos[y]);
		x = pos[x];
		y = pos[y];
		//cout << "xtop = " << getTop(x) << ", ytop = " << getTop(y) << endl;
		if(getTop(x) == getTop(y)){
			rings++;
			Split(getTop(x), a, b, getRk(x));
			Merge(getTop(b), getTop(a));	
			Split(getTop(y), a, c, getRk(y));
			Split(a, a, b, 1);
			Split(c, c, d, 1);
			Merge(getTop(a), getTop(d));
			Merge(getTop(b), getTop(c));
		} else {
			rings--;
			Split(getTop(x), a, b, getRk(x));
			Merge(getTop(b), getTop(a));
			Split(getTop(y), a, b, getRk(y));
			Merge(getTop(b), getTop(a));
			Split(getTop(x), a, b, 1);
			Split(getTop(y), c, d, 1);
			Merge(getTop(Merge(getTop(c), getTop(b))), getTop(Merge(getTop(a), getTop(d))));
		}
		/*
		for(int i = 1; i <= N; i++){
			if(!fat[i]){
				cout << "fat[" << i << "] = " << fat[i] << endl;
				disp(i);
				cout <<endl;
			}
		}
		*/
		printf("%d\n", N - rings);
	}
}
