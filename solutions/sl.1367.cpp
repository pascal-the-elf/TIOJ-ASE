#include <iostream>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 5e4 + 326;
int N, ans, A[maxN], B[maxN];

signed main(){
	ericxiao;
	while(cin >> N){
		for(int i = 0; i < N; i++) cin >> A[i];
		for(int i = 0; i < N; i++) cin >> B[i];
		sort(A, A + N);
		sort(B, B + N);
		ans = 0;
		for(int i = 0; i < N; i++){
			ans += A[i] * B[N - i - 1];
		}
		cout << ans << endl;
	}
}
