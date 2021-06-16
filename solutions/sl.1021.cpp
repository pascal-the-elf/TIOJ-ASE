#include <iostream>
#define int long long int
using namespace std;

int n, k;

signed main(){
    while(cin >> n >> k){
        int ans = 0, t = 1, orin = n;
        while(n){
            ans += max((n / 10) - (k == 0), 0LL ) * t; //is smaller before
            if(n < 10 && !k) break; //is most important bit
            if(n % 10 == k){ //is same
                ans += orin % t + 1;
            } else if(n % 10 > k){ //is bigger
                ans += t;
            }
            n /= 10;
            t *= 10;
        }
        cout << ans << endl;
    }
}
