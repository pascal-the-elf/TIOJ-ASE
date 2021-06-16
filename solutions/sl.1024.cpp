#include <iostream>
#include <string.h>
using namespace std;

string ans1[10], ans2[10];

string operator*(string a, string b){ //AB=((A|B)|(A|B))
	return "((" + a + "|" + b + ")|(" + a + "|" + b + "))";
}

string add(string a, string b){ //A+B=((A|A)|(B|B))
	return "((" + a + "|" + a + ")|(" + b + "|" + b + "))";
}
string getAns1(int n){ //Cn= AnBn+(An+Bn)Cn-1
	if(ans1[n] != "") return ans1[n];
	string s = getAns1(n - 1);
	string An = "A", Bn = "B";
	An += (char)(n + '0');
	Bn += (char)(n + '0');
	ans1[n] = add((An * Bn), add(An, Bn) * s);
	return ans1[n];
}

string getAns2(int n){ //Cn =((An|Bn)|(Cn-1|((An|An)|(Bn|Bn))))
	if(ans2[n] != "") return ans2[n];
	string s = getAns2(n - 1);
	string An = "A", Bn = "B";
	An += (char)(n + '0');
	Bn += (char)(n + '0');
	ans2[n] = "((" + An + "|" + Bn + ")|("+ s + "|((" + An + "|" + An + ")|(" + Bn + "|" + Bn + "))))";
	return ans2[n];
}

int cnt(string s){
	int r = 0;
	for(char c : s){
		r += (c == '|');
	}
	return r;
}

int N;

int main(){
	ans1[0] = ans2[0] = "((A0|B0)|(A0|B0))";
	cin >> N;
	string A = getAns1(N), B = getAns2(N);
	cout << "ans1:" << endl;
	cout << A << endl;
	cout << cnt(A) << " NAND(s) used." << endl;
	cout << "ans2:" << endl;
	cout << B << endl;
	cout << cnt(B) << " NAND(s) used." << endl;

}


