#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 6e4 + 10, INF = 1e9;

int T, N, Q, com, l, r, c, v, qc, ans[maxN], arr[maxN];
vector<int> lis;

struct Obj{
	int l, r, type, val, id;
	Obj(int l, int r, int type, int val, int id): l(l), r(r), type(type), val(val), id(id){}
	Obj(){}
};

struct BIT{
	int arr[maxN], n;
	vector<pii> ops;
	BIT(int nval): n(nval){
		ops.clear();
		fill(arr, arr + n, 0);
	}
	BIT(){}
	void modify(int p, int x){
		ops.emplace_back(p, x);
		for(;p <= n; p += (p & -p)) arr[p] += x;
	}
	int query(int p){
		int r = 0;
		for(; p > 0; p -= (p & -p)) r += arr[p];
		return r;
	}
	void undo(){
		int p, x;
		for(pii op : ops){
			p = op.F;
			x = -op.S;
			for(;p <= n; p += (p & -p)) arr[p] += x;
		}
		vector<pii>().swap(ops);
	}
} bit;

void total_bs(int l, int r, vector<Obj> objs){
	//cout << "Running total bs of " << l << ", " << r << endl;
	if(!objs.size()) return;
	if(l + 1 == r){
		for(Obj obj : objs){
			if(obj.type == 1){
				ans[obj.id] = l;
			}
		}
		return; 
	}
	vector<Obj> lft, rgt;
	int m = (l + r) / 2, smallerthan;
	for(Obj &obj : objs){
		//cout << "Looking at obj: type = " << obj.type << ", (l r) = " << obj.l << " " << obj.r << ", val = " << obj.val << endl;
		if(obj.type == 1){
			smallerthan = bit.query(obj.r) - bit.query(obj.l - 1);
			//cout << "SmallerThan = " << smallerthan << endl;
			if(smallerthan < obj.val){
				obj.val -= smallerthan;
				rgt.push_back(obj);
			} else {
				lft.push_back(obj);
			}
		} else if(obj.type == 2){
			if(obj.val < m){
				//cout << "Adding at " << obj.l << endl;
				bit.modify(obj.l, obj.r);
				lft.push_back(obj);
			} else {
				rgt.push_back(obj);
			}
		}
	}
	bit.undo();
	total_bs(l, m, lft);
	total_bs(m, r, rgt);
}

vector<Obj> queries;

int main(){
	ericxiao;
	cin >> T;
	while(T--){
		cin >> N >> Q;
		bit = BIT(N + 1);
		lis.clear();
		queries.clear();
		qc = 0;
		for(int i = 1; i <= N; i++){
			cin >> v;
			arr[i] = v;
			lis.push_back(v);
			queries.emplace_back(i, 1, 2, v, -1);
		}
		for(int i = 0; i < Q; i++){
			cin >> com;
			if(com == 1){
				cin >> l >> r >> c;
				queries.emplace_back(l, r, 1, c, qc++);
			} else if(com == 2){
				cin >> c >> v;
				lis.push_back(v);
				queries.emplace_back(c, -1, 2, arr[c], -1);
				queries.emplace_back(c, 1, 2, v, -1);
				arr[c] = v;
			} else if(com == 3) {
				cin >> l >> r;
				qc++;
			}
		}
		sort(lis.begin(), lis.end());
		for(Obj  &q : queries){
			if(q.type == 2){
				q.val = lower_bound(lis.begin(), lis.end(), q.val) - lis.begin() + 1;
				//cout << "q: modify at " << q.l << ", now value = " << q.val << endl;
			}
		}
		fill(ans, ans + qc, 0);
		total_bs(1, N + Q + 1, queries);
		for(int i = 0; i < qc; i++){
			//cout << "ans[" << i << "] = " << ans[i] << endl;
			cout << (!ans[i] ? 7122 : lis[ans[i] - 1])  << '\n'; 
		}
	}
}
/*
5 3
1 2 6 4 5
1 3 4 1
2 1 3
1 1 1 1
*/
