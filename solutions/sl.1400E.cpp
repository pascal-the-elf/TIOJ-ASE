#include <iostream>
using namespace std;

const int maxN = 5e3 + 326;
int vals[maxN], N;

inline int solve(int l, int r){
	//cout << "Solving: " << l << ", " << r << endl;
	int res = (r - l + 1), mn = 2e9, _r;
	for(int i = l; i <= r; i++) mn = min(mn, vals[i]);
	_r = mn;
	for(int i = l; i <= r; i++){
		vals[i] -= mn;
	}
	int cl = -1, cr = -1;
	for(int i = l; i <= r; i++){
		if(!vals[i] && cl != -1){
			_r += solve(cl, cr);	
			cl = cr = -1;
		}
		if(vals[i] && cl == -1){
			cl = cr = i;
		} else {
			cr = i;
		}
	}
	if(cl != -1) _r += solve(cl, cr);
	return min(res, _r);
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> vals[i];
	}
	cout << solve(0, N - 1) << endl;
}
