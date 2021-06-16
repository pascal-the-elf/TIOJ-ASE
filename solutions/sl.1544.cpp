#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int T;
string a, b;

bool cmp(string a, string b){
	if(a.length() != b.length()) return a.length() < b.length();
	for(int i = 0; i < a.length(); i++){
		if(a[i] != b[i]) return a[i] < b[i];
	}

}
int main(){
	ericxiao;
	cin >> T;
	while(T--){
		cin >> a >> b;
		cout << cmp(a, b) << endl;
	}
}
