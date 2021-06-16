#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int T;
string s, cs;
vector<string> lhs, rhs;

vector<string> neg(vector<string> vec){
    vector<string> res;
    if(vec.size() == 1){
        res.push_back("not");
        res.push_back(vec[0]);
        return res;
    }
    if(vec.size() == 2){
        res.push_back(vec[1]);
        return res;
    }
    vector<string> l, r;
    bool type = 0, f = false; //0: and; 1: or
    for(string s : vec){
        if(s == "and" || s == "or"){
            type = (s == "or");
            f = true;
            continue;
        }
        (f ? r : l).push_back(s);
    }
    l = neg(l);
    r = neg(r);
    if(type) l.push_back("and");
    else l.push_back("or");
    for(string s : r) l.push_back(s);
    return l;
}

int main(){
    cin >> T;
    getline(cin, s);
    while(T--){
        getline(cin, s);
        cs = "";
        lhs.clear();
        rhs.clear();
        bool f = false;
        for(char c : s){
            if(c == ' '){
                if(cs == "IF"){
                    cs = "";
                    continue;
                }
                if(cs == "THEN"){
                    f = true;
                    cs = "";
                    continue;
                }
                (f ? rhs : lhs).push_back(cs);
                cs = "";
            } else {
                cs += c;
            }
        }
        /*
        cout << "LHS: \n";
        for(string s : lhs) cout << s << "/";
        cout << "\nRHS: \n";
        for(string s : rhs) cout << s << "/";
        cout << endl;
        */
        rhs.push_back(cs);
        lhs = neg(lhs);
        rhs = neg(rhs);
        cout << "IF";
        for(string s : rhs) cout << " " << s;
        cout << " THEN";
        for(string s : lhs) cout << " " << s;
        cout << endl;
    }
}
