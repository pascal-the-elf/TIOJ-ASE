#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 1e5 + 226;
int T, N, K, arr[maxN], l, r, t[3];

bool cov(int st, int len){
	bool cl = false, cr = false;
	for(int i = 0; i < len; i++){
		if(i + st == l) cl = true;
		if(i + st == r) cr = true;
	}
	return (cl && cr);
}
signed main(){
	cin >> T;
	while(T--){
		cin >> N >> K;
		if(N == 1){
			int x;
			cin >> x;
			cout << (x == K ? "Yes" : "No") << endl;
			continue;
		}
		l = N;
		r = -1;
		for(int i = 0; i < N; i++){
			cin >> arr[i];
			if(arr[i] == K){
				r = i;
				l = (l == N ? i : l);
			}
		}
		if(r == -1){
			cout << "No" << endl;
			continue;
		}
		bool eureka = false;
		for(int i = 0; i + 2 <= N; i++){
			if(min(arr[i], arr[i + 1]) == K || (min(arr[i], arr[i + 1]) > K && !cov(i, 2))){
				cout << "Yes" << endl;
				eureka = true;
				break;
			}
			if(i + 3 <= N){
				for(int j = 0; j < 3; j++) t[j] = arr[i + j];
				sort(t, t + 3);
				if(t[1] == K || (t[1] > K && !cov(i, 3))){
					cout << "Yes" << endl;
					eureka = true;
					break;
				}
			}
		}
		if(!eureka) cout << "No" << endl;
	}
}

