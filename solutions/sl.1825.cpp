#include <iostream>
#include <string.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	for(char c = 'A'; c <= 'Z'; c++){
		int x = 10000, e = -1;
		for(int i = 0; i < (int)s.length(); i++){
			if(c == s[i]){
				x = min(i, x);
				e = max(i, e);
			}
		}
		if(~e) cout << (char)(c) << ":" << x + 1 << "," << e + 1 << endl;
	}
}
