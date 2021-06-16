#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 10;

deque<pii> dandiao;
int vals[maxN], pre[maxN], n;

signed main(){
    ericxiao;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> vals[i];
        pre[i] = vals[i] + pre[i - 1];
    }
    int ans = 0;
    pii p;
    for(int i = n; i; i--){
        //cout << "i = " << i << endl;
        //cout << "Pushing pre = " << pre[i] << ", i = " << i << endl;
        while(dandiao.size() && dandiao.front().F >= pre[i]) dandiao.pop_front();
        dandiao.push_front({pre[i], i});
        p = {pre[i - 1], -n};
        //cout << "pre[i - 1] = " << pre[i - 1] << endl;
        if(vals[i] >= 0){
            auto lb = lower_bound(dandiao.begin(), dandiao.end(), p, greater<pii>());
            if(lb != dandiao.end()){
                //cout << ", other i = " << lb->S << endl;
                ans += (n - lb->S + 1);
            }
        } else {
            //cout << "ans += " << n - i + 1 << endl;
            ans += n - i + 1;
        }

    }
    cout << ans << endl;
}
