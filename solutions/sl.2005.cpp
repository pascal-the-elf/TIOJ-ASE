#include <iostream>
#include <vector>
#define int long long int
#define vv vector<vector<int> >
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, M;
const vv I = {
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1}
};

inline int add(int a, int b){
	return (a + b >= M ? a + b - M : a + b);
}

inline int sub(int a, int b){
	return (a - b < 0 ? a - b + M : a - b);
}

vv operator*(vv a, vv b){
	vv r;
	r.resize(a.size());
	for(int i = 0; i < a.size(); i++){
		r[i].resize(b[0].size());
		for(int j = 0; j < b[0].size(); j++){
			r[i][j] = 0;
			for(int k = 0; k < a[0].size(); k++){
				r[i][j] = add(r[i][j], a[i][k] * b[k][j] % M);
			}
		}
	}
	return r;
}

vv operator ^ (vv v, int e){
	if(!e) return I;
	if(e == 1) return v;
	vv res = v ^ (e/2);
	res = res * res;
	if(e % 2) res = res * v;
	return res;
}

void show(vv vc){
	for(vector<int> v : vc){
		for(int x : v){
			cout << x << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int solve(int N, int M){
	int d = 1, val = 1;
	vv vals = {
		{0},
		{0},
		{1}
	}, MATRIX;
	for(int digits = 1; N; digits++){
		d *= 10;
		MATRIX = {
			{d % M, 1, 1},
			{0, 1, 1},
			{0, 0, 1}
		};
		int exponent = min(d - d/10, N);
		//cout << "Exp to pow = " << exponent << endl;
		MATRIX = MATRIX ^ exponent;
		vals = MATRIX * vals;
		N -= exponent;
	}
	return vals[0][0];
}

signed main(){
	ericxiao;
	while(cin >> N >> M){
		cout << solve(N, M) << '\n';
	}
}
