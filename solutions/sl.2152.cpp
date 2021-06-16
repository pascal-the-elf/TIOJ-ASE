#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <string.h>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);
#define endl '\n'
using namespace std;

const int maxN = 7e3 + 226;

stack<int> stk;
vector<string> ans;
int A[maxN], B[maxN], N, cnt;

void solve(int l = 0, int r = N){
	//cout << "S(" << l << ", " << r << ")" << endl;
	if(l >= r) return;
	if(l + 1 == r){
		cnt++;
		ans.push_back("T");
		ans.push_back("U");
		int val = stk.top();
		ans.push_back("P " + to_string(val));
		return;
	}
	int m = (r + l) / 2;
	set<int> need;
	bool hasTop = false;
	for(int i = l + 1; i < m; i++) need.insert(B[i]);
	vector<int> tp, bt;
	for(int i = 0; i < (r - l); i++){
		ans.push_back("T");
		cnt++;
		int val = stk.top();
		stk.pop();
		if(need.count(val)){
			tp.emplace_back(val);
			need.erase(val);
		} else {
			bt.emplace_back(val);
		}
		if(val == B[l]) hasTop = true;
		if(hasTop && need.size() == 0) break;
	}
	ans.push_back("U");
	for(int val : bt){
		stk.push(val);
		ans.push_back("P " + to_string(val));
	}
	for(int val : tp){
		stk.push(val);
		ans.push_back("P " + to_string(val));
	}

	solve(l + 1, m);

	need = set<int>();
	vector<int>().swap(tp);
	vector<int>().swap(bt);
	hasTop = false;
	for(int i = m + 1; i < r; i++) need.insert(B[i]);
	for(int i = 0; i < (r - l); i++){
		ans.push_back("T");
		cnt++;
		int val = stk.top();
		stk.pop();
		if(need.count(val)){
			tp.emplace_back(val);
			need.erase(val);
		} else {
			bt.emplace_back(val);
		}
		if(val == B[m]) hasTop = true;
		if(hasTop && need.size() == 0) break;
	}
	ans.push_back("U");
	for(int val : bt){
		stk.push(val);
		ans.push_back("P " + to_string(val));
	}
	for(int val : tp){
		stk.push(val);
		ans.push_back("P " + to_string(val));
	}
	solve(m + 1, r);
}


int main(){
	ericxiao;
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = N - 1; i >= 0; i--){
		stk.push(A[i]);
	}
	for(int i = 0; i < N; i++) cin >> B[i];
	solve();
	cout << cnt << endl;
	for(string s : ans){
		cout << s << endl;
	}
}
