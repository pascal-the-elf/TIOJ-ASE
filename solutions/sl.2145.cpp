#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > ans;
int N;

vector<vector<char>> solve(int n = N){
	vector<vector<char>> res;
	if(n == 1){
		return {
			{'.','.','.'}, 
			{'.','#','.'}, 
			{'.','.','.'} 
		};
	}
	int sz = 1;
	for(int i = 0; i < n; i++) sz *= 3;
	res.resize(sz);
	for(int i = 0; i < sz; i++) res[i].resize(sz);
	vector<vector<char>> jizz = solve(n - 1);
	for(int i = 0; i < sz / 3; i++){
		for(int j = 0; j < sz / 3; j++){
			for(int x = 0; x < 3; x++){
				for(int y = 0; y < 3; y++){
					res[i + x * sz / 3][j + y * sz / 3] = jizz[i][j];
				}
			}
			res[i + sz / 3][j + sz / 3] = '#';
		}
	}
	return res;
}

int main(){
	cin >> N;
	ans = solve();
	for(vector<char> v : ans){
		for(char x : v) cout << x;
		cout << '\n';
	}
}
