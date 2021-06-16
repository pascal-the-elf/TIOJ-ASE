#include <iostream>
#include <string.h>
using namespace std;

string s;

int main(){
    while(cin >> s){
        int v = 0;
        for(char c : s) v += tolower(c) - 'a' + 1;
        v %= 17;
        if(v <= 2) cout << "D";
        else if(v <= 5) cout << "C";
        else if(v <= 9) cout << "B";
        else if(v <= 12) cout << "A";
        else if(v <= 16) cout << "SA";
        cout << '\n';
    }
}
