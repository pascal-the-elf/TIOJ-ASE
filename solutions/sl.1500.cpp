#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int 
using namespace std;

const double INF = 1e30;

vector<pii> points;
int N;
double ans;
double dist(pii a, pii b){
	return (a.F - b.F) * 1.0 * (a.F - b.F) + (a.S - b.S) * 1.0 * (a.S - b.S);
}

signed main(){
	ericxiao;
	cout << fixed << setprecision(6);
	while(cin >> N){
		points.resize(N);
		for(int i = 0; i < N; i++){
			cin >> points[i].F >> points[i].S;
		}
		sort(points.begin(), points.end());
		ans = INF;
		for(int i = 0; i < N; i++){
			for(int j = i + 1; j < N && (points[j].F - points[i].F) * 1.0 * (points[j].F - points[i].F) <= ans + 1; j++){
				ans = min(ans, dist(points[i], points[j]));
			}
		}
		cout << sqrt(ans) << endl; //remember precision 6
	}
}
