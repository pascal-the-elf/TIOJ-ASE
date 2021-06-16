#include <iostream>
#include <string.h>
#include <stack>
#include <map>
#define F first
#define S second
using namespace std;

map<string, int> frq;

string s;

map<string, int> solve(string s){
    //cout << "Solving: " << s << endl;
    string cur = "", coef;
    int lv = 0, c;
    map<string ,int> ret;
    for(int i = 0; i < s.length(); i++){
        map<string ,int> tmp;
        coef = cur = "";
        if(s[i] >= 'A' && s[i] <= 'Z'){
            cur += s[i];
            if(i < s.length() - 1 && s[i + 1] >= 'a' && s[i + 1] <= 'z'){
                cur += s[++i];
            }
            tmp[cur]++;
        } else { //it's a ()
            lv = 0;
            for(; i < s.length(); i++){
                cur += s[i];
                if(s[i] == '(') lv++;
                else if(s[i] == ')') lv--;
                if(!lv){
                    break;
                }
            }
            //cout << "for s = " << s << ", i = " << i << endl;
            tmp = solve(cur.substr(1, cur.length() - 2));
        }
        if(i + 1 < s.length() && s[i + 1] <= '9' && s[i + 1] >= '0'){
            i++;
            for(; i < s.length(); i++){
                if(!(s[i] <= '9' && s[i] >= '0')) break;
                coef += s[i];
            }
            i--;
            c = stoi(coef);
            for(auto &p : tmp) p.S *= c;
        }
        for(auto p : tmp){
            ret[p.F] += p.S;
        }
    }
    return ret;
}

int main(){
    cin >> s;
    cout << s << endl;
    frq = solve(s);
    for(auto p : frq){
        cout << p.F << ":" << p.S << endl;
    }
}
