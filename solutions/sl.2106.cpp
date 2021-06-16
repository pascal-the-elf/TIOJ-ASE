#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> sides;

int T, N;

inline void solve(){
	cin >> N;
	sides.resize(N);
	for(int i = 0; i < N; i++) cin >> sides[i];
	sort(sides.begin(), sides.end());
	double s = 0;
	for(int i = 0; i < N - 1; i++) s += sides[i];
	if(sides[0] < 0){
		cout << "Yes\n";
		return;
	}
	cout << (s > sides[N - 1] ? "No" : "Yes") << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}

