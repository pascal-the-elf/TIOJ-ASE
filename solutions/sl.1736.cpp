#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e5 + 10;

vector<int> deps;
int l[maxN], r[maxN], N, maxD[maxN], minD[maxN], ans[maxN];

void dfs(int u = 1, int dep = 0){
	if(l[u] == -1 && r[u] == -1){
		minD[u] = maxD[u] = dep;
		ans[u] = 0;
		deps.push_back(dep);
		return;
	}
	if(l[u] == -1){
		dfs(r[u], dep + 1);		
		deps.push_back(dep);
		if(ans[r[u]] == -1){
			ans[u] = -1;
			return;
		}
		maxD[u] = maxD[r[u]];
		minD[u] = dep;
		if(minD[r[u]] > dep + 1){
			ans[u] = -1;
			return;
		}
		ans[u] = 1 + ans[r[u]];
		return;
	}
	if(r[u] == -1){
		dfs(l[u], dep + 1);	
		deps.push_back(dep);
		if(ans[l[u]] == -1){
			ans[u] = -1;

			return;
		}
		maxD[u] = maxD[l[u]];
		minD[u] = dep;
		if(minD[l[u]] > dep + 1){
			ans[u] = -1;
			return;
		}
		ans[u] = ans[l[u]];
		return;
	}
	dfs(l[u], dep + 1);
	dfs(r[u], dep + 1);
	maxD[u] = max(maxD[l[u]], maxD[r[u]]);
	minD[u] = min(minD[l[u]], minD[r[u]]);
	if(ans[l[u]] == -1 || ans[r[u]] == -1){
		ans[u] = -1;
		return;
	}
	if(minD[l[u]] == maxD[r[u]] || minD[l[u]] == maxD[r[u]] + 1){
		ans[u] = ans[l[u]] + ans[r[u]];
	} else if(minD[r[u]] == maxD[l[u]] || minD[r[u]] == maxD[l[u]] + 1){
		ans[u] = ans[l[u]] + ans[r[u]] + 1;
	} else {
		ans[u] = -1;
	}

}

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> l[i] >> r[i];
	}
	dfs();
	/*
	for(int i = 1; i <= N; i++){
		cout << "ans[" << i << "] = " << ans[i] << endl;
	}
	*/
	int mxDep = -1, mnDep = N + 1;
	for(int d : deps){
		mxDep = max(mxDep, d);
		mnDep = min(mnDep, d);
	}
	if(mxDep - mnDep > 1){
		cout << -1 << endl;
		return 0;
	}
	cout << ans[1] << endl;
}
