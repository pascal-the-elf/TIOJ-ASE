#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 26;

int T, y, x, N, M;
string s, mp[maxN], ans;


inline void solve(){
	cin >> N >> M;
	mp[0] = mp[N + 1] = "";
	for(int i = 0; i <= M + 1; i++){
		mp[0] += '#';
		mp[N + 1] += '#';
	}
	for(int i = 1; i <= N; i++){
		cin >> mp[i];
		mp[i] = '#' + mp[i] + '#';
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(mp[i][j] == 'S'){
				y = i;
				x = j;
			}
		}
	}
	
	ans = "";
	while(mp[y][x] != 'T'){
		mp[y][x] = '#';
		if(mp[y + 1][x] != '#'){
			ans += 'D';
			y++;
		} else if(mp[y - 1][x] != '#'){
			ans += 'U';
			y--;
		} else if(mp[y][x + 1] != '#'){
			ans += 'R';
			x++;
		} else if(mp[y][x - 1] != '#'){
			ans += 'L';
			x--;
		}

	}
	cout << ans << '\n';
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
