#include <iostream>
#include <algorithm>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326;
int N, v[maxN], ord[maxN];
string arr[maxN];


inline int ds(string x){
	int r = 0;
	for(char c : x) r += c - '0';
	return r;
}

signed main(){
	ericxiao;
	while(cin >> N){
		for(int i = 0; i < N; i++){
			cin >> arr[i];
			ord[i] = i;
			v[i] = ds(arr[i]);
		}
		stable_sort(ord, ord + N, [](int a, int b){
			return v[a] < v[b];
		});
		for(int i = 0; i < N; i++) cout << arr[ord[i]] << " \n"[i == N - 1];
	}
}
