#include <iostream>
#define int long long int
using namespace std;

int cnt[50], T, N, K;

bool get(int N, int K){
    //cout << "Getting " << K << "th char of a_" << N << endl;
    if(N <= 2) return (N - 1);
    return (K > cnt[N - 2] ? get(N - 1, K - cnt[N - 2]) : get(N - 2, K));
}

inline void solve(){
    cin >> N >> K;
    if(N <= 47){
        if(cnt[N] < K){
            cout << -1 << endl;
            return;
        }
    }
    cout << get(min(N, (int)47), K) << endl;
}

signed main(){
    cnt[1] = cnt[2] = 1;
    for(int i = 3; i <= 50; i++){
        cnt[i] = cnt[i - 1] + cnt[i - 2];
        //cout << i << " : " << cnt[i] << endl;
        if(cnt[i] > 3e9) break;
    }
    cin >> T;
    while(T--){
        solve();
    }
}
