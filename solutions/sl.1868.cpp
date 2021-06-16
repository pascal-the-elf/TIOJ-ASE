#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5 + 226;
int N, K, val[maxN], lft[maxN], rgt[maxN];
int canReach[maxN];
string status;

inline int pre(int l, int r){
	return canReach[r] - ( l ? canReach[l - 1] : 0 );
}
int main(){
	ericxiao;
	cin >> N >> K;	
	K--;
	for(int i = 0; i < N; i++) {
		cin >> val[i];
	}
	cin >> status;
	for(int i = 0; i < N; i++){
		if(status[i] == 'T' && !canReach[i]){
			canReach[i] = 1;
			for(int j = i + 1; j < N; j++){
				if(!canReach[j] && val[j] >= val[j - 1]){
					canReach[j] = 1;			
				} else break;
			}
			for(int j = i - 1; j >= 0; j--){
				if(!canReach[j] && val[j] >= val[j + 1]){
					canReach[j] = 1;			
				} else break;
			}
		}
	}
	lft[0] = rgt[N - 1] = 1;
	for(int i = 1; i < N; i++){
		lft[i] = (val[i] >= val[i - 1] ? lft[i - 1] + 1 : 1);	
		canReach[i] += canReach[i - 1];
	}
	for(int i = N - 2; i >= 0; i--){
		rgt[i] = (val[i] >= val[i + 1] ? rgt[i + 1] + 1 : 1);	
	}
	/*
	for(int i = 0; i < N; i++) cout << canReach[i] << " \n"[i == N - 1];
	for(int i = 0; i < N; i++) cout << lft[i] << " \n"[i == N - 1];
	for(int i = 0; i < N; i++) cout << rgt[i] << " \n"[i == N - 1];
	*/
	//for(int i = 0; i < N; i++) cout << canReach[i] << " ";
	//cout << endl;
	if(!pre(K, K)){	
		int gol = lft[K], gor = rgt[K];
		for(int i = K + 1; i < N && val[i] == val[K]; i++, gol++);
		for(int i = K - 1; i >= 0 && val[i] == val[K]; i--, gor++);
		cout << max(gol, gor) << endl;
		return 0;
	}
	int cur = !canReach[0], finalAns = cur;
	for(int i = 1; i < N; i++){
		if(pre(i, i)) continue;
		if(!(pre(i - 1, i - 1)) && val[i] >= val[i - 1]) cur++;
		else cur = 1;
		//cout << "i = " << i << "lcur = " << cur << endl;
		finalAns = max(cur, finalAns);
	}
	cur = !pre(N - 1, N - 1);
	finalAns = max(cur, finalAns);
	for(int i = N - 2; i >= 0; i--){
		if(pre(i, i)) continue;
		if(!(pre(i + 1, i + 1)) && val[i] >= val[i + 1]) cur++;
		else cur = 1;
		//cout << "i = " << i << "rcur = " << cur << endl;
		finalAns = max(cur, finalAns);
	}
	cout << finalAns + canReach[N - 1] << endl;
}
