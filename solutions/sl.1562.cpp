#include <iostream>
using namespace std;

const int maxN = 226;

int N, K, arr[maxN];

inline bool chk(int t){
    int cnt = 1, cs = 0;
    for(int i = 0; i < N; i++){
        if(cs + arr[i] > t){
            cnt++;
            cs = 0;
        }
        cs += arr[i];
    }
    //cout << "For t = " << t << ", cnt = " << cnt << endl;
    return cnt <= K;
}

inline void solve(){
    int l = 0, r = 100000, m;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        l = max(l, arr[i]);
    }
    l--;
    while(l + 1 < r){
        m = (l + r) / 2;
        if(chk(m)){
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
}

int main(){
    while(cin >> N >> K){
        solve();
    }
}
