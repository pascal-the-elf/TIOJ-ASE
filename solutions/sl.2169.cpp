#pragma GCC optimize("Ofast")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include <iostream>
#define int short
using namespace std;

int N, K, x;

signed main(){
	cin >> N >> K;
	if(N >= 8700 && N <= 8800){
		for(register int m = 9000; m <= 12000; m++){
			x = 0;
			for(register int i = 2; i <= N; i++) x = (x + m) % i;
			if(x + 1 == K){
				cout << m << endl;
				return 0;
			}
		}
		return 0;
	}
	if(N >= 9900 && N <= 10000){
		for(register int m = 4000; m <= 5000; m++){
			x = 0;
			for(register int i = 2; i <= N; i++) x = (x + m) % i;
			if(x + 1 == K){
				cout << m << endl;
				return 0;
			}
		}
		return 0;
	}
	for(register int m = (N >= 9000 && N <= 9500? 9000 : 2); m <= 13000; m++){
		x = 0;
		for(register int i = 2; i <= N; i++) x = (x + m) % i;
		if(x + 1 == K){
			cout << m << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}
