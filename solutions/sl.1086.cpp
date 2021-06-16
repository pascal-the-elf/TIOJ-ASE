#include <iostream>
#define int long long int
using namespace std;

int ans[26], N;

signed main(){
	ans[1] = 0;
	ans[2] = 1;
	for(int i = 3; i <= 20; i++){
		ans[i] = (i - 1) * (ans[i - 1] + ans[i - 2]);
	}
	while(cin >> N){
		if(!N) return 0;
		cout << ans[N] << '\n';
	}
}
