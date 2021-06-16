#include <iostream>
#include <string.h>
using namespace std;

int frq[26], has[26], N;
string s;

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		fill(has, has + 26, 0);
		cin >> s;
		for(char c : s) has[c - 'a'] = 1;
		for(int i = 0; i < 26; i++) frq[i] += has[i];
	}
	for(int i = 0; i < 26; i++){
		if(frq[i] == N){
			cout << (char)('a' + i) << endl;
			return 0;
		}
	}
	cout << "7122\n";
}
