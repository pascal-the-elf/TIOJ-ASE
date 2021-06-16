#include <iostream>
#include <vector>
#include <map>
#include <deque>
#define int long long int
using namespace std;

const int maxN = 1e6 + 10, LIM = (1LL << 40), PRIMES = 20, MAXPRIMES = 25;


int primes[MAXPRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
map<int, int> smallestpf;

void dfs(int facts, int currentNum, int currentPrime){
	//cout << "Running (" << facts << ", " << currentNum << ", " << currentPrime << ")" << endl;
	if(currentPrime == PRIMES){
		if(!smallestpf.count(facts)){
			smallestpf[facts] = currentNum;
		} else {
			smallestpf[facts] = min(smallestpf[facts], currentNum);
		}
		return;
	}
	//cout << 1 * currentNum << " and " << LIM << endl;
	for(int cur = 1, p = 0; (cur * currentNum) < LIM; p++, cur *= primes[currentPrime]){
		//cout << "cur = " << cur << endl;
		dfs(facts * (p + 1), currentNum * cur, currentPrime + 1);
	}
	//cout << "OUT" << endl;
}

signed main(){
	dfs(1, 1, 0);
	//cout << "DONE" << endl;
	//for(auto [a, b] : smallestpf){
	//	cout << "Smallest number with " << a << " factors = " << b << endl;
	//}
	deque<int> dq;
	dq.push_back(0);
	for(auto [___, num] : smallestpf){
		while(dq.size() && dq.back() > num) dq.pop_back();
		dq.push_back(num);
	}
	for(int x : dq){
		cout << x << endl;
	}
	int N;
	while(cin >> N){
		cout << dq[N] << endl;
	}
}
