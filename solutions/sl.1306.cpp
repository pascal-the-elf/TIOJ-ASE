#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int T, N;
string a, b;

int match(string a, string b){
    int res = 0;
    string s = a + "$" + b;
    vector<int> fail = vector<int>(a.length() + b.length() + 1);
    fail[0] = -1;
    for(int i = 1; i < s.length(); i++){
        int q = fail[i - 1];
        while(q >= 0 && s[q + 1] != s[i]) q = fail[q];
        if(s[q + 1] == s[i]) q++;
        fail[i] = q;
        res += (fail[i] == (a.length() - 1));
    }
    return res;
}

int main(){
    ericxiao;
    cin >> T;
    while(T--){
        cin >> a;
        cin >> N;
        while(N--){
            cin >> b;
            cout << match(b, a) << '\n';
        }
    }
}
