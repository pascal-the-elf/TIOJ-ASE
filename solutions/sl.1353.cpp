#include <iostream>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 226;

int pf[maxN];

void sieve(){
	for(int i = 2; i < maxN; i++){
		if(!pf[i]){
			for(int j = i; j < maxN; j += i) pf[j]++;
		}
	}
}

struct ZCK{
	ZCK(){}
	pii seg[maxN * 2];
	void init(){
		for(int i = maxN; i < maxN * 2; i++) seg[i] = {pf[i - maxN], -i};	
		for(int i = maxN - 1; i; i--){
			seg[i] = max(seg[(i << 1)], seg[(i << 1) | 1]);	
		}
	}
	pii query(int l, int r){
		pii res = {-1, -1};
		for(l += maxN, r += maxN; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = max(res, seg[l++]);
			if(r & 1) res = max(res, seg[--r]);
		}
		return res;
	}
} rmq;

int l, r;

int main(){
	ericxiao;
	sieve();
	rmq.init();
	while(cin >> l >> r){
		auto [fc, n] = rmq.query(l, r + 1);
		cout << -(maxN + n) << " " << fc << endl;
	}
}

