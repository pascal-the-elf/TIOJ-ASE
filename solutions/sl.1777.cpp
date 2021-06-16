#include <iostream>
//#define int __int128
#define int long long int
using namespace std;

string _L, _R, _pos, _dir;
int L, R, pos, dir, ans = 0;
signed N;
inline int toInt(string s){
	int res = 0;
	for(char c : s){
		res = res * 10 + (c - '0');
	}
	return res;
}

inline string toStr(int x){
	string res = "";
	while(x){
		res = (char)((x % 10) + '0') + res;
		x /= 10;
	}
	return res;
}

signed main(){
	cin >> N >> _L >> _R;
	L = toInt(_L);
	R = toInt(_R);
	while(N--){
		cin >> _pos >> _dir;
		pos = toInt(_pos);
		dir = toInt(_dir);
		if(dir == 1){
			ans = max(ans, pos - L);
		} else if(dir == 2) {
			ans = max(ans, R - pos);
		} else {
			ans = max(ans, min(pos - L, R - pos));
		}
	}
	cout << toStr(ans) << endl;
}
