#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int B, N, d, x, M;

inline int Abs(int x){
	return (x < 0) ? -x : x;
}

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

struct BIT{
	vector<int> bit;
	int N;
	BIT(){}
	BIT(int N): N(N){
		bit.resize(N);
	}
	void add(int p, int x){
		for(; p < N; p += p & -p) bit[p] += x;
	}
	int res(int p){
		if(p <= 0) return 0;
		if(p >= N) return res(N - 1);
		int r = 0;
		for(; p; p -= p & -p) r += bit[p];
		return r;
	}
	int sum(int l, int r){ // [l, r]
		return res(r) - res(l - 1);
	}
};

struct BIT2D{
	vector<BIT> bit;
	int N;
	BIT2D(){}
	BIT2D(int N): N(N){
		bit.resize(N);
		for(BIT &b : bit) b = BIT(N);
	}
	void add(int x, int y, int v){
		for(; x < N; x += x & -x) bit[x].add(y, v);	
	}
	int res(int x, int y){
		if(x <= 0) return 0;
		if(x >= N) return res(N - 1, y);
		int r = 0;
		for(; x; x -= x & -x) r += bit[x].res(y);
		return r;
	}
	int sum(int a, int b, int c, int d){ //[a, c] * [b, d]
		return res(c, d) - res(c, b - 1) - res(a - 1, d) + res(a - 1, b - 1);
	}
};

struct BIT3D{
	vector<BIT2D> bit;
	int N;
	BIT3D(){}
	BIT3D(int N): N(N){
		bit.resize(N);
		for(BIT2D &b : bit) b = BIT2D(N);
	}
	void add(int x, int y, int z, int v){
		for(; x < N; x += x & -x) bit[x].add(y, z, v);	
	}
	int res(int x, int y, int z){
		if(x <= 0) return 0;
		if(x >= N) return res(N - 1, y, z);
		int r = 0;
		for(; x; x -= x & -x) r += bit[x].res(y, z);
		return r;
	}
	int sum(int a, int b, int c, int x, int y, int z){ //[a, x] * [b, y] * [c, z]
		return res(x, y, z) - res(x, b - 1, z) - res(x, y, c - 1) - res(a - 1, y, z) + res(x, b - 1, c - 1) + res(a - 1, b - 1, z) + res(a - 1, y, c - 1) - res(a - 1, b - 1, c - 1);
	}
};

struct PP{
	int x, y;
	PP(){}
	PP(int a, int b): x(a), y(b){}
};

struct PS{
	int x, y, z, w;
	PS(){}
	PS(int a, int b, int c, int d): x(a), y(b), z(c), w(d){}
};

void solve1(){
	Read(N); Read(d); Read(M);
	vector<int> cur, all;
	cur.resize(N);
	for(int i = 0; i < N; i++){
		Read(cur[i]);
	}
	sort(cur.begin(), cur.end());
	for(int x : cur) all.push_back(x);
	int l = 0, r = 0;
	long long int ans = 0;
	for(int i = 0; i < N; i++){
		while(r < N && Abs(all[r] - cur[i]) <= d) r++;
		while(l < N && Abs(all[l] - cur[i]) > d) l++;
		ans += (r - l - 1);
	}
	cout << ans / 2 << endl;
}

void solve2(){
	Read(N); Read(d); Read(M);
	BIT bit = BIT(2 * M + 5);
	vector<PP> cur, all;
	int x, y;
	for(int i = 0; i < N; i++){
		Read(x); Read(y);
		cur.emplace_back(x + y, x - y);
	}
	sort(cur.begin(), cur.end(), [](PP &a, PP &b) {
		return a.x < b.x;
	});
	for(auto p : cur) all.push_back(p);
	int l = 0, r = 0;
	long long int ans = 0;
	for(int i = 0; i < N; i++){
		while(r < N && Abs(all[r].x - cur[i].x) <= d){
			bit.add(all[r++].y + M, 1);
		}
		while(l < N && Abs(all[l].x - cur[i].x) > d){
			bit.add(all[l++].y + M, -1);
		}
		ans += bit.sum(cur[i].y + M - d, cur[i].y + M + d) - 1;
	}
	cout << ans / 2 << endl;
}

void solve3(){
	Read(N); Read(d); Read(M);
	BIT3D bit = BIT3D(4 * M + 5);
	vector<PS> cur, all;
	int x, y, z;
	for(int i = 0; i < N; i++){
		Read(x); Read(y); Read(z);
		cur.emplace_back(x + y + z, x + y - z + 2 * M, x - y + z + 2 * M, x - y - z + 2 * M);
	}
	sort(cur.begin(), cur.end(), [](PS &a, PS &b) {
		return a.x < b.x;
	});
	for(auto p : cur) all.push_back(p);
	int l = 0, r = 0;
	long long int ans = 0;
	for(int i = 0; i < N; i++){
		while(r < N && Abs(all[r].x - cur[i].x) <= d){
			bit.add(all[r].y, all[r].z, all[r].w, 1);
			r++;
		}
		while(l < N && Abs(all[l].x - cur[i].x) > d){
			bit.add(all[l].y, all[l].z, all[l].w, -1);
			l++;
		}
		ans += bit.sum(cur[i].y - d, cur[i].z - d, cur[i].w - d, cur[i].y + d, cur[i].z + d, cur[i].w + d) - 1;
	}
	cout << ans / 2 << endl;
}

int main(){
	ericxiao;
	Read(B);
	if(B == 1){
		solve1();
	} else if(B == 2){
		solve2();
	} else {
		solve3();
	}
}
