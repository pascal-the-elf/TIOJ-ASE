#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e6 + 10;
int K, fail[maxN], q, ans = 0;
string s;

int main(){
	ericxiao;
	cin >> K >> s;
	fail[0] = -1;
	for(int i = 1; i < s.length(); i++){
		q = fail[i - 1];
		while(q >= 0 && s[i] != s[q + 1]) q = fail[q];
		if(s[i] == s[q + 1]) q++;
		fail[i] = q;
		if(fail[i] != -1 && (i + 1) % (i - fail[i]) == 0 && (i - fail[i]) / (i + 1) % K == 0){
			ans = i;
		}

	}
	cout << (ans + 1) / K << endl;
}
