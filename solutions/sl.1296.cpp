#include <iostream>
#define int long long int
using namespace std;

int ans[21], t;

signed main(){
    ans[1] = 1;
    for(int i = 2; i <= 20; i++) ans[i] = (4 * i - 2) * ans[i - 1] / (i + 1);
    while(cin >> t) cout << ans[t] << endl;
}
