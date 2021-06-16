#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

long long int N, M, a, b, deg[maxN];

int main(){
	ericxiao;
	cin >> N >> M;
	if(M == N * (N - 1) / 2){
		cout << 0 << '\n';
	} else {
		cout << N << '\n';
	}
	return 0;
}
