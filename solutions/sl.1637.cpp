#include <iostream>
#include <stack>
#include <utility>
#define ericxiao ios_base::sync_with_stdio(0);
#define int long long int
using namespace std;

const int maxN = 1e6 + 226;

struct Obj{
    int l, r, val;
    Obj(){}
    Obj(int l, int r, int val): l(l), r(r), val(val){}
    bool operator<(const Obj &o){
        return val <= o.val;
    }
} ob;

stack<Obj> stk;

int N, x, currentSum, ans;

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 1; i < N; i++){
        cin >> x;
        ob = Obj(i - 1, i, x);
        currentSum += x;
        while(stk.size() && stk.top() < ob){
            currentSum += (stk.top().r - stk.top().l) * (x - stk.top().val);
            ob.l = stk.top().l;
            stk.pop();
        }
        ans += currentSum;
        stk.push(ob);
    }
    cout << ans << '\n';
}
