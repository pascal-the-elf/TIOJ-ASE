#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int K, ans[100000 + 10];
string s;

string ip()
{
    string i="";
    int temp=getchar_unlocked();
    while(temp<'a'||temp>'z')
        temp=getchar_unlocked();
    while(temp>='a'&&temp<='z')
    {
        i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> K){
        s = ip();
        int l = s.length();
        if(l < 2 * K){
            cout << "0" << endl;
            continue;
        }
        for(int i = K; i < l; i++){
            ans[i] = ans[i-1] + (s[i] == s[i - K]);
            //cout << "ans[" << i << "] = " << ans[i] << endl;
        }
        int res = 0;
        for(int i = 2 * K - 1; i < l; i++){
            res += (ans[i] - ans[i - K] == K);
            //cout << "ans[" << i << "] = " << ans[i] << ", ans[" << i << " - " << K << " - 1] = " << ans[i-K-1] << endl;
        }
        cout << res << endl;
    }
}
