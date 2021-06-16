#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
//By S
string s;

int main(){
    cin >> s;
    string newS = s;
    reverse(s.begin(), s.end());
    cout << newS + s.substr(1) << endl;
}

