#include <iostream>
#include <map>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

int N, L, x, ans;
map<int, int> frq;

inline bool chk(){
	if(frq.rbegin()->S >= 2){
		return 2 * (frq.rbegin()->F) >= L;
	} else {
		return frq.rbegin()->F + prev(prev(frq.end()))->F >= L;
	}
}

inline void stp(){
	int val, amnt, a, b;
	if(frq.rbegin()->S > 1){
		val = 2 * frq.rbegin()->F, amnt = frq.rbegin()->S / 2;
		a = frq.rbegin()->F;
		ans += frq.rbegin()->S / 2;
		frq[a] &= 1;
		frq[val / 3] += (3 - val % 3) * (amnt);
		if(val % 3) frq[val / 3 + 1] += (val % 3) * (amnt);
		if(!frq[a]) frq.erase(a);
	} else {
		ans++;
		//cout << "TWO: , found " << prev(prev(frq.end()))->F << " and " <<  frq.rbegin()->F << endl;
		a = prev(prev(frq.end()))->F, b = frq.rbegin()->F;
		val = a + b;
		frq[a]--;
		frq[b]--;
		frq[val / 3] += 3 - val % 3;
		if(val % 3) frq[val / 3 + 1] += val % 3;
		if(!frq[a]) frq.erase(a);
		if(!frq[b]) frq.erase(b);
	}
}

signed main(){
	cin >> N >> L;
	for(int i = 0; i < N; i++){
		cin >> x;
		frq[x]++;
	}
	while(chk()){
		if(frq.size() >= 10000000) return 0;
		stp();	
	}
	cout << ans << '\n';
}
