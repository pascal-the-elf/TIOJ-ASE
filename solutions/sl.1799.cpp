#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 5e6 + 326;
int N, avg, ans, c;
vector<int> vals;

inline int Abs(int x){
	return x < 0 ? -x : x;
}

inline int solve(vector<int> vals){
	int r = 0; 
	//for(int x : vals) cout << x << " ";
	//cout << endl;
	for(int i = 0; i < N - 1; i++){
		r += Abs(vals[i] - avg);
		vals[i + 1] += vals[i] - avg; 
	}
	return r;
}

signed main(){
	cin >> N;
	vals.resize(N);
	for(int i = 0; i < N; i++){
		cin >> vals[i];
		avg += vals[i];
	}
	avg /= N;
	ans = solve(vals);
	int r = Abs(vals[0] - avg); 
	vals[0] = avg;
	vals[vals.size() - 1] += vals[0] - avg; 
	ans = min(ans, solve(vals) + r);
	cout << ans << endl;
}
