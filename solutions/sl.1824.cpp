#include <iostream>
#include <string.h>
using namespace std;

int ans;
string s;

int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '?'){
            for(int j = 0; j < 10; j++){
                s[i] = (char)(j + '0');
                if(!(stoi(s) % 7)) cout << s << endl;
            }
        }
    }
}

