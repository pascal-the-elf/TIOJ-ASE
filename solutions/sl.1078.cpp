#include <iostream>
#include <string.h>
#define int long long int 
using namespace std;

const int maxC = 50;

int c[maxC][maxC], M, ans, bc = 1, T;
string s;

signed main(){
	c[0][0] = 1;
	for(int i = 1; i < maxC; i++){
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	cin >> T;
	while(T--){
		ans = 0, bc = 1;
		s = "";
		cin >> M;
		while(M){
			s = (char)((M & 1) + '0') + s;
			M >>= 1;
		}
		//cout << "s = " << s << endl;
		for(int i = 1; i < s.length(); i++){
			for(int j = 0; i - j > j && j < i; j++){
				ans += c[i - 1][j];
				//cout << "Adding len = " << i << " with " << j << " 0s\n";
				//cout << i - 1 << " choose " << j << " = " << c[i - 1][j] << '\n';
			}
		}
		for(int i = 1; i < s.length(); i++){
			if(s[i] == '1'){
				//cout << "s[" << i << "] is 1" << endl;
				//cout << "to the left is " << bc << " ones and " << i - bc << " zeros " << endl;
				for(int j = 0; j <= s.length() - 1 - i && (i - bc) + j + 1 < bc + (s.length() - i - 1 - j); j++){
					ans += c[s.length() - 1 - i][j];
				}
			}
			bc += (s[i] - '0');
		}
		ans += (bc > s.length() - bc);
		//cout << s << endl;
		cout << ans << endl;

	}
}
