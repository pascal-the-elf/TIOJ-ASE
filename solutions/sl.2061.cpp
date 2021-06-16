#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

string s;
int frqs[10];
int dp[10005][10005], lft[10005], rgt[10005], head = 0;

string getAns(int l, int r){
    //cout << "Running getAns(" << l << ", " << r << ")" << endl;
    if(l > r) return "";
    if(l == r){
        string t = "";
        t += s[l];
        return t;
    } else {
        if(s[l] == s[r]){
            return s[l] + getAns(l + 1, r - 1) + s[r];
        } else {
            if(dp[l + 1][r] >= dp[l][r - 1]) return getAns(l + 1, r);
            else return getAns(l, r - 1);
        }
    }
}

int main(){
    ericxiao;
    cin >> s;
    for(char c : s) frqs[c ^ '0']++;
    for(int i = 0; i < 10; i++){
        if(frqs[i] >= 1000){
            for(int j = 0; j < 1000; j++) cout << i;
            cout << '\n';
            return 0;
        }
    }

    for(int d = 1; d <= s.length(); d++){
        for(int i = 0; i <= s.length() - d; i++){
            if(d == 1){
                dp[i][i + d - 1] = 1;
                continue;
            }
            if(s[i] == s[i + d - 1]) dp[i][i + d - 1] = 2 + dp[i + 1][i + d - 2];
            else dp[i][i + d - 1] = max(dp[i + 1][i + d - 1], dp[i][i + d - 2]);
        }
    }
    string ans = "";
    int l = 0, r = s.length() - 1;
    while(l <= r){
        //cout << "l = " << l << ", r= " << r << endl;
        lft[head] = l;
        rgt[head] = r;
        head++;
        if(s[l] == s[r]){
            l++;
            r--;
        } else {
            if(dp[l + 1][r] >= dp[l][r - 1]){
                l++;
            } else {
                r--;
            }
        }
    }
    for(int i = head - 1; i >= 0; i--){
        if(s[lft[i]] == s[rgt[i]]){
            if(lft[i] == rgt[i]) ans += s[lft[i]];
            else ans = s[lft[i]] + ans + s[rgt[i]];
        }
    }
    cout << ans << '\n';
}
