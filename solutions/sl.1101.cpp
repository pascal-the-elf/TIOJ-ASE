#include <iostream>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

pii operator + (pii a, pii b){
    return {a.F + b.F, a.S + b.S};
}

int n, m, l, r;

signed main(){
    while(cin >> n >> m){
        if(!n && !m) return 0;
        if(n == 1){
            if(m == 1) cout << "0/1" << endl;
            else cout << "1/0" << endl;
            continue;
        }
        n -= 2;
        m--;
        int l = 0, r = (1 << n), mid;
        pii L = {0, 1}, R = {1, 0}, M;
        while(l + 1 < r){
            mid = (l + r) / 2;
            M = L + R;
            //cout << "l = " << l << ", r = " << r << endl;
            if(m < mid){
                R = M;
                r = mid;
            } else {
                L = M;
                l = mid;
            }
            //cout << "L: " << L.F << "/" << L.S << endl;
            //cout << "R: " << R.F << "/" << R.S << endl;
        }
        M = L + R;
        cout << M.F << "/" << M.S << endl;
    }
}
