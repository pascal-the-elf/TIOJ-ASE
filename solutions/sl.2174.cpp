#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 3e5 + 326, INF = 1e9;
int N, M, l, r, x, tag[maxN * 4], com, ans[maxN];
bool isQue[maxN];
pii seg[maxN * 4];
vector<int> que[maxN];
vector<pii> st[maxN], ed[maxN];

inline void pull(int id){
	if(seg[2 * id + 1].F == seg[2 * id + 2].F){
		seg[id].F = seg[2 * id + 1].F;
		seg[id].S = seg[2 * id + 1].S + seg[2 * id + 2].S;
	} else if(seg[2 * id + 1].F > seg[2 * id + 2].F){
		seg[id] = seg[2 * id + 2];
	} else {
		seg[id] = seg[2 * id + 1];
	}
}

inline void push(int id, int l, int r){
	if(!tag[id]) return;
	seg[id].F += tag[id];
	if(r - l > 1){
		tag[2 * id + 1] += tag[id];
		tag[2 * id + 2] += tag[id];
	}
	tag[id] = 0;
}

void build(int id = 0, int l = 0, int r = M){
	if(l + 1 == r){
		seg[id] = {0, 1};
		tag[id] = 0;
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	pull(id);
}

void modify(int id, int l, int r, int ql, int qr, int x){
	push(id, l, r);	
	if(ql <= l && r <= qr){
		tag[id] += x;
		push(id, l, r);
		return;
	}
	if(l >= qr || ql >= r) return;
	int m = (l + r) / 2;
	modify(2 * id + 1, l, m, ql, qr, x);
	modify(2 * id + 2, m, r, ql, qr, x);
	pull(id);
}

pii query(int id, int ql, int qr, int l, int r){
	push(id, l, r);
	if(ql <= l && r <= qr) return seg[id];
	if(l >= qr || ql >= r) return {INF, 0};
	int m = (l + r) / 2;
	pii a = query(2 * id + 1, ql, qr, l, m), b = query(2 * id + 2, ql, qr, m, r);
	if(a.F == b.F) return {a.F, a.S + b.S};
	else if(a.F < b.F) return a;
	return b;
}

void disp(int id = 0, int l = 0, int r = M){
	if(l + 1 == r){
		cout << seg[id].F << " ";
		return ;
	}
	int m = (l + r) / 2;
	disp(2 * id + 1, l, m);
	disp(2 * id + 2, m, r);
}

int main(){
	ericxiao
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> com;
		if(com == 1){
			cin >> l >> r >> x;
			st[l].emplace_back(i, x);
			ed[r].emplace_back(i, x);
		} else {
			cin >> x;
			que[x].emplace_back(i);
			isQue[i] = true;
		}
	}
	build();
	for(int i = 0; i < N; i++){
		for(auto [t, v] : st[i]){
			modify(0, 0, M, t, M, v);
		}
		for(int q : que[i]){
			pii p = query(0, 0, q, 0, M);
			//cout << "{" << p.F << ", " << p.S << "}" << endl;
			ans[q] = (p.F == 0 ? p.S : 0);
		}
		//cout << "For i = " << i << ", " << endl;
		//disp();
		//cout << endl;
		for(auto [t, v] : ed[i]){
			modify(0, 0, M, t, M, -v);
		}
	}
	for(int i = 0; i < M; i++) if(isQue[i]){
		cout << ans[i] << endl;
	}
}
