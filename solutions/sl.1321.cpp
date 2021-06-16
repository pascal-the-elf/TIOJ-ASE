#include <iostream>
#include <string.h>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e6 + 10;

string s, _s;

int manacher[maxN * 2], ans[maxN], m, len;

int main(){
    ericxiao;
    cin >> _s;
    len = _s.length();
    _s = _s + _s;
    s = '$';
    for(int i = 0; i < _s.length(); i++){
        s += _s[i];
        s += '$';
    }
    //cout << s << endl;
    int l = 0, r = 0;
    for(int i = 0; i < s.length(); i++){
        if(r < i) manacher[i] = 1;
        else manacher[i] = min(r - i, manacher[l + r - i]);
        while(i - manacher[i] - 1 >= 0 && i + manacher[i] + 1 < s.length() && s[i - manacher[i] - 1] == s[i + manacher[i] + 1]){
            manacher[i]++;
        }
        if(r < i + manacher[i]){
            l = i - manacher[i];
            r = i + manacher[i];
        }
        //cout << manacher[i] << " ";
    }
    //cout << endl;
    //cout << "len = " << len << endl;
    if((len & 1) == 0){
        for(int i = 0; i < s.length(); i += 2){
            //cout << "manacher[" << i << "] = " << manacher[i] << endl;
            if(manacher[i] >= len && i / 2 - len / 2 < len) ans[m++] = i / 2 - len / 2;
        }
    } else {
        for(int i = 1; i < s.length(); i += 2){
            //cout << "manacher[" << i << "] = " << manacher[i] << endl;
            if(manacher[i] >= len && i / 2 - len / 2 < len) ans[m++] = i / 2 - len / 2;
        }
    }
    if(!m){
        cout << "none";
        return 0;
    }
    cout << m << ":";
    for(int i = 0; i < m; i++) cout << " " << ans[i];
}
