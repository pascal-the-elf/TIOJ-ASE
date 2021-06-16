#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 515 * 2;

int N, T;
vector<int> a, b, adj[maxN], pa, pb, from, len, indeg;
vector<double> lis, _a, _b;
queue<int> que;
bool ing[maxN];

inline void solve(){
	cin >> N;
	vector<int>().swap(a);
	vector<int>().swap(b);
	_a.resize(N);
	_b.resize(N);
	from.resize(N);
	len.resize(N);
	indeg.resize(N);
	que = queue<int>();
	vector<double>().swap(lis);
	fill(len.begin(), len.end(), 1);
	fill(ing, ing + N, false);
	fill(indeg.begin(), indeg.end(), 0);
	fill(from.begin(), from.end(), -1);
	for(int i = 0; i < N; i++){
		cin >> _a[i];
		lis.push_back(_a[i]);
	}
	for(int i = 0; i < N; i++){
		cin >> _b[i];
		lis.push_back(_b[i]);
	}
	sort(lis.begin(), lis.end());
	for(double x : _a){
		a.push_back(lower_bound(lis.begin(), lis.end(), x) - lis.begin());	
	}
	for(double x : _b){
		b.push_back(lower_bound(lis.begin(), lis.end(), x) - lis.begin());	
	}
	for(int i = 0; i < N; i++) vector<int>().swap(adj[i]);
	pa.resize(lis.size());
	fill(pa.begin(), pa.end(), -1);
	pb.resize(lis.size());
	fill(pb.begin(), pb.end(), -1);
	for(int i = 0; i < N; i++) pa[a[i]] = i, pb[b[i]] = i;
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			if(a[i] > a[j] && pb[a[i]] != -1 && pb[a[j]] != -1 && pb[a[i]] < pb[a[j]]){
				//cout << j << " connects to " << i << endl;
				adj[j].push_back(i);
				indeg[i]++;
				ing[i] = ing[j] = true;
			}
		}
	}
	int curMax = 0, maxAt = -1;
	for(int i = 0; i < N; i++){
		if(pb[a[i]] != -1){
			curMax = 1;
			maxAt = i;
		}
	}
	que = queue<int>();
	for(int i = 0; i < N; i++){
		if(ing[i] && !indeg[i]){
			que.push(i);
			maxAt = i;
		}
	}

	while(que.size()){
		int f = que.front(); que.pop();	
		if(curMax < len[f]){
			curMax = len[f];
			maxAt = f;
		}
		for(int x : adj[f]){
			if(len[x] < len[f] + 1){
				len[x] = len[f] + 1;
				from[x] = f;
			}
			indeg[x]--;
			if(!indeg[x]) que.push(x);
		}
	}
	for(int cur = maxAt; ~cur; cur = from[cur]){
		cout << lis[a[cur]] << " ";
	}
	cout << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
