#include <iostream>
#include <string.h>
using namespace std;

const int maxN = 226;

string s;
int fail[maxN], q;
int main(){
    while(cin >> s){
        fail[0] = -1;
        //cout << -1 << " ";
        for(int i = 1; i < s.length(); i++){
            q = fail[i - 1];
            while(q > -1 && s[q + 1] != s[i]) q = fail[q];
            if(s[q + 1] == s[i]) q++;
            fail[i] = q;
            //cout << fail[i] << " ";
        }
        //cout << endl;
        if(s.length() % (s.length() - fail[s.length() - 1] - 1) == 0) cout << s.length() / (s.length() - fail[s.length() - 1] - 1) << '\n';
        else cout << "1\n";
    }
}
