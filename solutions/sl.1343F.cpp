#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int maxN = 226;

int N, T, k, x, ans[maxN], m, id, a, b, coverAt[maxN], lowDel[maxN];
bool isIn[maxN];
set<int> has[maxN], seqs[maxN], _seqs[maxN];

inline bool isPossible(int x){
	fill(lowDel, lowDel + N + 1, maxN);
	m = 0;
	ans[0] = x;
	for(int i = 0; i < N; i++) _seqs[i] = seqs[i];
	for(int r = 1; r < N; r++){
		int nxtseq = -1;
		for(int y : has[x]){
			//cout << "erasing " << x << " from seq #" << y << endl;  
			_seqs[y].erase(x);
			lowDel[y] = min(r, lowDel[y]); 
			if(_seqs[y].size() == 1 && r - lowDel[y] == seqs[y].size() - 2){
				nxtseq = y;	
			}
		}
		if(nxtseq == -1) return false;
		x = *_seqs[nxtseq].begin(); 
		ans[r] = x;
	}
	return true;
}
/*
5
2 4 5
3 1 4 5
3 1 3 5
5 1 2 3 4 5

4 5 1 3 2 

*/

inline void solve(){
	cin >> N;
	for(int i = 0; i <= N; i++){
		set<int>().swap(seqs[i]);
		set<int>().swap(has[i]);
	}
	for(int i = 0; i < N - 1; i++){
		cin >> k;
		while(k--){
			cin >> x;
			seqs[i].insert(x);
			has[x].insert(i);
		}
	}
	for(int s = 1; s <= N; s++){
		if(isPossible(s)){
			for(int i = 0; i < N; i++){
				cout << ans[i] << " \n"[i == N - 1];
			}
			return;
		}
	}
}
int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
