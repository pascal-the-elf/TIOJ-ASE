#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;

const int INF = 1e17;

int N, ans = INF, x, sum = 0;
vector<int> l, r, lef, rig;

inline bool hasBit(int i, int j){
	return (i & (1 << j)) > 0;
}

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x;
		sum += x;
		(i < N / 2 ? l : r).push_back(x);
	}
	int s = 0;
	for(int i = 0; i < (1 << l.size()); i++){
		s = 0;
		for(int j = 0; j < l.size(); j++){
			s += hasBit(i, j) * l[j];
		}
		lef.push_back(s);
	}
	for(int i = 0; i < (1 << r.size()); i++){
		s = 0;
		for(int j = 0; j < r.size(); j++){
			s += hasBit(i, j) * r[j];
		}
		rig.push_back(s);
	}
	sort(lef.begin(), lef.end());
	sort(rig.begin(), rig.end());
	for(int S : lef){
		if(3 * S < sum) continue;
		int T = *lower_bound(rig.begin(), rig.end(), (sum - S) / 2);
		if(T < N - 2 * S) continue;
		//cout << "S = " << S << ", T = " << T << endl;
		ans = min(ans, S - T);
	}
	for(int S : rig){
		if(3 * S < sum) continue;
		int T = *lower_bound(lef.begin(), lef.end(), (sum - S) / 2);
		if(T < N - 2 * S) continue;
		//cout << "S = " << S << ", T = " << T << endl;
		ans = min(ans, S - T);
	}
	cout << ans << endl;
}
