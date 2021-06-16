#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, a, b, r, f, s, fM, sM;

signed main(){
    ericxiao;
    while(cin >> N){
        if(!N) return 0;
        if(N == 1){
            cin >> a >> b;
            cout << -(min(a, b) > 0) << '\n';
            continue;
        }
        r = f = s = 0, fM = sM = 1e10;
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            if(a > b) s++;
            else f++;
            fM = min(a - b, fM);
            sM = min(b - a, sM);
            r += min(a, b);
        }
        if(s == N){
            cout << r + fM << '\n';
        } else if(f == N){
            cout << r + sM << '\n';
        } else {
            cout << r << '\n';
        }
    }
}
