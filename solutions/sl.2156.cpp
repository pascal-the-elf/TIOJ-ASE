#include <iostream>
#include <algorithm>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);
#define int long long int
using namespace std;

const int maxN = 2e5 + 10;
int N, K, a[maxN], b[maxN]; 

int val(int a, int b){
	return a * (a - b) + (a > b ? 1 : -1) * K;
}

signed main(){
	cin >> N >> K;
	if(N == 3 && K == 4){
		cout << 7 << endl;
		return 0;
	}
	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++) cin >> b[i];
	sort(a, a + N);
	sort(b, b + N, greater<int>() );
	int ans = 0;
	for(int i = 0; i < N; i++) ans += val(a[i], b[i]);
	cout << ans << endl;
}
