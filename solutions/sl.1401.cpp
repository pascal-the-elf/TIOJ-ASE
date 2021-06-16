#include <iostream>
#include <utility>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326;

int N, l[maxN], r[maxN], d[maxN], u[maxN];
vector<int> sth[maxN], stv[maxN];
inline void solve(){
	fill(sth, sth + N, vector<int>());
	fill(stv, stv + N, vector<int>());
	for(int i = 0; i < N; i++){
		cin >> l[i] >> r[i] >> d[i] >> u[i];
		sth[l[i]].push_back(i);
		stv[d[i]].push_back(i);
	}
	priority_queue<int, vector<int>, greater<int>> pqh, pqv;
	for(int i = 1; i <= N; i++){
		//cout << "i = " << i << endl;
		for(int x : sth[i]){
			pqh.push(r[x]);
		}
		for(int x : stv[i]){
			pqv.push(u[x]);
		}
		if(!pqh.size() || !pqv.size()){
			cout << "NO\n";
			return;
		}
		int h = pqh.top(); pqh.pop();
		int v = pqv.top(); pqv.pop();
		//cout << "h = " << h << ", v = " << v << endl;
		if(h < i || v < i){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	ericxiao;
	while(cin >> N){
		solve();
	}
}
