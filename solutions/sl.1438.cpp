#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, M, k, a;

inline int choose(int x){
    return x * (x - 1) / 2 * (x - 2) / 3;
}

signed main(){
    ericxiao;
    while(cin >> N){
        if(!N) return 0;
        a = choose(N);
        cin >> M;
        while(M--){
            cin >> k;
            a -= choose(k);
        }
        if(a <= 0) cout << "IMPOSSIBLE\n";
        else cout << a << '\n';
    }
}
