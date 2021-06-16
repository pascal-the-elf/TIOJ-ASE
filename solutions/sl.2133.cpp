#include <iostream>
#include <string>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int short
using namespace std;

int arr[(int)1e4 + 326];
string o, s;

inline void solve(){
	cin >> s;
	o = "";
	for(char c : s){
		o += '$';
		o += c;
	}
	o += '$';	
	swap(o, s);
	fill(arr, arr + s.length() + 1, 0);
	int l = -1, r = -1, m = 1;
	for(int i = 1; i < s.length(); i++){
		if(i > r){
			arr[i] = 0;
		} else {
			arr[i] = min(arr[l + r - i], (int)(r - i));
		}
		while(i + arr[i] + 1 < s.length() && (i - arr[i] - 1) >= 0){
			if(s[i + arr[i] + 1] != s[i - arr[i] - 1]) break;
			arr[i]++;
		}
		if(r < i + arr[i]){
			l = i - arr[i];
			r = i + arr[i];
		}
		m = max(m, arr[i]);
	}
	//for(int i = 0; i < s.length(); i++) cout << s[i] << " \n"[i == s.length() - 1];
	//for(int i = 0; i < s.length(); i++) cout << arr[i] << " \n"[i == s.length() - 1];
	cout << m << endl;
}

signed main(){
	ericxiao;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
