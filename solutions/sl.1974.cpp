#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 2e5 + 226;

int horpre[maxN], vertpre[maxN];

struct RMQ{
    int seg[maxN * 4], tag[maxN * 4]; 
    RMQ(){}
    inline void push(int id, int l, int r){
        seg[id] += tag[id];
        if(l + 1 < r){
            tag[2 * id + 1] += tag[id];
            tag[2 * id + 2] += tag[id];
        }
        tag[id] = 0;
    }
    inline void pull(int id){
        seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
    }
    void build(int id, int l, int r){
        tag[id] = 0;
        if(l + 1 == r){
            seg[id] = horpre[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * id + 1, l, m);
        build(2 * id + 2, m, r);
        pull(id);
    }
	void modify(int id, int ql, int qr, int l, int r, int val){
		push(id, l, r);
		if(ql >= r || l >= qr) return;
		if(ql <= l && r <= qr){
			tag[id] += val;
			push(id, l, r); 
			return;
		}
		int m = (l + r) / 2;
		modify(2 * id + 1, ql, qr, l, m, val);
		modify(2 * id + 2, ql, qr, m, r, val);
		pull(id);
	}
	int query(int id, int ql, int qr, int l, int r){
		push(id, l, r);
		if(ql >= r || l >= qr) return -1;
		if(ql <= l && r <= qr) return seg[id];
		int m = (l + r) / 2;
		return max(query(2 * id + 1, ql, qr, l, m), query(2 * id + 2, ql, qr, m, r));
	}
	void show(int l, int r, int lim){
		for(int i = l; i < r; i++){
			cout << query(0, i, i + 1, 0, lim) << " "; 
		}
		cout << endl;
	}
};

struct Rect{
	int l, d, r, u, w;
	Rect(){}
	Rect(int l, int d, int r, int u, int w): l(l), d(d), r(r), u(u), w(w){}
};

struct Seg{
	int y, l, r, w;
	Seg(){}
	Seg(int y, int l, int r, int w): y(y), l(l), r(r), w(w){}
	bool operator<(const Seg s) const {
		return y < s.y;
	}
};

vector<Rect> rects;
vector<Seg> segs;
vector<int> xs, ys;
int l, d, r, u, w, n, m;

signed main(){
	ericxiao;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> l >> d >> r >> u >> w;
		rects.emplace_back(l, d, r, u, w);
		xs.push_back(l);
		xs.push_back(r);
		ys.push_back(u);
		ys.push_back(d);
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	int xsz = unique(xs.begin(), xs.end()) - xs.begin();
	int ysz = unique(ys.begin(), ys.end()) - ys.begin();
	for(Rect &r : rects){
		r.l = lower_bound(xs.begin(), xs.begin() + xsz, r.l) - xs.begin();
		r.r = lower_bound(xs.begin(), xs.begin() + xsz, r.r) - xs.begin();
		r.u = lower_bound(ys.begin(), ys.begin() + ysz, r.u) - ys.begin();
		r.d = lower_bound(ys.begin(), ys.begin() + ysz, r.d) - ys.begin();
		//cout << "Got: l, d, r, u  = " << r.l << ", " << r.d << ", " << r.r << ", " << r.u << endl;
		//cout << "Weight = " << r.w << endl;
		horpre[r.l] += r.w;
		horpre[r.r + 1] -= r.w;
		vertpre[r.d] += r.w;
		vertpre[r.u + 1] -= r.w;
		segs.emplace_back(r.d, r.l, r.r, -r.w);
		segs.emplace_back(r.u + 1, r.l, r.r, r.w);
	}
	sort(segs.begin(), segs.end());
	for(int i = 1; i <= xsz; i++) horpre[i] += horpre[i - 1];
	for(int i = 1; i <= ysz; i++) vertpre[i] += vertpre[i - 1];
	RMQ rmq = RMQ();
	//for(int i = 0; i <= xsz; i++) cout << horpre[i] << " ";
	//cout << endl;
	//cout << "Going to build" << endl;
	rmq.build(0, 0, xsz);
	//cout << "Done building " << endl;
	int cnt = 0, ans = 0;
	for(int i = 0; i <= ysz; i++){
		while(cnt < segs.size() && segs[cnt].y == i){
			//cout << "y = " << i << endl;
			//cout << "Modify: " << segs[cnt].l << ", " << segs[cnt].r << ": " << segs[cnt].w << endl;
			rmq.modify(0, segs[cnt].l, segs[cnt].r + 1, 0, xsz, segs[cnt].w);
			cnt++;
		}
		//cout << "Seg: " << endl;
		//rmq.show(0, xsz + 1, xsz);
		
		ans = max(ans, vertpre[i] + rmq.query(0, 0, xsz, 0, xsz));
	}
	cout << ans << endl;
}
