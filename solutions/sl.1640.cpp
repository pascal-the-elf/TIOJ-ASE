#include <iostream>
#include <set>
#define int long long int 
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

inline int lg(int x){
	for(int i = 0;; i++){
		if((1LL << (i)) >= x) return i;
	}
}

signed main(){
	ericxiao;
	int N;
	while(cin >> N){
		if(N != -1)
			cout << N << " " << N + lg(N) - 2 << endl;
		else return 0;
	}
}

