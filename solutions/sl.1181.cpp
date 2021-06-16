#include <iostream>
#include <string.h>
using namespace std;

string jizz = "RGBYP";
string s;
int T;

int main(){
	cin >> T;
	while(T--){
		int has[5];
		for(int i = 0; i < 5; i++) has[i] = 0;
		for(int i = 0; i < 12; i++){
			cin >> s;
			for(char c : s){
				for(int j = 0; j < 5; j++){
					if(jizz[j] == c){
						has[j] = 1;
					}
				}
			}
		}
		int a = 0;
		for(int i = 0; i < 5; i++) a += has[i];
		cout << a << endl;

	}
}
