#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326;
int N, ans, cnt = 2;
string s[maxN];

int main(){
	ericxiao;
	cin >> N;
	for(int i = 0; i < N; i++) cin >> s[i];
	sort(s, s + N);
	ans = s[0].length() + 1;
	for(register int i = 1; i < N; i++){
		short d = s[i - 1].length();
		for(register int j = 0; j < min(s[i - 1].length(), s[i].length()); j++){
			if(s[i - 1][j] != s[i][j]) break;
			d--;
		}
		ans += d;
		ans += s[i].length() - (s[i - 1].length() - d) + 1;
	}
	ans += s[N - 1].length();
	cout << ans << endl;
}
