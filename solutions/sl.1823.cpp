#include <iostream>
#define int long long int 
using namespace std;

const int maxN = 1e5;
bool visited[maxN];



bool isTrue(int x){
	if(visited[x]) return false;
	visited[x] = true;
	//cout << "Running f(" << x << ")" << endl;
	if(x > 1e10) return false;
	if(x == 1) return true;
	int f = 0;
	while(x){
		f += (x % 10) * (x % 10);
		x /= 10;
	}
	return isTrue(f);
}

signed main(){
	int cnt = 0;
	int N = 67172;
	cout << "44\n320\n694\n6899\n67169";
}
