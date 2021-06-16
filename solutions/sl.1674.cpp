#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 9, inv2 = 5e8 + 5;
int n, ans = 0, range;

signed main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		//cout << "From " << i << " to " << (n / (n / i))  << " has quotient " << n / i << endl;
		range = ((n / (n / i)) - i + 1) % MOD;
		//cout << "Range = " << range << endl;
		ans += ((n % MOD * range % MOD) - ((n / i) * range % MOD) * (i % MOD + (n / (n / i)) % MOD) % MOD * inv2 % MOD + MOD) % MOD;
		ans %= MOD;
		//cout << "Add: " << n * range - (n / i) * range * (i + (n / (n / i))) / 2 << endl;
		//cout << n << "/" << i << " = " << n / i  << endl;
		i = (n / (n / i));
	}
	cout << ans << endl;
}
