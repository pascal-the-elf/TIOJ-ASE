#include <iostream>
#include <string.h>
#include <deque>
using namespace std;

string a, b;
int p, pd, e1, e2;
double A, B;
deque<char> dq;


int main(){
    cin >> a >> b;
	A = stod(a), B = stod(b);
	if(abs(A - B) >= 1e-6){
		cout << (A > B ? a : b) << endl;
		return 0;
	}
	string oria = a, orib = b;
	bool f = true;
	for(char c : a){
		if(c == '0' && f) continue;
		f = false;
		dq.push_back(c);
	}
	a = "";
	for(char c : dq) a += c;
	dq = deque<char>();
	for(char c : b){
		if(c == '0' && f) continue;
		f = false;
		dq.push_back(c);
	}
	b = "";
	for(char c : dq) b += c;

	if(a[0] == '.') a = '0' + a;
	if(b[0] == '.') b = '0' + b;
    p = 2e9, pd = a.length() - 1;
    for(int i = 0; i < a.length(); i++){
        if('0' < a[i] && a[i] <= '9') p = min(p, i);
        if(a[i] == '.') pd = i;
    }
    e1 = pd - p;
    p = 2e9, pd = b.length() - 1;
    for(int i = 0; i < b.length(); i++){
        if('0' < b[i] && b[i] <= '9') p = min(p, i);
        if(b[i] == '.') pd = i;
    }
    e2 = pd - p;
    if(e1 != e2){
        cout << (e1 > e2 ? oria : orib);
    } else {
        string _a = a, _b = b;
        while(_a.length() < _b.length()) _a += '0';
        while(_a.length() > _b.length()) _b += '0';
        for(int i = 0; i < _a.length(); i++){
            if(_a[i] != _b[i]){
                cout << (_a[i] > _b[i] ? oria : orib);
                return 0;
            }
        }
    }
}
