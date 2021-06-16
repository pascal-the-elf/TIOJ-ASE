#include <iostream>
#include <map>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

map<int, int> mp;
int N, pre, x, ans;

inline int Sgn(int x){
	return (x < 0) ? -1 : (x > 0) ? 1 : 0;
}

int main(){
	ericxiao;
	while(cin >> N){
		map<int,int>().swap(mp);
		pre = ans = 0;
		mp[0] = 0;
		for(int i = 1; i <= N; i++){
			cin >> x;
			pre += Sgn(x);
			if(mp.count(pre)){
				ans = max(ans, i - mp[pre]);
			} else {
				mp[pre] = i;
			}
		}
		cout << ans << endl;
	}
}
