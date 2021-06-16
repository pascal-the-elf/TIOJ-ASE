#include <iostream>
#define int long long int
using namespace std;

int N, ans, l;

signed main(){
    cin >> N;
    for(int d = 2; d <= N; d++){
        ans += (d - 1 - l) * (N / (d - 1) - 1);
        l = d - 1;
        d = (N / (N / d));
    }
    //ans += (N - l - 1);
    cout << ans << endl;
}
