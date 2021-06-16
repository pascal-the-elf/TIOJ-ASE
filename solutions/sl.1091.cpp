#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int INF = 1e6;

string A, B;

vector<pii> segs;
vector<int> fail, dp;

vector<int> getFail(string s){
    vector<int> res;
    res.resize(s.length());
    res[0] = -1;
    int q;
    //cout << -1 << " ";
    for(int i = 1; i < s.length(); i++){
        q = res[i - 1];
        //cout << "Q = " << q << endl;
        while(q > -1 && s[q + 1] != s[i]) q = res[q];
        if(s[q + 1] == s[i]) q++;
        res[i] = q;
        //cout << res[i] << " ";
    }
    //cout << endl;
    return res;
}

int main(){
    cin >> A >> B; //find occs of A in B
    if(B.length() <= 10){
        int maxsz = 0;
        string s;
        bool hasMatch;
        for(int i = 0; i < (1 << B.length()); i++){
            s = "";
            //cout << "i = " << i << endl;
            for(int j = 0; j < B.length(); j++){
                if((i & (1 << j) ) > 0 )s += B[j];
            }
            //cout << "s = " << s << endl;
            hasMatch = false;
            fail = getFail((A + '$' + s));
            for(int i = A.length() + 1; i < A.length() + 1 + s.length(); i++){
                if(fail[i] == A.length() - 1) hasMatch = true;
            }
            //cout << "hasmatch: " << hasMatch << endl;
            if(!hasMatch) maxsz = max(maxsz, (int)s.length());
        }
        cout << B.length() - maxsz << endl;
        return 0;
    }
    bool isAllA = true;
    for(int i = 0; i < B.length(); i++){
        if(B[i] == A[0]) B[i] = 'A';
        else B[i] = 'B';
    }
    for(int i = 1; i < A.length(); i++){
        if(A[i] == A[0]) A[i] = 'A';
        else A[i] = 'B';
        if(A[i] == 'B') isAllA = false;
    }
    A[0] = 'A';
    //cout << "NEWA = " << A << endl;
    //cout << "NEWB = " << B << endl;

    if(isAllA){
        int ans = 0, cons;
        for(int i = 0; i < B.length(); i++){
            if(B[i] == 'A'){
                cons = 0;
                while(i < B.length() && B[i] == 'A'){
                    cons++;
                    i++;
                }
                i--;
                ans += max(cons - (int)A.length() + 1, 0);
            }
        }
        cout << ans << endl;
        return 0;
    }


    fail = getFail((A + "$" + B));
    dp.resize(B.size() + 1);
    segs.emplace_back(-1, -1);
    for(int i = A.length() + 1; i < A.length() + B.length() + 1; i++){
        if(fail[i] == A.length() - 1) segs.emplace_back(i -2 *  A.length(), i -  A.length() - 1);
    }
    dp[0] = 0;
    int currentCost, l;
    bool hasDiff;
    for(int i = 1; i < segs.size(); i++){
        dp[i] = INF;
        for(int j = i; j > 0; j--){
            if(segs[j].S < segs[i].F) break;
            currentCost = dp[j - 1];
            hasDiff = false;
            for(int k = segs[i].F; k <= segs[j].S; k++){
                if(B[k] != B[segs[i].F]) hasDiff = true;
            }
            if(hasDiff) dp[i] = min(dp[i], currentCost + 1);
            else {
                for(l = segs[j].S; l < B.length() && B[l] ==  B[segs[j].S]; l++){}
                currentCost += l - segs[j].S;
                dp[i] = min(dp[i], currentCost);
            }
        }
        //cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    cout << dp[segs.size() - 1];
}
