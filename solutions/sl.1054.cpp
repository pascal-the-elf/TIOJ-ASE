#include <iostream>
#include <string.h>
using namespace std;
	
string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
string s;
int N, cd;

int main(){
	cin >> s >> N;
	if(s[0] == 'S'){
		if(s[1] == 'u') cd = 0;
		else cd = 6;
	} else if(s[0] == 'M'){
		cd = 1;
	} else if(s[0] == 'T'){
		cd = 2;
		if(s[1] == 'h') cd += 2;
	} else if(s[0] == 'W'){
		cd = 3;
	} else if(s[0] == 'F'){
		cd = 5;
	}
	cout << days[(cd + N) % 7] << endl;
}
