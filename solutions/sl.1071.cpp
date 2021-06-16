#include <iostream>
#include <vector>
#include <set>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 226;

int n, ans = INF;
string s;
vector<string> t;
set<string> st;

vector<int> match(string a, string b){ //find b in a
    //cout << "Finding " << b << " in " << a << endl;
    string st = b + "$" + a;
    vector<int> fail(b.length() + a.length() + 1), matches;
    fail[0] = -1;
    int q;
    //cout << st << endl;
    for(int i = 1; i < st.length(); i++){
        q = fail[i - 1];
        while(q >= 0 && st[q + 1] != st[i]) q = fail[q];
        if(st[q + 1] == st[i]) q++;
        fail[i] = q;
        //cout << fail[i] << " ";
    }
    //cout << endl;
    for(int i = b.length() * 2; i < st.length(); i++){
        if(fail[i] == b.length() - 1) matches.push_back(i - b.length() * 2);
    }
    //cout << "Found at positions ";
    //for(int u : matches) cout << u << " "; cout << endl;
    return matches;
}

void dfs(string s){
    if(s.length() < ans) ans = s.length();
    string ns;
    for(string str : t){
        if(s.length() < str.length()) continue;
        vector<int> matches = match(s, str);
        if(!matches.size()) continue;
        int pos = matches[0];
        ns = s.substr(0, pos) + s.substr(pos + str.length(), s.length());
        //cout << "s = " << s << " str = " << str << ", ns = " << ns << endl;
        if(!st.count(ns)){
            st.insert(ns);
            dfs(ns);
        }
    }
}

int main(){
    //match("ababab", "ab");
    ericxiao;
    while(cin >> n){
        if(!n) return 0;
        ans = INF;
        cin >> s;
        t.resize(n);
        for(int i = 0; i < n; i++){
            cin >> t[i];
        }
        st = set<string>();
        dfs(s);
        st.insert(s);
        cout << ans << '\n';
    }
}
