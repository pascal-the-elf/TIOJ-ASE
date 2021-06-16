#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;


int t, a, b, c, d, p, q, r, w, ans = 0, tots[1001 * 1001 + 100], m;
//f(s,t,u,v)=asp+btq+cur+dvw

inline int exp(int b, int e){
	if(e == 1) return b;
	if(e == 2) return b * b;
	if(e == 3) return b * b * b;
}

signed main(){
	cin >> t;
	while(t--){
		ans = m = 0;
		cin >> a >> b >> c >> d >> p >> q >> r >> w;
		for(int s = 0; s <= 1000; s++){
			for(int t = 0; t <= 1000; t++){
				tots[m++] = a * exp(s, p) + b * exp(t, q);
			}
		}
		sort(tots, tots + m);
		for(int u = 0; u <= 1000; u++){
			for(int v = 0; v <= 1000; v++){
				int val = -1 * (c * exp(u, r) + d * exp(v, w));
				ans += upper_bound(tots, tots + m, val) - lower_bound(tots, tots + m, val);
			}
		}
		cout << ans << endl;
	}
}
