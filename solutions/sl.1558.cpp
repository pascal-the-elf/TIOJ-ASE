#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 326;
int N, d, r, ans, m[maxN], n[maxN];

inline void solve(){
	for(int i = 0; i < N; i++) cin >> m[i];
	for(int i = 0; i < N; i++) cin >> n[i];
	sort(m, m + N);
	sort(n, n + N, greater<int>());
	int ans = 0;
	for(int i = 0; i < N; i++){
		ans += (m[i] + n[i] > d ? (m[i] + n[i] - d) * r : 0);
	}
	cout << ans << endl;
}

signed main(){
	while(cin >> N >> d >> r){
		solve();
	}
}
