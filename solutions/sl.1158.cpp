#include <iostream>
#define int long long int
using namespace std;

int n, q;


/*
With the ith addition, every ray will cross all 2 * (i - 1) prev lines, creating 2 * (i - 1) new spaces.
It will also create a new space with the two rays by itself, so another one is added. Thus the sum
1 + sum ( 4 * (i - 1)  + 1 )
*/

signed main(){
    cin >> q;
    while(q--){
        cin >> n;
        int ans = 1 + n + 2 * n * (n - 1);
        cout << ans << endl;
    }
}
