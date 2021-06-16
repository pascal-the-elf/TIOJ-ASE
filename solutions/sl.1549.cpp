#include <iostream>
#include <stack>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

stack<int> stk;

int n, x;

signed main(){
    ericxiao;
    cin >> n;
    int ans = 0, lst;
    while(n--){
        cin >> x;
        int popcnt = 0;
        if(!stk.size()){
            stk.push(x);
            continue;
        }
        if(stk.size() && stk.top() < x){
            ans += (stk.top() - x) * (stk.top() - x);
            //cout << "Too heavy, ans += " << (stk.top() - x) * (stk.top() - x) << endl;
            stk.push(x);
            continue;
        }
        while(stk.size() && stk.top() > x){
            lst = stk.top();
            stk.pop();
            popcnt++;
        }
        //cout << "POPS = " << popcnt << endl;
        if(popcnt){
            ans += (x - lst) * (x - lst);
            //cout << "Adding edge between " << x << " and " << lst << endl;
        }
        if(stk.size()){
            ans += (x - stk.top()) * (x - stk.top());
            //cout << "Adding edge between" << x << " and " << stk.top() << endl;
            if(popcnt){
                ans -= (lst - stk.top()) * (lst - stk.top());
                //cout << "Removing edge between " << lst << " and " << stk.top() << endl;
            }
        }
        stk.push(x);
    }
    cout << ans << '\n';
}
