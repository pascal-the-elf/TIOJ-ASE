#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<pii> dolls;
int N, T, h, w;

int main(){
	ericxiao;
	cin >> T;
	while(T--){
		cin >> N;
		dolls.resize(N);
		for(int i = 0; i < N; i++){
			cin >> h >> w;
			dolls[i] = {h, w};
		}
		sort(dolls.begin(), dolls.end(), [](const pii a, const pii b){
			if(a.F == b.F) return a.S > b.S;
			return a.F < b.F;
		});
		vector<int> lis;
		lis.resize(N + 1);
		fill(lis.begin(), lis.end(), (int)(1e6));
		for(pii p : dolls){
			*lower_bound(lis.begin(), lis.end(), p.S) = p.S;
		}
		cout << lower_bound(lis.begin(), lis.end(), (int)(1e6)) - lis.begin() << '\n';
	}

}
