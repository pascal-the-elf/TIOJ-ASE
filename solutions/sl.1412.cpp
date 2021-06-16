#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long int
using namespace std;


const int maxN = 1005;
int N, price[maxN], peran, mostAt, need[maxN], needan, lft, ans, sum, maxBuy;

signed main(){
	ericxiao;
	while(cin >> N){
		peran = mostAt = needan = lft = ans = sum = maxBuy = 0;
		for(int i = 0; i < N; i++){
			cin >> price[i];
			sum += price[i];
			if(price[i] > price[mostAt]) mostAt = i;
		}
		cin >> peran;
		for(int i = 0; i < N; i++){
			cin >> need[i];
			maxBuy = max((price[i] + need[i] - 1) / price[i], maxBuy);
		}
		for(int i = 0; i < N; i++){
			lft += price[i] * maxBuy - need[i];
		}
		cin >> needan;
		ans = maxBuy;
		//cout << "lft = " << lft << endl;
		//cout << "mxby = " << maxBuy << endl;
		ans += max(0LL, (needan * peran - lft + sum - 1) / sum); 
		cout << ans << endl;
	}
}
