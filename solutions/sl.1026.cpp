#include <iostream>
#include <string.h>
using namespace std;

int n;

int main(){
    string s = "";
    cin >> n;
    while(n){
        s += (n % 2 + '0');
        n /= 2;
    }
    string ans = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == s.length() - 1){
            ans += '+';
        } else {
            if(s[i + 1] == '0'){
                while(s[i + 1] == '0'){
                    ans += '-';
                    i++;
                }
            }
            ans += '+';
        }
    }
    cout << ans.length() << endl;
    cout << ans << endl;
}
