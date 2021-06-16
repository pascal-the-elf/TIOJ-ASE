#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 26;
string s, _s, bwt[maxN];
int N;


int main(){
	while(cin >> N){
		cin >> s;
		_s = s;
		for(int i = 0; i < N; i++){
			bwt[i] = _s;
			_s = _s.substr(1, N) + _s[0];	
		}
		sort(bwt, bwt + N);
		for(int i = 0; i < N; i++) cout << bwt[i][N - 1];
		cout << endl;
		s = s.substr(1, N) + s[0];
		for(int i = 0; i < N; i++){
			if(bwt[i] == s){
				cout << i + 1 << endl;
				break;
			}
		}
	}
}
