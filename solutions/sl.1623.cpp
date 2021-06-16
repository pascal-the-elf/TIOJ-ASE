#include <iostream>
#include <numeric>
#include <algorithm>
#include <queue>
using namespace std;

const int maxN = 2e3 + 326;
int w[maxN][maxN], v[maxN], N, K, M, ord[maxN], ans, take[maxN];

inline int getAns(){
	int cars = 0, cs = 0, r = 0, ret = 0; 
	for(int i = 0; i < N; i++){
		if(!take[i]) continue;
		cs += v[i];
		r++;
		if(cs > M){
			ret += r;
			r = 0;
			cs = 0;
			cars++;
			if(cars == K){
				return ret;
			}
		}
	}
	return ret;
}

int main(){
	cin >> N >> K >> M;
	for(int i = 0; i < N; i++) cin >> v[i];
	iota(ord, ord + N, 0);
	sort(ord, ord + N, [](int a, int b){
		return v[a] < v[b];
	});
	for(int i = 0; i < N; i++){
		take[ord[i]] = true;
		//cout << "get = " << getAns() << endl;
		ans = max(ans, getAns());
	}
	cout << ans << endl;
}
