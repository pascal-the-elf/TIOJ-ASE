#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;

int t, n, ans = 0;
vector<int> vals, bigger;
struct BIT{
    int bit[maxN + 10];
    BIT(){ fill(bit, bit + maxN, 0); }
    void add(int p, int x){
        for(; p < maxN; p += (p & -p)) bit[p] += x;
    }
    int que(int p){
        int res = 0;
        for(; p > 0; p -= (p & -p)) res += bit[p];
        return res;
    }
    void reset(){
        fill(bit, bit + maxN, 0);
    }
} bit;

signed main(){
    ericxiao;
    cin >> t;
    while(t--){
        bit = BIT();
        cin >> n;
        ans = 0;
        vals.resize(n);
        bigger.resize(n);
        //cout << "Proper: " << endl;
        for(int i = 0; i < n; i++){
            cin >> vals[i];
            bigger[i] = bit.que(vals[i]);
            bit.add(vals[i], 1);
            //cout << "Bigger[" << i << "] = " << bigger[i] << endl;
        }
        bit.reset();
        for(int i = 0; i < n; i++){
            ans += bit.que(vals[i]);
            //cout << "Ans += " << bit.que(vals[i]) << endl;
            bit.add(vals[i], bigger[i]);
        }
        //cout << "Rev: " << endl;
        reverse(vals.begin(), vals.end());
        bit.reset();
        for(int i = 0; i < n; i++){
            bigger[i] = bit.que(vals[i]);
            bit.add(vals[i], 1);
        }
        bit.reset();
        for(int i = 0; i < n; i++){
            ans += bit.que(vals[i]);
            bit.add(vals[i], bigger[i]);
        }
        cout << ans << endl;
    }
}
