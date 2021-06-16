#include <iostream>
using namespace std;

const int maxN = 2e6;
int T, M, pay[maxN], take[maxN], my[5], oth[5], vals[5] = {1, 5, 10, 20, 50};

inline void solve(){
	cin >> M;
	int myMon = 0, othMon = 0, coins = 0;
	for(int i = 0; i < 5; i++) { 
		cin >> my[i];
		coins += my[i];
		myMon += my[i] * vals[i];
	}
	for(int i = 0; i < 5; i++) { 
		cin >> oth[i];
		othMon += oth[i] * vals[i];
	}
	//cout << "MyMon = " << myMon << ", oth = " << othMon << endl;
	fill(pay, pay + myMon + 1, -maxN);
	fill(take, take + othMon + 1, maxN);
	pay[0] = 0;
 	take[0] = 0;
	for(int i = 0; i < 5; i++){
		int k = 1;
		while(my[i]){
			int t = min(k, my[i]);
			for(int j = myMon; j >= t * vals[i]; j--){
				pay[j] = max(pay[j], pay[j - t * vals[i]] + t);	
			}
			my[i] -= t;
			k *= 2;
		}
	}
	for(int i = 0; i < 5; i++){
		int k = 1;
		while(oth[i]){
			int t = min(k, oth[i]);
			for(int j = othMon; j >= t * vals[i]; j--){
				take[j] = min(take[j], take[j - t * vals[i]] + t);	
			}
			oth[i] -= t;
			k *= 2;
		}
	}
	
	int ans = maxN;
	for(int i = M; i <= myMon && (i - M) <= othMon; i++){ 
		if(pay[i] == -maxN || take[i - M] == maxN) continue;
		ans = min(ans, coins -pay[i] + take[i - M]);
	}
	cout << ans << endl;
}
int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
