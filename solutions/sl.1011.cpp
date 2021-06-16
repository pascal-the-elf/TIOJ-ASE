#include <iostream>
#include <string.h>
using namespace std;

int A, B;

string getBin(int x){
    string s = "";
    while(x){
        s = (char)('0' + (x % 2)) + s;
        x /= 2;
    }
    return s;
}

int main(){
    cin >> A >> B;
    string s1 = getBin(A), s2 = getBin(B);
    int l;
    for(l = 0; l < min(s1.length(), s2.length()); l++){
        if(s1[l] != s2[l]) break;
    }
    cout << s1.length() + s2.length() - 2 * l << endl;
}
