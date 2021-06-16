#include <iostream>
using namespace std;

int N, M, arr[226][226]; 

inline void solve(){
	for(int i = 1; i <= N + 1; i++) for(int j = 1; j <= M + 1; j++) arr[i][j] = 0;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) cin >> arr[i][j];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(arr[i][j]){
				cout << "X ";
				continue;
			}
			int k = 0;
			for(int dx = -1; dx <= 1; dx++){
				for(int dy = -1; dy <= 1; dy++){
					k += arr[i + dx][j + dy];
				}
			}
			cout << k << " ";
		}
		cout << endl;
	}
}

int main(){
	while(cin >> N >> M){
		solve();
	}
}
