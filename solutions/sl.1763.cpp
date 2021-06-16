#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define piii pair<pii,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 151, INF = 1e6;

int arr[maxN][maxN], N;

bool isValid(int y, int x){
	return (y >= 0 && x >= 0 && x < N && y < N);
}

class Cmp{
public:
	bool operator()(piii a, piii b){
		return a.S < b.S;
	}
};

priority_queue<piii, vector<piii>, Cmp > pq;

int dijkstra(int mV){ //gets the max of min value on all paths with max weight <= mV
	static int maxVal[maxN][maxN];
	static bool visited[maxN][maxN];
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		maxVal[i][j] = -INF;
		visited[i][j] = false;
	}
	maxVal[0][0] = arr[0][0];
	pq.push({{0, 0}, arr[0][0]});
	piii tp;	
	while(pq.size()){
		tp = pq.top();
		pq.pop();
		if(visited[tp.F.F][tp.F.S]) continue;
		visited[tp.F.F][tp.F.S] = true;
		if(isValid(tp.F.F + 1, tp.F.S) && !visited[tp.F.F + 1][tp.F.S] && arr[tp.F.F + 1][tp.F.S] <= mV && maxVal[tp.F.F + 1][tp.F.S] < min(maxVal[tp.F.F][tp.F.S], arr[tp.F.F + 1][tp.F.S])){
			maxVal[tp.F.F + 1][tp.F.S] = min(maxVal[tp.F.F][tp.F.S], arr[tp.F.F + 1][tp.F.S]);
			pq.push({{tp.F.F + 1, tp.F.S}, maxVal[tp.F.F + 1][tp.F.S]});
		}
		if(isValid(tp.F.F - 1, tp.F.S) && !visited[tp.F.F - 1][tp.F.S] && arr[tp.F.F - 1][tp.F.S] <= mV && maxVal[tp.F.F - 1][tp.F.S] < min(maxVal[tp.F.F][tp.F.S], arr[tp.F.F - 1][tp.F.S])){
			maxVal[tp.F.F - 1][tp.F.S] = min(maxVal[tp.F.F][tp.F.S], arr[tp.F.F - 1][tp.F.S]);
			pq.push({{tp.F.F - 1, tp.F.S}, maxVal[tp.F.F - 1][tp.F.S]});
		}
		if(isValid(tp.F.F, tp.F.S + 1) && !visited[tp.F.F][tp.F.S + 1] && arr[tp.F.F][tp.F.S + 1] <= mV && maxVal[tp.F.F][tp.F.S + 1] < min(maxVal[tp.F.F][tp.F.S], arr[tp.F.F][tp.F.S + 1])){
			maxVal[tp.F.F][tp.F.S + 1] = min(maxVal[tp.F.F][tp.F.S], arr[tp.F.F][tp.F.S + 1]);
			pq.push({{tp.F.F, tp.F.S + 1}, maxVal[tp.F.F][tp.F.S + 1]});
		}
		if(isValid(tp.F.F, tp.F.S - 1) && !visited[tp.F.F][tp.F.S - 1] && arr[tp.F.F][tp.F.S - 1] <= mV && maxVal[tp.F.F][tp.F.S - 1] < min(maxVal[tp.F.F][tp.F.S], arr[tp.F.F][tp.F.S - 1])){
			maxVal[tp.F.F][tp.F.S - 1] = min(maxVal[tp.F.F][tp.F.S], arr[tp.F.F][tp.F.S - 1]);
			pq.push({{tp.F.F, tp.F.S - 1}, maxVal[tp.F.F][tp.F.S - 1]});
		}

	}
	return maxVal[N - 1][N - 1];
}

int main(){
	ericxiao;
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> arr[i][j];
		}
	}
	int ans = INF, dr;
	for(int mV = arr[0][0]; mV <= 400; mV++){
		ans = min(ans, mV - dijkstra(mV));
	}
	cout << ans << endl;
}
