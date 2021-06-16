#include <iostream>
#define int long long int
using namespace std;

const int M = 1000000;

int exp(int b, int e){
	int r = 1;
	for(int i = 0; i < 30; i++){
		if((e >> i) & 1){
			r = r * b % M;
		} 
		b = b * b % M;
	}
	return r;
}

int a, b, c, d;

signed main(){
	cin >> a >> b >> c >> d;
	int r = 0;
	for(int i = a; i <= d; i += b){
		r = (r + exp(i, c)) % M;
	}
	cout << r << endl;
}
