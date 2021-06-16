#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
vector<int> vec;
set<int> st;
int main(){
	while(cin >> N){
		if(!N) return 0;
		st = set<int>();
		vec.resize(N + 1);
		for(int i = 1; i <= N; i++) {
			cin >> vec[i];
			vec[i] += vec[i - 1];
		} 
		if(vec[N] == N){
			cout << "NO\n";
			continue;
		}
		for(int i = 0; i < N; i++){
			for(int j = i + 1; j <= N; j++){
				st.insert(vec[j] - vec[i]);
			}
		}
		bool can = true;
		for(int i = 1; i <= vec[N]; i++){
			can &= st.count(i);
		}
		if(can) cout << "YES\n";
		else cout << "NO\n";
	}
}
