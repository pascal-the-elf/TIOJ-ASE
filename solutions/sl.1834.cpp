#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <stack>
#include <string.h>
#define ONE "ダメよ" 
#define TWO "しかし" 
#define THREE "くやし" 
#define ERR "イヤ...やめてよ...お兄ちゃん...壊れる"
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;


bool jizz(string &a, string &b){
	if(a.length() != b.length()) return a.length() > b.length();
	for(int i = 0; i < a.length(); i++){
		if(a[i] != b[i]) return a[i] > b[i];
	}
	return true;
}

class Larger{
	public:
		const bool operator() (string &a, string &b) const {
			return jizz(a, b);
		}
};

class Smaller{
	public:
		const bool operator() (string &a, string &b) const {
			return !jizz(a, b);
		}
};

int a, x, y, N;
stack<string> re1;
queue<string> re2;
priority_queue<string, vector<string>, Smaller> re3;
priority_queue<string, vector<string>, Larger> re4;

string com, b;

inline void push(int a, string &b){
	if(a == 1){
		re1.push(b);
	} else if(a == 2){
		re2.push(b);
	} else if(a == 3){
		re3.push(b);
	} else if(a == 4){
		re4.push(b);
	}
}

inline string pop(int a){
	string r;
	if(a == 1){
		if(re1.size()){
			r = re1.top();
			re1.pop();
			return r;
		}
		return "";
	} else if(a == 2){
		if(re2.size()){
			r = re2.front();
			re2.pop();
			return r;
		}
		return "";

	} else if(a == 3){
		if(re3.size()){
			r = re3.top();
			re3.pop();
			return r;
		}
		return "";

	} else if(a == 4){
		if(re4.size()){
			r = re4.top();
			re4.pop();
			return r;
		}
		return "";
	}
}

int main(){
	ericxiao;
	while(cin >> N){
		re1 = stack<string>();
		re2 = queue<string>();
		re3 = priority_queue<string, vector<string>, Smaller>();
		re4 = priority_queue<string, vector<string>, Larger>();
		while(N--){
			cin >> com;
			if(com[2] == ONE[2]){
				cin >> a >> b;
				if(a == 1){
					re1.push(b);
				} else if(a == 2){
					re2.push(b);
				} else if(a == 3){
					re3.push(b);
				} else if(a == 4){
					re4.push(b);
				}
			} else if(com[2] == TWO[2]){
				cin >> x >> y;
				string res = pop(x);
				if(res == ""){
					//cout << ERR << endl;
					continue;
				}
				push(y, res);
			} else if(com[2] == THREE[2]){
				cin >> a;
				string res = pop(a);
				if(res == ""){
					cout << ERR << endl;
					continue;
				}
				cout << res << endl;
			}
		}

	}
}



