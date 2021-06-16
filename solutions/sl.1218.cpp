#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 1e4 + 10;

string N, _N;

int main(){

    while(cin >> N){
        bool f = false;
        _N = "";
        for(int c : N){
            if(c != '0') f = true;
            if(f) _N += c;
        }
        if(!_N.length()) return 0;
        N = _N;
        if((N[N.length() - 1] - '0') % 2){
            cout << "LOSE ";
        } else {
            cout << "WIN ";
        }
        if(N == "1"){
            cout << "WIN\n";
            continue;
        }
        if(N == "2"){
            cout << "LOSE\n";
            continue;
        }
        if(N == "3" || N == "4"){
            cout << "WIN\n";
            continue;
        }
        if((N[N.length() - 1] - '0') % 2){
            cout << "LOSE";
        } else {
            cout << "WIN";
        }
        cout << endl;
    }
}
