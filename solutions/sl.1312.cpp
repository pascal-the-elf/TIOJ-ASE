#include <iostream>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define min(a,b) (a<b?a:b)
#define int short
using namespace std;

const int maxN = 1e4 + 10;
int dsu[maxN], lead[maxN], md[maxN], N, M, k, a, b;

void Flat(int x){
	if(dsu[x] == x) return;
	Flat(dsu[x]);
	lead[x] = lead[dsu[x]];
	dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
	Flat(a);
	Flat(b);
	if(dsu[a] == dsu[b]) return;
	if(md[dsu[a]] > md[dsu[b]]) swap(a, b);
	if(md[dsu[a]] == md[dsu[b]]){
		md[dsu[a]]++;
		lead[dsu[a]] = min(lead[dsu[a]], lead[dsu[b]]);
		dsu[dsu[b]] = dsu[a];
	} else {
		lead[dsu[b]] = min(lead[dsu[a]], lead[dsu[b]]);
		dsu[dsu[a]] = dsu[b];
	}

}

signed main(){
	ericxiao;
	while(cin >> N >> M){
		iota(dsu, dsu + N + 1, 0);
		iota(lead, lead + N + 1, 0);
		fill(md, md + N + 1, 0);
		while(M--){
			cin >> a >> b;
			Merge(a, b);
		}
		cin >> k;
		Flat(k);
		cout << lead[k] << '\n';
	}
}
