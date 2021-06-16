#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

const int maxN = 1e5 + 10;
string s;


int deg[maxN], leaves, maxdep, cnt, maxdeg;

inline void solve(string s){
    fill(deg, deg + s.length(), 0);
    maxdeg = leaves = cnt = maxdep = 0;
    stack<int> stk;
    for(char c : s){
        if(c == '('){
            if(!stk.empty()){
                deg[stk.top()]++;
                maxdeg = max(maxdeg, deg[stk.top()]);
            }
            stk.push(++cnt);
            maxdep = max(maxdep, (int)stk.size());
        } else if(c == '*'){
            leaves++;
            if(!stk.empty()){
                deg[stk.top()]++;
                maxdeg = max(maxdeg, deg[stk.top()]);
            }
            maxdep = max(maxdep, (int)stk.size() + 1);
        } else {
            stk.pop();
        }
    }
    cout << leaves << " " << maxdep << " " << maxdeg << endl;
}

int main(){
    while(cin >> s){
        solve(s);
    }
}
