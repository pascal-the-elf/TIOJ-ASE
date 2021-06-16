#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string s, _s, ans;
int n, m, x;

int main(){
    ericxiao;
    while(cin >> n >> m){
        if(!n && !m) return 0;
        s = "", ans = "";
        for(int i = 0; i < n; i++){
            cin >> _s;
            s += _s;
        }
        for(int i = 0; i < m; i++){
            cin >> x;
            ans += s[x - 1];
        }
        cout << ans << '\n';
    }
}
