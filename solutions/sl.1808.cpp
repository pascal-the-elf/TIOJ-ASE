#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

string operator + (string a, string b){
    string r = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.length() < b.length()) swap(a, b);
    while(b.length() < a.length()) b += '0';
    bool c = false;
    for(int i = 0; i < a.length(); i++){
        r += ((a[i] + b[i] + c - 2 * '0') % 10) + '0';
        c = (a[i] + b[i] + c - 2 * '0') / 10;
    }
    if(c) r += '1';
    reverse(r.begin(), r.end());
    return r;
}

string div2(string a){
    string res = "";
    int cr = 0;
    for(char c : a){
        cr += (c - '0');
        if(!(res == "" && !(cr / 2)))
            res += (cr / 2 + '0');
        cr %= 2;
        cr *= 10;
    }
    if(res == "") return "0";
    return res;
}

string operator *(string b, string e){
    if(e == "0") return "1";
    if(e == "1") return b;
    string r = b * div2(e);
    r = r + r;
    if((*e.rbegin() - '0') % 10 % 2) r = r + b;
    return r;
}

vector<string> ans[101];

signed main(){
    ans[1].push_back("1");
    ans[1].push_back("5");
    ans[1].push_back("6");
    cout << "vector<vector<string>> = {";
    string st = "0", _s, __s, ori;
    for(int d = 2; d <= 100; d++){
        cout << "{";
        for(int s = 1; s < 10; s++){
            _s = (s + '0');
            _s.append(st);
            for(int _d = 1; _d < d; _d++){
                for(string n : ans[_d]){
                    __s = _s + n;
                    ori = __s;
                    __s = __s * __s;
                    if(__s.substr(__s.length() - ori.length(), ori.length()) == ori){
                        ans[d].push_back(ori);
                        cout << "\"" << ori << "\",";
                    }
                }
            }
        }
        cout << "}";
        cout << ", "[d == 100] << endl;
        st.append("0");
    }
    cout << "}" << endl;
}
