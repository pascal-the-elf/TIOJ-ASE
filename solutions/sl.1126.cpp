#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int short
using namespace std;

string s;

int arr[60], t;

int solve(string s){
	string ns = "$";
	for(int i = 0; i < s.length(); i++){
		ns += s[i];
		ns += '$';
	}
	s = ns;

	arr[0] = 0;
	short l = 0, r = 0, ans = 1;

	for(int i = 1; i < s.length(); i++){
		if(i > r){
			arr[i] = 0;
		} else {
			arr[i] = min(arr[l + r - i], (short)(r - i));
		}
		while(i + arr[i] < s.length() && 0 <= i - arr[i] && s[i + arr[i]] == s[i - arr[i]]) arr[i]++;
		arr[i]--;
		if(i + arr[i] >= r){
			r = i + arr[i];
			l = i - arr[i];
		}
        ans = max(ans, arr[i]);
	}
	//cout << s << endl;
	//for(int i = 0; i < s.length(); i++) cout << arr[i] << " ";
	//cout << endl;
	return ans;
}

signed main(){
    ericxiao;
    while(cin >> s){
		cout << solve(s) << '\n';
    }
}
