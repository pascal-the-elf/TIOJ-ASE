#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int LIM = (1LL << 32);

vector<int> fib1, fib2;
int N, x, c, limind, lg[(1<<24)];
map<int, int> res;
signed main(){
    ericxiao;
    int cur = 1, las = 1, _t;
    for(int i = 0; i < 24; i++){
        lg[(1<<i)] = i;
    }
    for(int i = 0; i < 20; i++){
        (i < 10 ? fib1 : fib2).push_back(cur);
        _t = cur + las;
        las = cur;
        cur = _t;
    }
    cout << "fib1size = " << fib1.size() << endl;
    int sm = 0;
    for(int x : fib1){
        cout << x << " ";
        sm += x;
    }
    cout << ", sum = " << sm << endl;
    cout << endl;
    for(int i = 1; i < (1<<fib1.size()); i++){
        int sum = 0, _i = i, cnt = 0;
        //cout << "i = " << i << endl;
        while(_i){
            //cout << "_i = " << _i << endl;
            sum += fib1[lg[(_i & -_i)]];
            _i -= (_i & -_i);
            cnt++;
        }
        if(!res.count(sum)) res[sum] = cnt;
        else res[sum] = min(cnt, res[sum]);
    }
    for(auto p : res){
        cout << p.first << " " << p.second << endl;
    }
}
