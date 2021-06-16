#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 5e5 + 10;
int N, r[maxN], b[maxN];

signed main(){
    while(cin >> N){
        for(int i = 0; i < N; i++) cin >> r[i];
        for(int i = 0; i < N; i++) cin >> b[i];
        sort(r, r + N);
        sort(b, b + N);
        int ans = 0;
        for(int i = 0; i < N; i++) ans += r[i] * b[i];
        cout << ans << endl;
    }
}
