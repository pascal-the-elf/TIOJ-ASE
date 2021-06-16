#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);

#define int long long int
using namespace std;

int N, c, a, r, d, has[3][16], bitmask, twoway[16], hastroop[3];
int ans;


signed main(){
	ericxiao;
	cin >> N;
	while(N--){
		cin >> c >> a >> r >> d; 
		c--;
		has[c][a * 4 + r * 2 + d]++;
	}
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			for(int k = 0; k < 8; k++){
				if((i | j | k) != 7) continue;	
				ans += has[0][i] * has[1][j] * has[2][k];
			}
		}
	}
	cout << ans << endl;
}
