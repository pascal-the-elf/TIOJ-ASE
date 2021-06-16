#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e3 + 326, maxLog = 13;
int T, N, arr[maxN], pos[maxN], ans, sparse[maxLog][maxN][2], l2[maxN];

inline void buildSparse(){
	for(int i = 1; i <= N; i++) sparse[0][i][0] = sparse[0][i][1] = arr[i];
	for(int i = 1; i < maxLog; i++){
		for(int j = 1; j + (1 << i) - 1 <= N; j++){
			sparse[i][j][0] = min(sparse[i - 1][j][0], sparse[i - 1][j + (1 << (i - 1))][0]);
			sparse[i][j][1] = max(sparse[i - 1][j][1], sparse[i - 1][j + (1 << (i - 1))][1]);
		}
	}
}

int getLog(int x){
	int orix = x;
	while(true){
		if(x == (x & -x)){
			return l2[x];
		}
		x -= x & -x;
	}
}

inline int getMax(int l, int r){
	if(l > r) swap(l, r);
	int k = getLog(r - l + 1);	
	return max(sparse[k][l][1], sparse[k][r - (1 << k) + 1][1]);
}

inline int getMin(int l, int r){
	if(l > r) swap(l, r);
	int k = getLog(r - l + 1);	
	return min(sparse[k][l][0], sparse[k][r - (1 << k) + 1][0]);
}

inline int Abs(int x){
	return x < 0 ? -x : x;
}

inline void solve(){
	cin >> N;
	ans = 0;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		pos[arr[i]] = i;
	}
	buildSparse();
	for(int l = 1; l <= N; l++){
		for(int r = l + 1; r <= N; r++){
			if(Abs(pos[r] - pos[l]) + 1 != r - l + 1) continue;
			//cout << "l = " << l << ", r = " << r << endl;
			//cout << "min of pos = " << getMin(pos[l], pos[r]) << " max = " << getMax(pos[l], pos[r]) << endl;
			if(getMax(pos[l], pos[r]) != r || getMin(pos[l], pos[r]) != l) continue;
			ans++;
		}
	}
	cout << ans << endl;
}

int main(){
	ericxiao
	for(int i = 0; i < maxLog; i++) l2[(1 << i)] = i;
	int x;
	cin >> T;
	while(T--){
		solve();
	}
}
