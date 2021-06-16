#include <iostream>
#include <string.h>
using namespace std;

const int mxDig = 10;

int dp[mxDig][2], tenpow[mxDig], pre[mxDig], a, b;
string rep;

int getDp(int dig, bool isTight){
	if(dig == rep.length()){
		return 0;
	}
}

inline int get(int x){
	if(x < 0) return 0;
	rep = "";
	for(int i = 0; i < mxDig; i++) dp[i][0] = dp[i][1] = -1;
	int _x = x;
	while(_x){
		rep = (char)(_x % 10 + '0') + rep;
		_x /= 10;
	}
	for(int i = 0; i < mxDig; i++){
		pre[i] = stoi(rep.substr(rep.length() - i - 1, rep.length()));
		cout << "pre[" << i << "] = " << pre[i] << endl;
	}
	cout << "rep = " << rep << endl;
	return getDp(0, true);
}

int main(){
	tenpow[0] = 1;
	for(int i = 1; i < mxDig; i++) tenpow[i] = 10 * tenpow[i - 1];
	while(cin >> a >> b){
		cout << get(b) - get(a - 1) << endl;
	}
}
