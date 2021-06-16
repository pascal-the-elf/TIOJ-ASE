#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxH = 1e5 + 10, maxN = 1e3 + 19;

bool can[maxH];
int T, N, H, vals[maxN][3];

inline void solve(){
    cin >> N >> H;
    for(int i = 0; i <= H; i++) can[i] = false;
    int s = 0;
    for(int k = 0; k < N; k++){
        for(int i = 0; i < 3; i++) cin >> vals[k][i];
        sort(vals[k], vals[k] + 3);
        s += vals[k][0];
        vals[k][1] -= vals[k][0];
        vals[k][2] -= vals[k][0];
    }
    H -= s;
    if(H < 0){
        cout << "no solution" << endl;
        return;
    }
    can[0] = true;
    for(int i = 0; i < N; i++){
        for(int j = H; j >= 0; j--){
            if(can[j]){
                if((j + vals[i][1]) <= H) can[j + vals[i][1]] = true;
                if((j + vals[i][2]) <= H) can[j + vals[i][2]] = true;
            }
        }
    }
    for(int i = H; i >= 0; i--){
        if(can[i]){
            cout << i + s << endl;
            return;
        }
    }
}

int main(){
    ericxiao;
    cin >> T;
    while(T--){
        solve();
    }
}
