#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 226250, base = 131, MOD = 1e9 + 7;
string s;

inline int add(int a, int b){
	return (a + b > MOD ? a + b - MOD : a + b);
}

inline int sub(int a, int b){
	return (a - b < 0 ? a - b + MOD : a - b);
}

int modpow(int b, int e){
	if(!b) return 0;
	if(!e) return 1;
	int res = modpow(b, e/2);
	res = res * res % MOD;
	if(e % 2) res = res * b % MOD;
	return res;
}

inline int inv(int x){
	return modpow(x, MOD - 2);
}

int solve(string s){
	static int hsh[maxN];
	s = '$' + s;
	hsh[0] = 0;
	//cout << "Running hash " << endl;
	for(int i = 1; i < s.length(); i++){
		//cout << "running hsh[" <<  i << "] " << endl;
		hsh[i] = add(hsh[i - 1] * base % MOD, s[i]); 
	}
	int ma = 0, sl = s.length();
	for(int l = 0; l * 2 < s.length(); l++){
		if(sub(hsh[sl - 1], hsh[sl - 1 - l] * modpow(base, l) % MOD) == sub(hsh[sl - l - 1], hsh[sl - 1 - 2 * l] * modpow(base, l) % MOD))
			ma = l;
	}
	return ma;
}

signed main(){
	while(cin >> s){
		cout << solve(s) << '\n';
	}
}



