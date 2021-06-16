#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e4 + 226, INF = 2e9;
int val[maxN], N;
vector<int> ans;

struct ZCK{
	pii seg[maxN * 2];
	ZCK(){}
	void build(){
		for(int i = N; i < 2 * N; i++) seg[i] = {val[i - N], i - N};
		for(int i = N - 1; i > 0; i--) seg[i] = min(seg[2 * i], seg[2 * i + 1]);
	}
	pii query(int l, int r){
		pii res = {INF, -1};	
		for(l += N, r += N; l < r; l >>= 1, r >>= 1){
			if(l & 1){
				res = min(res, seg[l++]);	
			}
			if(r & 1){
				res = min(res, seg[--r]);
			}
		}
		return res;
	}
	void reset(){
		for(int i = 0; i < 2 * N; i++) seg[i] = {0, 0};
	}
} rmq;

void run(int l = 0, int r = N){
	if(l >= r) return;	
	pii res = rmq.query(l, r);	
	//cout << "For l = " << l << ", r = " << r << ", res = (" << res.F << ", " << res.S << ")" << endl;
	ans.push_back(res.F);
	run(l, res.S);
	run(res.S + 1, r);
}

int main(){
	while(cin >> N){
		if(!N) return 0;
		for(int i = 0; i < N; i++) cin >> val[i];
		vector<int>().swap(ans);
		rmq.reset();
		rmq.build();
		run();
		for(int i = 0; i < N - 1; i++) cout << ans[i] << " ";
		cout << ans[N - 1] << endl;
	}
}
